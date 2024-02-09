// Program Name: lire

#include "lire.h"



void lire_top(ifstream &f_dep,ifstream &top)
{
  int i;

  if(!f_dep.is_open())
    exit(-1);
  if(f_dep.bad())
    exit(-1);
  if(!top.is_open())
    exit(-1);
  if(top.bad())
    exit(-1);

  for (i = 0; i <= 255; i++)
       f_dep>>tab_dep[i];
   f_dep>>nbregle;
  top>>noskipws;
  int a;
  for (i = 0; i <= nbregle; i++)
  {
     top>>tab_regle[i].l_g;
      car=top.get();
     for (a=1;a<=tab_regle[i].l_g;a++)
     {
              top>>tab_regle[i].cxt_g[a];
     }
      car=top.get();
     top>>tab_regle[i].l_ct;
      car=top.get();
     top>>tab_regle[i].l_d;
      car=top.get();
     for (a=1;a<=tab_regle[i].l_d;a++)
     {
         top>>tab_regle[i].ch_d[a];
     }
      car=top.get();
     top>>tab_regle[i].nb_cat_reg;
      car=top.get();
      bool f2=true;
     for (a=1;a<=tab_regle[i].nb_cat_reg;a++)
     {
         top>>tab_regle[i].ens_cat_reg[a].lg_cat;
          car=top.get();
         if((tab_regle[i].ens_cat_reg[a].lg_cat)==0)
             car=top.get();
         else
         {
           f2=false;
           for (int b=1;b<=tab_regle[i].ens_cat_reg[a].lg_cat;b++)
           {
              top>>tab_regle[i].ens_cat_reg[a].catg[b];
           }
          car=top.get();
         }
     }
        if (f2)
          car=top.get();
     top>>tab_regle[i].l_ph;
      car=top.get();
     for (a=1;a<=tab_regle[i].l_ph;a++)
     {
         top>>tab_regle[i].pho[a];
     }
      car=top.get();
     top>>tab_regle[i].num;
      car=top.get();
     top>>tab_regle[i].inclue;
      car=top.get();
     top>>tab_regle[i].poly_ph;
      car=top.get();
     top>>tab_regle[i].sentinelle;
      car=top.get();
      //  car=top.get();
   }//for
}



