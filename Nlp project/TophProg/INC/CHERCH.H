/* Header for module  cherch */

#ifndef _cherch
#define _cherch


int to_int(char c);
char majmin(char c);
void test_inclusion(int ind,bool droite);
void test_appartenance(int ibout, bool droite);
void ct_comparer() ;
void cxt_droit_comparer();
void cxt_gauche_comparer();
void cat_comparer1();
void init_ens_cat();
void lire_espace_cat(int &index) ;
bool lire_cats_mots();
void comparer_regle(ofstream &ftexte) ;

#endif
