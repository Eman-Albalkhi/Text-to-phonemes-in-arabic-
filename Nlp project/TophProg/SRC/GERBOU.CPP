// Program Name: gerbou


#include "gerbou.h"


int moins1(int i,int j,bool &debut)
{
  int  indice;
  bool one_time;

  indice = i;
  one_time = false;
  if (indice != deb_bout) 
  {
	  one_time = true;
      if (i - j >= 1)
		  indice = i - j;
      else
      indice = long_bout + (i - j);
  }
  debut = (indice == deb_bout);
  if (debut && one_time && (j == 1))
    return indice;
  else  if  (debut)
     return i;
  else
     return indice;
}


int plus1(int i,int j, bool &fin)
{
  int  indice;
  bool one_time;

  indice = i;
  one_time = false;
  if (indice != fin_bout) 
  {
	  one_time = true;
      if ((i + j) <= long_bout)
		  indice = i + j;
      else
          indice = (i + j) - long_bout;
  }
  fin = (indice == fin_bout);
  if (fin && one_time && (j == 1))
    return indice;
  else if (fin)
     return i;
  else
     return indice;
}



/* End. */
