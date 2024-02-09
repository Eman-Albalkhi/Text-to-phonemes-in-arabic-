 //program name: var_struct


#ifndef _var_struct
#define _var_struct

#include "types_toph1.h"
#include <iostream.h>
#include <fstream.h>
#include <string.h>
ofstream top; //file of struct_regle
ofstream ftab;
//fstream ftab("ftab",ios::in | ios::out); //file of text

type_tab_long tab_long,tab_dep;
struc_list* alphabet[256 ];
int nbregle;

//fstream fcorres("fcorres",ios::in | ios::out); //file of text
fstream fres("fres",ios::in | ios::out); //file of text
char *suff;
//string  chemin_gram;
//char *chemin_gram;
char chemin_gram[20];
char trace_car;
int numregle;
struc_regle regle;
ptr_tab_elem ptel;
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
bool sens;
ifstream gram; //file of text
string u;
//int GRAM;
char car;

ofstream res,fens;

//fstream Res("Res",ios::in | ios::out); //file of text
//fstream Contxt("Contxt",ios::in | ios::out); //file of text
//fstream FENS("FENS",ios::in | ios::out); //file of text

int long_nompref;

ofstream ftrace("FTRACE"); //file of text

char rep;
bool trace;
list_mot_cxt lmc;
int imc;
bool entree_ecran,fin_anormale;
bool bool_majmin;


#endif

// end.