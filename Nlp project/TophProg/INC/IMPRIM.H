/* Header for module imprim */

#ifndef _imprim
#define _imprim

#include "types_toph1.h"
#include "var_trans.h"
#include "stdlib.h"

void extr_ident(int n,nom_ident &id,int &l);
int to_int(char c) ;
void decode(int &n, char &c1,char &c2);
void ecrire_contexte(ofstream &f, bool droite, int i1,int i2);
void ecrire_ct(ofstream &f);
void ecrire_pho(ofstream &f);
void ecrire_cat(ofstream &f);
void imprimer_regle(ofstream &f);
void trace_imprimer(ofstream &f);
void non_trans_imprimer(ofstream &f);
void stat_imprimer(ofstream &f);

#endif

/* End. */
