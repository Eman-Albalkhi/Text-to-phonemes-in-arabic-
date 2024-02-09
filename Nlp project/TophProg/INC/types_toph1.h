// program name: types_toph

#ifndef _types_toph1
#define _types_toph1


const int nb_max_ph_reg=4,max_tab_phon=2000;
const int max_lg_cxt_g=300,max_lg_ch_d=300,max_lg_ph=40;
const int max_num_elem=4000;
const int max_tab_elem=25000;
const int max_lg_elem=100,max_tab_ident=1500;
const int max_num_ident=100,max_lg_ident=30;
const int max_lg_mat=80,long_bout=50;
const char prim_car_alpha=((char) 0),last_car_alpha=((char) 255);
const int prim_car_ascii=0,last_car_ascii=255;
const int code_a_max=65,code_z_max=90;
const int code_a_min=97,code_z_min=122;
const int sant_maj_min=32,nb_max_phon=500;
const int nb_max_mots_cxt=50,lg_max_mots_cxt=30;
const int max_lg_cat=10,nb_max_cat=5;
const int max_nb_regle=5000;
typedef char category[max_lg_cat+1];

struct cat_lg {
category catg;
int lg_cat;
};

typedef cat_lg type_ens_cat[nb_max_cat+1];

typedef struct {
int nb_categ;
type_ens_cat ens_cat;
}types_cat;

typedef char context[max_lg_ch_d+1];
typedef char context_gauche[max_lg_cxt_g+1];
typedef char chain_droit[max_lg_ch_d+1];
typedef char chain_phon[max_lg_ph+1];
struct struc_regle {
	context_gauche cxt_g;
	chain_droit ch_d;
	type_ens_cat ens_cat_reg;
	int l_g;
	int l_ct;
	int l_d;
	int nb_cat_reg;
	chain_phon pho;
	int l_ph;
	int num;
	bool inclue;
	bool poly_ph;
	int sentinelle;
} ;


struct struc_list {
	struc_regle element;
	struc_list* suivant;
};



struct list_trace {
	int indice_regle;
	list_trace* suivant;
};


struct list_non_trans {
	char car;
	list_non_trans* suivant;
};

typedef char tab_elem[max_tab_elem+1];
/*struct tab_elem {
	char tab1;
	tab_elem* suivant;
};
*/
//typedef  tab_elem* ptr_tab_elem;
struct adr_lg {
	int adr,lg;
};

typedef struct adr_lg tab_adr_elem[max_lg_elem+1];
typedef char nom_elem[max_lg_elem+1];
typedef char tab_ident[max_tab_ident+1];


typedef struct adr_lg tab_adr_ident[max_num_ident+1];
struct list_appart {
	int num;
	list_appart* suivant;
};
typedef list_appart* tab_ens[max_num_ident+1];
typedef char nom_ident[max_lg_ident+1];


typedef char type_bout[long_bout+1];
struct mcxt_long {
	nom_elem mcxt;
	int lon_g;
};
typedef mcxt_long list_mot_cxt[nb_max_mots_cxt+1];
struct ind_stat {
	int ind,lg;
	struc_list* ptregle;
};
typedef ind_stat toph_phonemes [nb_max_phon+1];
typedef char tables_phonemes[max_tab_phon+1];
struct phon_long {
	chain_phon phon;
	int lon_g;
};
typedef phon_long ens_phon_regle[nb_max_ph_reg+1];
typedef int  type_tab_dep[256];
typedef struc_regle  type_tab_regle[max_nb_regle+1];
typedef int type_tab_long[256];

#endif

// end.
