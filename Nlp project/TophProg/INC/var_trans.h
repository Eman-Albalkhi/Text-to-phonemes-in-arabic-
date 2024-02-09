// Var_Trans
#ifndef _var_trans.h
#define _var_trans.h

#include "types_toph1.h"
#include <iostream.h>
#include <fstream.h>
#include <string.h>

//extern tab_elem ptel;
//extern ptr_tab_elem ptel;
//extern tab_elem*ptr_tab_elem;
extern tab_elem *maillon1,*maillon2;
extern tab_elem *ptel;
extern int indtel;
extern tab_adr_elem tadel;
extern int indtadel;
extern nom_elem elcour;
extern int numelcour;
extern int lgelcour;

extern tab_ident tid;
extern int indtid;
extern tab_adr_ident tadid;
extern int indtadid;

extern nom_ident idcour;
extern int numidcour;
extern int lgidcour;

extern tab_ens tens;

extern type_bout bout,mot_trans,mot;
extern int lgtrans;
extern int incr,deb_bout,fin_bout,i,ind_bout,ibout;

//***********input or outpur files???
//extern ofstream tata; //?????file of text
//extern ofstream invers;//file of text
//extern ofstream fslach; //text
//ifstream gram;  //text
//ifstream fens;  //text
//extern ifstream texte1; //text
//extern ofstream txttrans; //text
///extern ofstream ftrace; //text
///extern ofstream fstat;  //text
//ofstream fredon("fredon"); //text

extern struc_regle* regle;
extern int indregle;
extern int nbregle;

extern bool regle_valide,fin_texte,fin_du_texte,deb_du_texte,trouve;
extern int stat[max_nb_regle];
extern list_non_trans* tete_non_trans;
extern list_trace* tete_trace;
extern list_trace* head_trace;

extern list_non_trans *maillon1_non_trans,*maillon2_non_trans;
extern list_trace *maillon1_trace,*maillon2_trace;
extern list_trace *red1_trace,*red2_trace,*red_fin;

extern char nompref_gra[20],nompref_txt[20];
extern char car,marque_trace;
extern bool trace,statistique,trace_non_trans;

extern toph_phonemes top_phonemes;
extern tables_phonemes tab_phon;
extern int nb_phonemes;
extern int ind_tab_phon;

//int z;
//int xz;
extern int lcat,incrt;
extern bool cat_found;
extern bool toph_mot;
extern bool graphon;
extern type_ens_cat ens_cat_mot;
extern int nb_cat_mot;
extern int ind_cat;

extern char *suff;
extern int j;

extern int nb_non_transcrit,increment;
extern bool bid,pre_mot;
extern bool cr_lf[long_bout];
extern bool fin_mot[long_bout];
extern bool teste_redondance,red_globale,red_locale,pre_reg;
extern char classe_debut,classe_fin;
extern bool categ;
extern struc_regle regle_etude;
extern int indice_etude;

///extern ifstream top; //file of struc_regle
///extern ifstream f_dep; //text
extern int indice_cour;
extern struc_regle regle_cour;
extern type_tab_dep tab_dep;
extern type_tab_regle tab_regle;
extern int nb_regle;
///extern ofstream fres; //text

extern types_cat bout_cat[long_bout];


extern int ind3;
///extern ofstream ftexte; //text
//extern ofstream ftransfert;
//fstream ftexte1("ftexte1",ios::in | ios::out); //text
extern bool phon_ctxt;

extern bool verif_depd,verif_depg;
extern bool dd,dg;
extern bool fin_anormale;
extern bool bool_majmin;
extern bool stat_tri;

#endif





