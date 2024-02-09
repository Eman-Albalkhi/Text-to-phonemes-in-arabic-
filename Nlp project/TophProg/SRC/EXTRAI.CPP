//Program Name: extrai

#include "extrai.h"

void ext_terme(bool droite)
{

  bool fin_terme;
  int i;
// with regle_cour do
  lgelcour = 0;
  fin_terme = false;
  if (droite == 1)    //sens=droite (yameen)
  {
    while (!fin_terme)
	{
      lgelcour++;
      if (regle_cour.ch_d[indregle] == '/')
	  {
		  indregle++;
	      elcour[lgelcour] = regle_cour.ch_d[indregle];
	      indregle += 2;
	  }
	  else
	  {
	      elcour[lgelcour] = regle_cour.ch_d[indregle];
	      indregle++;
      }
      if (indregle > regle_cour.l_d)
		  fin_terme = true;
      else
	      fin_terme = ((regle_cour.ch_d[indregle] == '+') ||
		     (regle_cour.ch_d[indregle ] == '¡'));
    }  // end while
  }	  // end if
  else
  {
	  while (!fin_terme)
	  {
		  lgelcour++;
          if (regle_cour.cxt_g[indregle] == '/')
		  {
			  indregle--;
              elcour[max_lg_elem - lgelcour] = regle_cour.cxt_g[indregle];
              indregle -= 2;
		  }
		  else
		  {
			  elcour[max_lg_elem - lgelcour+1] = regle_cour.cxt_g[indregle];
              indregle--;
		  }
		  if (indregle < 1)
			    fin_terme = true;
		  else
			  fin_terme = ((regle_cour.cxt_g[indregle] == '+') ||(regle_cour.cxt_g[indregle] == '¡'));
	  }	 // end while
	  for (i = 1; i <= lgelcour ; i++)
		  elcour[i] = elcour[i + max_lg_elem - lgelcour];
	  }	// else
 //end with
}


void extr_elem(int n, nom_elem &el, int &l)

{



	int i,j;
    l = 0;
    i = tadel[n].adr - 1;
    while (l < tadel[n].lg)
	{
        l++;
    //    j=(sizeof (char))*(i+l);
     //     el[l] =((ptel+j)*);
     el[l] = (*ptel)[i+l];
      //  ptel=ptel->suivant;
	}

}



/* End. */
