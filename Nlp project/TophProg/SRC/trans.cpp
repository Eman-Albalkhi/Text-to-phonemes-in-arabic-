
// Program Name: trans

//#include "var_trans.h"
#include "trans.h"
#include "trace.h"
#include "imprim.h"
#include "cherch.h"
#include "gerbou.h"
#include "stdlib.h"
#include "malloc.h"
#include "iostream.h"


void LIRE_BLANC(ifstream &texte)
{
   while (!texte.eof() && (car == ' ' || car == '\t'|| car == '\n'))
      texte>>car;
}


void lire_espace(ifstream &texte)
{
  bool k;
         k=true;
  while (!texte.eof()&&(k))
  {
          texte.get(car);
	  if ((car == ' ')||(car == (char)(9)))
            k=true;
          else
          {
           texte.unget();k=false;
          }
          
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

void chercher_regle(ofstream &ftexte)
{
	char c;
    bool fin_classe_regles;

    incrt = 0;
    categ = false;
    c = bout[ind_bout];
    if (c=='{')
       categ=true;
    else
    {
        indice_cour = tab_dep[to_int(majmin(c))];
        regle_cour = tab_regle[indice_cour];
        regle_valide = false;
        //fin_classe_regles=true;
        fin_classe_regles = (regle_cour.sentinelle == 0);
        trouve = false;
        if (!fin_classe_regles)
		while (!((regle_valide)||(fin_classe_regles)))
		{
		    if (regle_cour.inclue)
		       	comparer_regle(ftexte);
		    regle_valide = trouve;
		    fin_classe_regles = (tab_regle[indice_cour+1].sentinelle == 0);
                    if (!regle_valide)
		    {
			indice_cour++;
			regle_cour = tab_regle[indice_cour];
		    }
		}
    }
}

// ifstream for read file
void methode2_ecrire_phon(ofstream &f)
{
	int i, nb;
	bool parth;
	int FORLIM;

    parth = false;
    nb = 0;
    i = 1;
    // with regle_cour do
	if (!regle_cour.poly_ph) 
	{
		FORLIM = regle_cour.l_ph;
        for (i = 1; i <= FORLIM; i++)
        	f<<regle_cour.pho[i];
	}
	else
		while (i <= regle_cour.l_ph) 
		{
			if ((!parth)&&(nb != 0)) 
			{
				parth = true;
				f<<'(';
			}
			if (regle_cour.pho[i] == '|') 
			{
				i++;
				nb++;
				}  // if
			else 
			{
				while ((regle_cour.pho[i] != '|')&&(i <= regle_cour.l_ph)) 
				{
					f<<regle_cour.pho[i];
					i++;
					nb++;
				}  // while
				if ((regle_cour.pho[i] == '|')&&(i < regle_cour.l_ph))
					i++;
			}
			if ((i <= regle_cour.l_ph)&& (parth))
				f<<"-";
            if ((i > regle_cour.l_ph)&&(parth))
				f<<')';
		}  /*while*/

}  /*ecrire_phon*/


void ecrire_phon(ofstream &f)
{
	int i, FORLIM;

    i = 1;
    //  with regle_cour do
	if (!regle_cour.poly_ph) 
	{
		FORLIM = regle_cour.l_ph;
        for (i = 1; i <= FORLIM; i++)
			f<<regle_cour.pho[i];
	}
	else
		while (i <= regle_cour.l_ph) 
		{
			if ((regle_cour.pho[i] == '|')&&((i == 1)||(i == regle_cour.l_ph))) 
			{
				f<<"[]";
                i++;
			}  //  if
			else
			{
				f<<'[';
                while ((regle_cour.pho[i] != '|')&&(i <= regle_cour.l_ph))
				{
					f<<regle_cour.pho[i];
                    i++;
				}  //  while
				f<<']';
                if ((regle_cour.pho[i] == '|')&&(i != regle_cour.l_ph))
					i++;
			} //  else
  
		}  //  while
               // f<<endl;

  //  end with
}  /*ecrire_phon*/




void transcrire_ct(ofstream &ftrace,ofstream &txttrans,ofstream &fslach)
{
	int i, FORLIM;


	if (regle_cour.ch_d[1] == (char)(0))    //(char)(32))
	{
		txttrans<<regle_cour.ch_d[1];
        if (trace)
			ftrace<<regle_cour.ch_d[1];
	}
	else
	{
		ecrire_phon(txttrans);
        if (trace)
                    {
		       	ecrire_phon(ftrace);
                        if  (regle_cour.ch_d[1]==' ') ftrace<<endl;
                        }
        if (toph_mot)
		{
			FORLIM = regle_cour.l_ph;
            for (i = 1; i <= FORLIM; i++)
		    mot_trans[i + j] = regle_cour.pho[i];
			j += regle_cour.l_ph;
		}
		if (graphon)
		{
			FORLIM = regle_cour.l_ct;
            for (i = 1; i <= FORLIM; i++)
				fslach<<regle_cour.ch_d[i];
            fslach<<'/';
		}
		if (statistique)
			stat[regle_cour.num]++;
	} // else
}

bool lire_ens_cat(ifstream &texte,ofstream &fres)
{

       char car1;
       bool found;
	int k,nb_cat_mot,i,j;
       //  char f_b,b_fb,WLIM1,WLIM2;
        nb_cat_mot=0;
        init_ens_cat();
	found=false;
	texte>>car;
	lire_espace(texte);
	// with bout_cat[fin_bout] do
        //nb_cat_mot=0;
	//****************bout_cat[fin_bout].nb_categ=0;
     /*	for (i=0;i< nb_max_cat;i++)
	{
	    for (j=0;j< max_lg_cat;j++)
		 bout_cat[fin_bout].ens_cat[i].catg[j]=' ';
	    bout_cat[fin_bout].ens_cat[i].lg_cat=0;
	}  */
        texte>>car1;
        texte.unget();
        while ((!texte.eof())&&(car1 != '{'))
     	{
		nb_cat_mot++;
		k=0;
		while ((!texte.eof())&&(car1 != ',')&&(car1 != '{')&&(car1 != ' '))
		{
			texte>>car;
			k++;
                        ens_cat_mot[nb_cat_mot].catg[k]=car;
			//bout_cat[fin_bout].ens_cat[nb_cat_mot].catg[k]=car;
		}
                ens_cat_mot[nb_cat_mot].lg_cat=k;
		//bout_cat[fin_bout].ens_cat[nb_cat_mot].lg_cat=k;
                texte>>car1;
                texte.unget();
		if ((!texte.eof())&&(car1 == ' '))
			lire_espace(texte);
                texte>>car1;
                texte.unget();
		if ((!texte.eof())&&(car1 == ','))
		{
			texte>>car;
			found=true;
			lire_espace(texte);
		}
		else
			if ((!texte.eof())&&(car1 == '{'))
				found=true;
			else
			{
				fres<<"!! erreur : lire_ens_cat !!\n";
				fres<<"le fichier de texte (cat) se termine brusquement\n";
				fin_anormale=true;
				exit(0);
			} // else
	} // while
        texte>>car1;
        texte.unget();
	if ((!texte.eof())&&(car1 == '{'))
        {
		texte>>car;
                while ((! texte.eof())&&(car != '\n'))
                      if (car==' ')
                         texte>>car;
                      else
                          break;
        }
	else
	{
		fres<<"!!erreur : lire_ens_cat !!\n";
		fres<<"le fichier de texte (cat) se termine brusquement\n";
		fin_anormale=true;
		exit(0);
	}
	/*bout_cat[fin_bout].nb_categ=nb_cat_mot;
	f_b=fin_bout;
	decr_fin_bout();
        b_fb=bout[fin_bout];
	WLIM1=((b_fb != ' ')||(b_fb != ',')||(b_fb != '!')||(b_fb != '.')||(b_fb != '?')||(b_fb != ':')||(b_fb != ';'));
	WLIM2=((b_fb != (char)(0))||(b_fb != (char)(39))||(b_fb != (char)(211))||(b_fb != (char)(34))||(b_fb != (char)(213)));
	while ((bout_cat[fin_bout].nb_categ=0)&&(!((WLIM1)||(WLIM2))))
	{
		bout_cat[fin_bout]=bout_cat[f_b];
		decr_fin_bout();
	}
	if ((WLIM1)||(WLIM2))
		bout_cat[fin_bout].nb_categ=0;
	fin_bout=f_b;
	if ((WLIM1)||(WLIM2))
		bout_cat[fin_bout].nb_categ=0; */

     	return found;
}

void lire_mot(type_bout mot,ifstream &texte)
{
     int i;
     bool kk=true;
     char car1;
     ind_bout=3;
     deb_bout=1;
     fin_bout=2;
     while (!((texte.eof())||(fin_bout == long_bout)))
     {
         texte>>car1;
         //texte.unget();
         if ((car1=='\n')&&(!(texte.eof()))&&(kk))
         {
            //readln(texte);
            fin_bout=fin_bout+1;
            cr_lf[fin_bout]=true;
            fin_bout++;
            fin_mot[fin_bout]=true;
            kk= false;
         }
         else if ((car1==' ')&&(kk))
         {
              texte>>car1;
              fin_bout +=2;
              fin_mot[fin_bout]=true;
              kk=false;
         }
         else if (kk)
         {
             fin_bout++;
             texte>>car1;
             bout[fin_bout]=car;
             kk=false;
         }
     }
     if ((texte.eof())&&(kk))
     {
         fin_bout++;
         fin_mot[fin_bout]=true;
     }
     if (!(texte.eof()))
        while ((!(texte.eof()))&& (car1 != '\n') &&(car1 ==' '))
              texte>>car1;
        for (i=fin_bout;i<=long_bout;i++)
            fin_mot[i]=true;
        mot = bout;

}

void incr_fin_bout()
{
  
	if ((fin_bout+1)<=long_bout)
            fin_bout=fin_bout+1;
	else
		fin_bout = (fin_bout+1) - long_bout;
}


void decr_fin_bout()
{
	if ((fin_bout-1) >= 1)
		fin_bout--;
	else
		fin_bout = (fin_bout - 1)+long_bout;
}

/*bool lire_ens_cat1(ifstream &texte,ofstream &fres)
{

	char b_fb,car1;
	bool found,WLIM1,WLIM2;
	int k,nb_cat_mot,f_b,i,j;

	f_b=0;
	found=false;
	texte>>car;
	lire_espace(texte);
	// with bout_cat[fin_bout] do
        nb_cat_mot=0;
	bout_cat[fin_bout].nb_categ=0;
	for (i=1;i<=nb_max_cat;i++)
	{
		for (j=1;j<=max_lg_cat;j++)
			bout_cat[fin_bout].ens_cat[i].catg[j]=' ';
		bout_cat[fin_bout].ens_cat[i].lg_cat=0;
	}
        texte>>car1;
        texte.unget();
        while ((!texte.eof())&&(car1 != '}'))
     	{
		nb_cat_mot++;
		k=0;
		while ((!texte.eof())&&(car1 != ',')&&(car1 != '}')&&(car1 != ' '))
		{
			texte>>car;
			k++;
			bout_cat[fin_bout].ens_cat[nb_cat_mot].catg[k]=car;
		}
		bout_cat[fin_bout].ens_cat[nb_cat_mot].lg_cat=k;
                texte>>car1;
                texte.unget();
		if ((!texte.eof())&&(car1 = ' '))
			lire_espace(texte);
                texte>>car1;
                texte.unget();
		if ((!texte.eof())&&(car1 = ','))
		{
			texte>>car;
			found=true;
			lire_espace(texte);
		}
		else
			if ((!texte.eof())&&(car1 = '}'))
				found=true;
			else
			{
				fres<<"!! erreur : lire_ens_cat !!\n";
				fres<<"le fichier de texte (cat) se termine brusquement\n";
				fin_anormale=true;
				exit(0);
			} // else
	} // while
        texte>>car1;
        texte.unget();
	if ((!texte.eof())&&(car1 = '}'))
		texte>>car;
	else
	{
		fres<<"!!erreur : lire_ens_cat !!\n";
		fres<<"le fichier de texte (cat) se termine brusquement\n";
		fin_anormale=true;
		exit(0);
	}
	bout_cat[fin_bout].nb_categ=nb_cat_mot;
	f_b=fin_bout;
	decr_fin_bout();
        b_fb=bout[fin_bout];
	WLIM1=((b_fb != ' ')||(b_fb != ',')||(b_fb != '!')||(b_fb != '.')||(b_fb != '?')||(b_fb != ':')||(b_fb != ';'));
	WLIM2=((b_fb != (char)(0))||(b_fb != (char)(39))||(b_fb != (char)(211))||(b_fb != (char)(34))||(b_fb != (char)(213)));
	while ((bout_cat[fin_bout].nb_categ=0)&&(!((WLIM1)||(WLIM2))))
	{
		bout_cat[fin_bout]=bout_cat[f_b];
		decr_fin_bout();
	}
	if ((WLIM1)||(WLIM2))
		bout_cat[fin_bout].nb_categ=0;
	fin_bout=f_b;
	if ((WLIM1)||(WLIM2))
		bout_cat[fin_bout].nb_categ=0;

     	return found;
}   */


void traiter_fin(ifstream &texte)
{
	if (texte.eof())
	{
		incr_fin_bout();
		bout[fin_bout]=' ';
		//bout_cat[fin_bout].nb_categ=0;
		cr_lf[fin_bout]=false;
		incr_fin_bout();
		bout[fin_bout]=' ';
		//bout_cat[fin_bout].nb_categ=0;
		cr_lf[fin_bout]=false;
		decr_fin_bout();
	}
}


void init_bout(ifstream &texte)
{



        deb_bout=1;
	ind_bout=1;
        bout[0]=' ';
	bout[ind_bout]=' ';
	fin_bout=1;
	cr_lf[fin_bout]=false;
	if (pre_mot)
	{
		fin_bout=2;
		bout[fin_bout]=' ';
		ind_bout=3;
		cr_lf[fin_bout]=false;
	}
	while (!(texte.eof())&&(fin_bout!=long_bout))
	{

                texte>>car;
		if (!(texte.eof())&&(car != '\n'))
		{
                  incr_fin_bout();
                  bout[fin_bout]=car;
                 // traiter_fin(texte);
		}
		else  if (!(texte.eof())&&(car== '\n'))
		{
			incr_fin_bout();
			bout[fin_bout]=' ';
			cr_lf[fin_bout]=true;
                 //       traiter_fin(texte);
		}
	}
	if (texte.eof())
	{
		incr_fin_bout();
		bout[fin_bout]=' ';
                incr_fin_bout();
		bout[fin_bout]=' ';
	       //	decr_fin_bout();
	}


}


void lister_non_trans()
{
	list_non_trans *pt;
	if (tete_non_trans==NULL)
	{
		maillon1_non_trans=new list_non_trans;
		tete_non_trans=maillon1_non_trans;
		// with maillon1_non_trans* do
		maillon1_non_trans->car=bout[ind_bout];
		maillon1_non_trans->suivant=NULL;
	}
	else
	{
		pt=tete_non_trans;
		while (!((pt->suivant==NULL)||(pt->car==bout[ind_bout])))
			pt=pt->suivant;
		if (pt->car != bout[ind_bout])
		{
			maillon2_non_trans=maillon1_non_trans;
                        maillon1_non_trans=new list_non_trans;
			maillon2_non_trans->suivant=maillon1_non_trans;
			// with	maillon1_non_trans* do
			maillon1_non_trans->car=bout[ind_bout];
			maillon1_non_trans->suivant=NULL;
		} // if
	} // else

}


void ecrire_fichiers(int meth,ofstream &fres,ofstream &ftrace,ofstream &txttrans,ofstream &fslach)
{
	if (meth==1)
	{
		if (!(teste_redondance))
			txttrans<<'\n';
		if (graphon)
			fslach<<'\n';
		if (trace)
			ftrace<<'\n';
	}
	else
		if (meth==2)
		{
			txttrans<<bout[ind_bout]<<endl;
			if (trace)
				ftrace<<bout[ind_bout];
			if (graphon)
				fslach<<bout[ind_bout];
		}
		else
			if (meth==3)
			{
				txttrans<<"'"<<bout[ind_bout]<<"'"<<endl;
				if (trace)
					ftrace<<"'"<<bout[ind_bout]<<"'";
				if (graphon)
					fslach<<"'"<<bout[ind_bout]<<"'";
			}
			else
			{
				fres<<"!! erreur : ecrire_fichier !!"<<endl;
				fres<<"L'indice donne pour la fonction ecrire_fichier n'a pas de sens"<<endl;
				fin_anormale=true;
                                exit(0);
                                //exit(EXIT_FAILURE);
				//????halt;
			}

}


void deplacer_tete_et_reecrire(ofstream &ftrace,ofstream &fres,ofstream &fslach,ofstream &txttrans,ofstream &ftexte)
{
	bool FLIM1,FLIM2;
	char b_ib;
        int ind;
	chercher_regle(ftexte);
        if (categ)
        {
           incrt=0;
           ind=ind_bout;
           while ((bout[ind] != '}')&&(!fin_du_texte))
           {
                 incrt++;
                 ind=plus1(ind,1,fin_du_texte);
           }
           incrt++;
           ind = plus1(ind,1,fin_du_texte);
           increment = incrt;
        }
        else  if (regle_valide)
	{
                transcrire_ct(ftrace,txttrans,fslach);
		increment=regle_cour.l_ct;
		if (trace)
		{
			if (regle_cour.ch_d[1]==marque_trace)
			{
				trace_imprimer(ftrace);
				disposer_trace(tete_trace);
			}
			construire_trace();
		}
	}
	else
	{
		if (cr_lf[ind_bout])
			{
				ecrire_fichiers(1,fres,ftrace,txttrans,fslach);
				cr_lf[ind_bout]=false;
			}
                else
                        //if (!(teste_redondance))
			  //	{
					b_ib=bout[ind_bout];
					FLIM1=((b_ib == ' ')||(b_ib == ',')||(b_ib == '!')||(b_ib == '.')||(b_ib == '?')||(b_ib == ':')||(b_ib == ';'));
					FLIM2=((b_ib == (char)(0))||(b_ib == (char)(39))||(b_ib == (char)(211))||(b_ib == (char)(34))||(b_ib == (char)(213)));
					if (!(trace_non_trans)||((FLIM1)||(FLIM2)))
						ecrire_fichiers(2,fres,ftrace,txttrans,fslach);
					else
						ecrire_fichiers(3,fres,ftrace,txttrans,fslach);
					if (!(FLIM1||FLIM2))
					{
						lister_non_trans();
						nb_non_transcrit++;
					}
			      //	}
				if (trace)
					if (bout[ind_bout]==marque_trace)
					{
						trace_imprimer(ftrace);
						disposer_trace(tete_trace);
					}
					increment=1;
	}
	ind_bout=plus1(ind_bout,increment,fin_texte);
	if (!(regle_valide)&&(teste_redondance)&&(red_globale))
		fin_mot[ind_bout]=true;
}

/*void transcrire_mot(type_bout &mot,type_bout &mot_trans)
{
   int p;
   j=0;
   for (p=1;p<=long_bout;p++)
   {
      bout[p]=' ';
      cr_lf[p]=false;
      fin_mot[p]=false;
      mot[p]=' ';
      mot_trans[p]=' ';
   }
   cat_found=false;
   lire_mot(mot);
   texte.get(car);
   if (!(texte.eof()))
     if (car=='}')
        cat_found= lire_ens_cat();
   while (!(fin_mot[ind_bout]))
      	deplacer_tete_et_reecrire(ftrace,fres,fslach,txttrans,ftexte);


}

void transcrire2_texte()
{
  while (!(texte.eof()))
     transcrire_mot(mot,mot_trans);

} */

void transcrire1_texte(ifstream &texte,ofstream &ftrace,ofstream &fres,ofstream &fslach,ofstream &txttrans,ofstream &ftexte)
{
	int p;
        char car1,car2;
	for (p=1;p<=long_bout;p++)
	{
		cr_lf[p]=false;
		bout[p]=' ';
		//bout_cat[p].nb_categ=0;
	}
	pre_mot=true;
	init_bout(texte);
	fin_texte=(deb_bout >= fin_bout);
	while (!(ind_bout > (long_bout/2)||(fin_texte)))
		deplacer_tete_et_reecrire(ftrace,fres,fslach,txttrans,ftexte);
	while (!fin_texte)
	{
		deplacer_tete_et_reecrire(ftrace,fres,fslach,txttrans,ftexte);
		deb_bout=plus1(deb_bout,increment,bid);
		i=0;
		while (!((i==increment)||(texte.eof())))
		{
                        texte>>car2;
			if (car2=='\n')
			{
				incr_fin_bout();
				bout[fin_bout]=' ';
				i++;
				cr_lf[fin_bout]=true;
				traiter_fin(texte);
			}
                        else if (!texte.eof())
                        {
                                i++;
                                 incr_fin_bout();
                                bout[fin_bout]=car2;
                                 traiter_fin(texte);
                        }
                        else
                        {
                                incr_fin_bout();
                                bout[fin_bout]=' ';
                                cr_lf[fin_bout]=false;
                        }
		} //while (!(i==increment)||(texte.eof()))
	} // while (!fin_texte)
}


void traiter_texte(ifstream &texte,ofstream &ftrace,ofstream &txttrans,ofstream &fslach,ofstream &fres,ofstream &ftexte)
{
	if (trace)
		tete_trace=NULL;
	tete_non_trans=NULL;
	nb_non_transcrit=0;
	transcrire1_texte(texte,ftrace,fres,fslach,txttrans,ftexte);
	if ((trace)&&(tete_trace != NULL))
	{
		trace_imprimer(ftrace);
		disposer_trace(tete_trace);
	}
	if (nb_non_transcrit != 0)
	{
		txttrans<<'\n';
		if (graphon)
			fslach<<'\n';
		if (trace)
		{
			ftrace<<'\n';
			ftrace<<"nombre d'occurrences non transcrite(s) : "<<nb_non_transcrit;
			non_trans_imprimer(ftrace);
		}
	}
}








