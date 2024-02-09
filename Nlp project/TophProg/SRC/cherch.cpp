// Program Name: cherch

#include "extrai.h"
#include "imprim.h"
#include "gerbou.h"


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


char majmin(char c)
{
  int code_c;

  if (bool_majmin)
    return c;
  else 
  {
	  code_c =to_int(c);
      if ((code_a_max <= code_c) && (code_c <= code_z_max))
		  return ((char)(code_c + sant_maj_min));
      else
		  return c;
  }
}


void test_inclusion(int ind,int droite)
{
  int i;
  bool egal;

  if (droite == 1) //sens == droite
  {
	  i = 1;
      egal = (majmin(bout[ind]) == majmin(elcour[i]));
      while ((egal) && (i < lgelcour) && !(fin_du_texte)) 
	  {
		  ind = plus1(ind, 1, fin_du_texte);
      i++;
      egal = (majmin(bout[ind]) == majmin(elcour[i]));
	  }
      if (verif_depd) 
	  {
          trouve = (((egal) && (fin_mot[ind]) && (i < lgelcour))||((egal) && (i == lgelcour)));
          if ((egal) && (fin_mot[ind]) && (i < lgelcour))
			  dd = true;
	  }
	  else
		  trouve = ((egal) && (i == lgelcour));
  }
  else
  {
	  i = lgelcour;
      egal = (majmin(bout[ind]) == majmin(elcour[i]));
      while ((egal) && (i > 1) && (!deb_du_texte))
	  {
		  ind = moins1(ind, 1, deb_du_texte);
          i--;
          egal = (majmin(bout[ind]) == majmin(elcour[i]));
	  }
	  if (verif_depg)
	  {
          trouve = (((egal) && (ind < 3) && (i > 1))||((egal) && (i == 1)));
          if ((egal) && (ind < 3) && (i > 1))
			  dg = true;
	  }
	  else
		  trouve = ((egal) && (i == 1));
  }
}


void test_appartenance(int ibout, bool droite)
{
    list_appart *p;
	
	if (droite == 1)  //sens == droite
	{
		//with regle_cour do
        decode(numidcour,regle_cour.ch_d[indregle+1],regle_cour.ch_d[indregle+2]);
        p = tens[numidcour];
        do
		{
			numelcour = p->num;
            extr_elem(numelcour, elcour, lgelcour);
            test_inclusion(ibout,1); // droite
            p = p->suivant;
		}
		 while (!((trouve)||(p == NULL)));
         }

	else
	{
        decode(numidcour, regle_cour.cxt_g[indregle-2],regle_cour.cxt_g[indregle-1]);
        p = tens[numidcour];
        do 
		{
            numelcour = p->num;
            extr_elem(numelcour, elcour, lgelcour);
            test_inclusion(ibout,0); //  gauche
            p = p->suivant;
		}
		while (!((trouve)||(p == NULL)));
	}
}


void ct_comparer()
{
	bool egal;
	
	if (toph_mot)
		fin_du_texte = false;
	// with regle_cour do
	egal = (majmin(bout[ibout]) == majmin(regle_cour.ch_d[indregle]));
    while ((egal) && (!fin_du_texte) && (indregle < regle_cour.l_ct))
	{
		ibout = plus1(ibout, 1, fin_du_texte);
        indregle++;
        egal = (majmin(bout[ibout]) == majmin(regle_cour.ch_d[indregle]));
	}
    trouve = ((egal) && (indregle == regle_cour.l_ct));
}


void cxt_droit_comparer()
{
	bool fin_facteur,fin_terme;
	while ((trouve)&&(indregle<=regle_cour.l_d)&&(!fin_du_texte))
	{
		trouve=false;
		do
		{
                if (trouve)
		{
			fin_terme=false;
			while (!fin_terme)
			{
				if (regle_cour.ch_d[indregle]=='/')
					indregle += 2;
				else
					indregle++;
				if (indregle > regle_cour.l_d)
					fin_terme=true;
				else
					fin_terme = ((regle_cour.ch_d[indregle]=='�')||(regle_cour.ch_d[indregle]=='+'));
			} // while
		}  // if (trouve)
		else
		{
			if (regle_cour.ch_d[indregle]=='"')
			{
				if ((!fin_du_texte)||(ibout==fin_bout))
					test_appartenance(ibout,1); // droite
				indregle += 4;
			}
			else
			{
				ext_terme(1); // droite
				if ((!fin_du_texte)||(ibout==fin_bout))
					test_inclusion(ibout,1); // droite
			}
			if (trouve)
				ibout=plus1(ibout,lgelcour,fin_du_texte);
		} // else
		if (indregle > regle_cour.l_d)
			fin_facteur = true;
		else
		{
			fin_facteur = (regle_cour.ch_d[indregle]=='+');
			indregle++;
		}   
               } while (!fin_facteur);// do
          }// while
}

void cxt_gauche_comparer()
{
	bool fin_facteur,fin_terme;

	while ((trouve)&&(indregle >= 1)&&(!deb_du_texte))
	{
		trouve=false;
		do 
		{
                if (trouve)
		{
			fin_terme=false;
			while (!fin_terme)
			{
				if (regle_cour.cxt_g[indregle]=='/')
					indregle -= 2;
				else
					indregle -= 1;
				if (indregle < 1)
					fin_terme=true;
				else
					fin_terme=((regle_cour.cxt_g[indregle]=='�')||(regle_cour.cxt_g[indregle]=='+'));
			} // while
		} // if (trouve)
		else
		{
			if (regle_cour.cxt_g[indregle]=='"')
			{
				if ((!deb_du_texte)||(ibout==deb_bout))
					test_appartenance(ibout,0); // gouche
				indregle -= 4;
			}
			else
			{
				ext_terme(0); // gouche
				if ((!deb_du_texte)||(ibout==deb_bout))
					test_inclusion(ibout,0); // gouche
			}
			if (trouve)
				ibout= moins1(ibout,lgelcour,deb_du_texte);
		} // else
		if (indregle < 1)
			fin_facteur=true;
		else
		{
			fin_facteur= (regle_cour.cxt_g[indregle]=='+');
			indregle --;
		}
                }
		while (!fin_facteur);
	} // while
}




void cat_comparer1()
{
	int ind1,ind2,i,lg_cat_reg,lg_cat_mot;
	category cat_reg;
        category cat_mot;
	bool termine;

	trouve=false;
	termine=false;
        for (int k=0;k<=max_lg_cat+1;k++)
                cat_reg[k]=' ';
        for (int k=0;k<=max_lg_cat+1;k++)
                cat_mot[k]=' ';
	ind1=1;
	while ((ind1 <= regle_cour.nb_cat_reg)&& !termine)
	{

			i=1;
                        for (int k=1;k<=regle_cour.ens_cat_reg[ind1].lg_cat;k++)
			        cat_reg[k]=regle_cour.ens_cat_reg[ind1].catg[k];
                         for (int l=1;l<=ens_cat_mot[ind1].lg_cat;l++)
                             cat_mot[l]=ens_cat_mot[ind1].catg[l];
			lg_cat_reg=regle_cour.ens_cat_reg[ind1].lg_cat;
                        lg_cat_mot=ens_cat_mot[ind1].lg_cat;


                        if ((majmin(cat_reg[i])=='�')||majmin(cat_mot[i])=='�' )
                                ind1++;
                        else
                        if   ((majmin(cat_reg[i])==majmin(cat_mot[i])))
                               ind1++;
                        else
                                termine=true;

	} // while ind1
	if (!termine)
         trouve=true;
} // cat_comparer1


void cat_comparer2()
{
	int ind1,ind2,i,lg_cat_reg,lg_cat_mot;
	category cat_reg;
        category cat_mot;
	bool termine;

	trouve=false;
	// with bout_cat[ind_cat] do
	// with regle_cour do
	termine=false;
                                for (int k=0;k<=max_lg_cat+1;k++)
			        cat_reg[k]=' ';
                         for (int k=0;k<=max_lg_cat+1;k++)
                             cat_mot[k]=' ';
	ind1=1;
	while ((ind1 <= regle_cour.nb_cat_reg)&&(!termine))
	{
		ind2=1;
		//while ((ind2 <= bout_cat[ind_cat].nb_categ)&&(!termine))
                while ((ind2 <= nb_cat_mot)&&(!termine))
		{
			i=1;
			//?????ens....,nb....
                        for (int k=1;k<=regle_cour.ens_cat_reg[ind1].lg_cat;k++)
			        cat_reg[k]=regle_cour.ens_cat_reg[ind1].catg[k];
                         for (int l=1;l<=ens_cat_mot[ind2].lg_cat;l++)
                             cat_mot[l]=ens_cat_mot[ind2].catg[l];
			       //cat_mot[l]=bout_cat[ind_cat].ens_cat[ind2].catg[l];
			lg_cat_reg=regle_cour.ens_cat_reg[ind1].lg_cat;
                        lg_cat_mot=ens_cat_mot[ind2].lg_cat;
			//lg_cat_mot=bout_cat[ind_cat].ens_cat[ind2].lg_cat;
			if ((cat_reg[1]=='�')||(cat_mot[1]=='�'))
			{
				i=2;
				if ((cat_reg[1]=='�')&&(cat_mot[1]=='�'))
				{
					while ((i<=lg_cat_reg)&&(i<=lg_cat_mot)&&(majmin(cat_reg[i])==majmin(cat_mot[i])))
						i++;
					if ((i != lg_cat_reg)&&(i != lg_cat_mot+1))
						ind2++;
					else
					{
						termine=true;
						trouve=true;
					}
				} // if cat_reg and cat_mot
				else
					if (cat_reg[1]=='�')
					{
						while ((i<=lg_cat_reg)&&(i<=lg_cat_mot+1)&&(majmin(cat_reg[i])==majmin(cat_mot[i-1])))
							i++;
						if ((i != lg_cat_reg+1)&&(i != lg_cat_mot+2))
						{
							termine=true;
							trouve=true;
						}
						else
							termine=true;
					} // if	ca_reg
					else
					{
						while ((i<=lg_cat_mot)&&(i<=lg_cat_reg+1)&&(majmin(cat_reg[i-1])==majmin(cat_mot[i])))
							i++;
						if ((i != lg_cat_reg+2)&&(i != lg_cat_mot+1))
						{
							termine=true;
							trouve=true;
						}
						else
							termine=true;
					} // if cat_mot
			} // if cat_reg or cat_mot
			else
			{
                                if   ((majmin(cat_reg[i])==majmin(cat_mot[i])))
                                {
			        	while ((majmin(cat_reg[i])==majmin(cat_mot[i]))&&(i<lg_cat_reg)&&(i<lg_cat_mot))
				        	i++;
				        if ((cat_reg[i+1]==' ')&&(cat_mot[i+1]==' '))
				        	trouve=(majmin(cat_reg[i])==majmin(cat_mot[i]));
			        	if (trouve)
				        	termine=true;
			        	else
				        	ind2++;
                                }
                                else
                                {    j=i+1;
			        	while ((majmin(cat_reg[i])==majmin(cat_mot[j]))&&(i<lg_cat_reg)&&(j<lg_cat_mot))
				               {
                                               i++;
                                               j++;
                                               }
				        if ((cat_reg[i+1]==' ')&&(cat_mot[j+1]==' '))
				        	trouve=(majmin(cat_reg[i])==majmin(cat_mot[j]));
			        	if (trouve)
				        	termine=true;
			        	else
				        	ind2++;

                                }
			} // else
		} // while ind2
		ind1++;
	} // while ind1
	// } with
} // cat_comparer1




void cat_comparer3()
{
	int ind1,ind2,i,lg_cat_reg,lg_cat_mot;
	category cat_reg;
        category cat_mot;
	bool termine;

	trouve=false;
	termine=false;
        for (int k=0;k<=max_lg_cat+1;k++)
                cat_reg[k]=' ';
        ens_cat_mot[1].catg[1]= '�';
        ens_cat_mot[2].catg[1]= '�';
        ens_cat_mot[3].catg[1]= '�';
        ens_cat_mot[4].catg[1]= '�';
        ens_cat_mot[1].lg_cat=1;
        ens_cat_mot[2].lg_cat=1;
        ens_cat_mot[3].lg_cat=1;
        ens_cat_mot[4].lg_cat=1;
        ind1=1;
	while ((ind1 <= regle_cour.nb_cat_reg)&& !termine)
	{

			i=1;
                        for (int k=1;k<=regle_cour.ens_cat_reg[ind1].lg_cat;k++)
			        cat_reg[k]=regle_cour.ens_cat_reg[ind1].catg[k];
                         for (int l=1;l<=ens_cat_mot[ind1].lg_cat;l++)
                             cat_mot[l]=ens_cat_mot[ind1].catg[l];
			lg_cat_reg=regle_cour.ens_cat_reg[ind1].lg_cat;
                       // 11/05/2006
                       lg_cat_mot=ens_cat_mot[ind1].lg_cat;

                       //  lg_cat_mot=4;

                        if ((majmin(cat_reg[i])=='�')||majmin(cat_mot[i])=='�' )
                                ind1++;
                        else
                        if   ((majmin(cat_reg[i])==majmin(cat_mot[i])))
                               ind1++;
                        else
                                termine=true;

	} // while ind1
	if (!termine)
         trouve=true;
} // cat_comparer1




void init_ens_cat()
{
	int i,j;
	for (i=1;i<=nb_max_cat;i++)
	{
		for (j=1;j<=max_lg_cat;j++)
			ens_cat_mot[i].catg[j]=' ';
		ens_cat_mot[i].lg_cat=0;
	}
}


void lire_espace_cat(int index)
{
        bool x1=true;
	while ((!fin_du_texte)&&(x1))
		if ((bout[index]==' ')||(bout[index]==((char)(9))))//�������������
                    index=plus1(index,1,fin_du_texte);

                else
                    x1=false;
}

bool lire_cats_mots()
{
    // bool found=true;
    	bool found;
	int index,k;

	nb_cat_mot=0;
	init_ens_cat();
	found=false;
	index=ind_bout;
	while ((bout[index] != '{')&&(bout[index] != ' '))
		index=plus1(index,1,fin_du_texte);
	if (bout[index] != ' ')
	{
		index=plus1(index,1,fin_du_texte);
		lire_espace_cat(index);
		while ((!fin_du_texte)&&(bout[index] != '}'))
		{
			nb_cat_mot++;
			k=0;
			while ((!fin_du_texte)&&(bout[index] != '�')&&(bout[index] != '}')&&(bout[index] != ' '))
			{
				k++;
				ens_cat_mot[nb_cat_mot].catg[k]=bout[index];
				index=plus1(index,1,fin_du_texte);
			}
			ens_cat_mot[nb_cat_mot].lg_cat=k;
			if ((!fin_du_texte)&&(bout[index]==' '))
				lire_espace_cat(index);
			if ((!fin_du_texte)&&(bout[index]=='�'))
			{
				index=plus1(index,1,fin_du_texte);
				found=true;
				lire_espace_cat(index);
			}
			else
				if ((!fin_du_texte)&&(bout[index]=='}'))
				{
					ind_cat=index;
					found=true;
				}
				else
				{

					fin_anormale=true;
					break;//????????halt;
				}
		}
	}
        return found;
	//????????returnfound;
	//lire_cats_mots=found;

}


void comparer_regle(ofstream &ftexte)
{

	// with regle_cour do
	int ind1;
        ind_cat=0;
	dd=false;
	dg=false;
	ibout=ind_bout;
	indregle=1;
	ct_comparer();
	if (trouve)
	{
		//ind_cat=ibout;
		indregle++;
		ibout=plus1(ibout,1,fin_du_texte);
		cxt_droit_comparer();
		if (trouve)
		{
			indregle=regle_cour.l_g;
			ibout=moins1(ind_bout,1,deb_du_texte);
			cxt_gauche_comparer();
			if (toph_mot)
			{
				if (trouve)
					if ((regle_cour.nb_cat_reg != 0)&&(cat_found))
						cat_comparer1();
			}
			else
				if (trouve)
				{
					if (regle_cour.nb_cat_reg != 0)
					{
                                                if (lire_cats_mots())
						//if (bout_cat[ind_cat].nb_categ != 0)
							cat_comparer1();
                                                else
                                                //change made 11/5/2006 to the case of the nb dont have a cat

                                                 // trouve = false;

                                                 {
                                                  cat_comparer3();
                                                 };
                                                    

					}

				}
		}
	}
	if ((trouve)&&(dd))
		ftexte<<"la regle appliquee depasse le texte a droit"<<'\n';
	else
		if ((trouve)&&(dg))
			ftexte<<"la regle appliquee depasse le texte a gauche"<<'\n';

}












