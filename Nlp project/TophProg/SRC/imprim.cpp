//Program Name: imprim


#include "imprim.h"



void extr_ident(int n,nom_ident &id,int &l)
{

  int i;

  l = 0;
  i = tadid[n].adr - 1;
  while (l < tadid[n].lg)
  {
    l++;
    id[l] = tid[i+l];
  }
}

int to_int(char c)
{
	int i=c;
	 if(i<0)
	 {
		 i=c&(128-1);
		 i=i+128;
	 }
	 return i;
}

void decode(int &n, char &c1,char &c2)
{
  n=10* (to_int(c1))+(to_int(c2))-11*(to_int(0));
}

void ecrire_contexte(ofstream &f, bool droite, int i1,int i2)
{
  int i, j;
  char cari, cari1, cari2;

  // with regle_cour do
  f<<'(';
  i = i1;
  while (i <= i2) 
  {
	  if (droite == 1)  //(sens== droite)
		  cari = regle_cour.ch_d[i];
      else
          cari = regle_cour.cxt_g[i];
      if (cari == '"')
	  {
		  if (droite == 1) //sens == droite
		  {
		     cari1 = regle_cour.ch_d[i+1];
                     cari2 = regle_cour.ch_d[i+2];
		  }
                  else
		  {
		     cari1 = regle_cour.cxt_g[i+1];
    	             cari2 = regle_cour.cxt_g[i+2];
		  }
		  decode(numidcour, cari1, cari2);
                  extr_ident(numidcour, idcour, lgidcour);
                  f<<"\"";
           for (j = 1; j <= lgidcour; j++)
		  f<<idcour[j];
       f<<"\"";
      i += 4;
	  }
	  else
	  {
		  if (cari == '/')
		  {
			  if (droite == 1) // sens=droite
     		      cari1 = regle_cour.ch_d[i+1];
			  else
				  cari1 = regle_cour.cxt_g[i+1];
              f << cari<< cari1;
			  i+=3;
		  }
		  else
		  {
			   f<<cari;
			  i++;
		  }
	  }
  }
   f<<')';

}


void ecrire_ct(ofstream &f)
{
	int i;
	//with regle_cour do
	f<<'+';
    for (i = 1; i <= regle_cour.l_ct;i++)
		 f<<regle_cour.ch_d[i];
   	f<<'+';
}


void ecrire_pho(ofstream &f)
{
  int i;
  // with regle_cour do
   f<<'[';
  for (i = 1; i <= regle_cour.l_ph; i++)
	   f<<regle_cour.pho[i];
   f<<']';
}

void ecrire_cat(ofstream &f)
{
  int i, j ;
  //with regle_cour do
  f<<'}';
  for (i = 1; i <= regle_cour.nb_cat_reg; i++)
  {
    for (j = 1; j <= regle_cour.ens_cat_reg[i].lg_cat; j++)
		 f<<regle_cour.ens_cat_reg[i].catg[j];
    if (i != regle_cour.nb_cat_reg)
      	 f<<'�';
  }
   f<<'{';
}



void imprimer_regle(ofstream &f)
{
    //with regle_cour do
	if (regle_cour.l_g > 0)
		ecrire_contexte(f, 0 ,1,regle_cour.l_g);/*gauche*/
    ecrire_ct(f);
    if (regle_cour.l_ct < regle_cour.l_d)
		ecrire_contexte(f, 1,regle_cour.l_ct+1,regle_cour.l_d);/*droite*/
    if (regle_cour.nb_cat_reg != 0)
		ecrire_cat(f);
    f<<'=';
    ecrire_pho(f);
	f<<'\n';
}



void trace_imprimer(ofstream &f)
{
    list_trace  *p;
    f<<'\n';
    p = tete_trace;
    while (p != NULL) 
	{
		indice_cour = p->indice_regle;
        regle_cour = tab_regle[indice_cour];
        imprimer_regle(f);
        indice_cour++;
        regle_cour = tab_regle[indice_cour];
        p = p->suivant;
        if (regle_cour.ch_d[1]==' ') f<<endl;
	}
	f<<'\n';
}


void non_trans_imprimer(ofstream &f)
{
    list_non_trans  *p;
    int i;   /* pour ne pas avoir des lignes > 60*/
    i = 1;
    f<<"Liste de(s) caractere(s) non transcrit(s) :\n";
    p = tete_non_trans;
    while (p != NULL) 
	{
		if (i == 71)
			i = 1;
        if (i <= 60)
		f<< p->car <<"/ ";
        else
            f<<p->car <<'\n';
        i++;
        p = p->suivant;
	}
	f<<'\n';
}


void stat_imprimer(ofstream &f)
{
    int n;
    int s, somme, i;
    somme = 0;
    for (i = prim_car_ascii; i <= last_car_ascii; i++)
	{
		indice_cour = tab_dep[i];
        regle_cour = tab_regle[indice_cour];
        while (regle_cour.sentinelle != 0)
		{
			somme = somme+stat[regle_cour.num];
            indice_cour++;
            regle_cour = tab_regle[indice_cour];
		}
	}	
    f<<"! statistiques par classes sur l'utilisation des regles !\n\n";
    if (somme == 0) 
	f<<" Aucune regle n'a ete appliquee !!!\n";
    else
      for (i=prim_car_ascii;i<=last_car_ascii;i++)
      {
	    indice_cour = tab_dep[i];
            regle_cour = tab_regle[indice_cour];
            if (regle_cour.sentinelle != 0) 
	    {
                f<<"! classe du '"<<((char)(i))<<" '!\n\n";
                s = 0;
                do
		{
		    n = regle_cour.num;
	            f<<'!'<<n<<'!';
	            imprimer_regle(f);
	            s += stat[n];
	            indice_cour++;
	            regle_cour = tab_regle[indice_cour];
		}
		while (regle_cour.sentinelle != 0);
                f<<'\n';
                if (s == 0)
		    f<<"  Aucune regle de la classe :"<<(char)(i)<<" n'a ete appliquee.\n";
		else
		{
		   f<<"!numero		nombre		%% dans    %%sur !\n";
		   f<<"! de regle       d`utilis.    la classe     le total !\n\n";
	           indice_cour = tab_dep[i];
	           regle_cour = tab_regle[indice_cour];
	           while (regle_cour.sentinelle != 0)  /*regle <> Nil Do*/
		   {
		       n = regle_cour.num;
	               f<<'!'<<n<<stat[n]<<'\t'<<(stat[n]/s)*100<<'\t'<<(stat[n]/somme)*100<<"  !";
	               indice_cour++;
                       regle_cour = tab_regle[indice_cour];
		   }
                }
                f<<'\n';
	    }
      }	/* for */
}



/* End. */
