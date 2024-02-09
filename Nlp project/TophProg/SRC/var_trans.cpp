

#include "types_toph1.h"
#include <iostream.h>
#include <fstream.h>
#include <string.h>

//tab_elem* ptr_tab_elem;
 tab_elem *maillon1,*maillon2;
tab_elem *ptel;

//ptr_tab_elem ptel;
int indtel;
tab_adr_elem tadel;
int indtadel;
nom_elem elcour;
int numelcour;
int lgelcour;

tab_ident tid;
int indtid;
tab_adr_ident tadid;
int indtadid;

nom_ident idcour;
int numidcour;
int lgidcour;

tab_ens tens;

type_bout bout,mot_trans,mot;
int lgtrans;
int incr,deb_bout,fin_bout,i,ind_bout,ibout;


struc_regle* regle;
int indregle;
int nbregle;
bool regle_valide,fin_texte,fin_du_texte,deb_du_texte,trouve;
int stat[max_nb_regle+1];
list_non_trans* tete_non_trans;
list_trace* tete_trace;
list_trace* head_trace;

list_non_trans *maillon1_non_trans,*maillon2_non_trans;
list_trace *maillon1_trace,*maillon2_trace;
list_trace *red1_trace,*red2_trace,*red_fin;

char nompref_gra[21],nompref_txt[21];
char car,marque_trace;
bool trace,statistique,trace_non_trans;

toph_phonemes top_phonemes;
tables_phonemes tab_phon;
int nb_phonemes;
int ind_tab_phon;
category cat_mot;
int lcat,incrt;
bool cat_found;
bool categ;
bool toph_mot=false;
bool graphon;
type_ens_cat ens_cat_mot;
int nb_cat_mot;
int ind_cat;

char *suff;
int j;

int nb_non_transcrit,increment;
bool bid,pre_mot;
bool cr_lf[long_bout+1];
bool fin_mot[long_bout+1];
bool teste_redondance,red_globale,red_locale,pre_reg;
char classe_debut,classe_fin;

struc_regle regle_etude;
int indice_etude;

int indice_cour;
struc_regle regle_cour;
type_tab_dep tab_dep;
type_tab_regle tab_regle;

types_cat bout_cat[long_bout+1];
int ind3;
bool phon_ctxt;

bool verif_depd,verif_depg;
bool dd,dg;
bool fin_anormale;
bool bool_majmin;
bool stat_tri;







