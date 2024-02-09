/* Header for module trans */


#ifndef _trans
#define _trans
#include "var_trans.h"
#include "stdlib.h"

void LIRE_BLANC(ifstream &texte);
void lire_espace(ifstream &texte);
int to_int(char c);
void chercher_regle(ofstream &ftexte);
void methode2_ecrire_phon(ofstream &f);
void ecrire_phon(ofstream &f);
void transcrire_ct(ofstream &ftrace,ofstream &txttrans,ofstream &fslach);
void incr_fin_bout();
void decr_fin_bout();
bool lire_ens_cat1();
void lire_mot(type_bout mot);
void init_bout(ifstream &texte);
void lister_non_trans();
void ecrire_fichiers(int meth,ofstream &fres,ofstream &ftrace,ofstream &txttrans,ofstream &fslach);
void deplacer_tete_et_reecrire(ofstream &ftrace,ofstream &fres,ofstream &fslach,ofstream &txttrans,ofstream &ftexte);
void transcrire_mot(type_bout &mot,type_bout &mot_trans);
void transcrire2_texte();
void traiter_fin();
void transcrire1_texte(ifstream &texte,ofstream &ftrace,ofstream &fres,ofstream &fslach,ofstream &txttrans,ofstream &ftexte);
void traiter_texte(ifstream &texte,ofstream &ftrace,ofstream &txttrans,ofstream &fslach,ofstream &fres,ofstream &ftexte);

#endif