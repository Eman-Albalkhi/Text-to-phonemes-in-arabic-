//#include "types_toph1.h"
#include "var_trans.h"
#include "extrai.h"
#include "trace.h"
#include "init.h"
#include "imprim.h"
#include "lire.h"
#include "gerbou.h"
#include "cherch.h"
#include "trans.h"
#include <stdlib.h>
#include <string.h>
#include <iostream.h>
#include <time.h>
#include <sys/timeb.h>
//#include <SysUtils.h>
#include <vcl/sysdefs.h>
using namespace std;


void saisir_nom_gram()
{
        do
        {
	if (nompref_gra[0]=='?')
	{
        printf("  xxxxxx.: fichier des regles, deja structure par struct\n");
        printf("  xxxxxx.ens: fichier de sauvegarde des ensembles \n");
        printf("  xxxxxx.reg: fichier de sauvegarde des regles\n\n");
        printf("nom du prefixe des fichiers:");
        }
        } while (nompref_gra[0]=='?');
}


void saisir_gram(ifstream &fens)
{
	ini_ident(fens);
        ini_elem(fens);
        ini_ens(fens);
	fens.close();
}


void ecrire_entete_fichiers(ofstream &ftrace,ofstream &fslach,ofstream &fstat)
{
	int i;

	if (statistique || stat_tri)
	{
		for (i = 0; i <= nbregle; i++)
			stat[i] = 0;
                suff=".sta";
		fstat<<"!-- transcr. du texte: "<<nompref_txt<<" --!\n";
		fstat<<"!-- grammaire:"<<nompref_gra<<" --!\n";
		fstat<<"!-- statistiques sur la grammaire --!\n\n";
	}
	if (trace)
	{
		suff=".trc";
		ftrace<<"!-- transcr. du texte: "<<nompref_txt<<" --!"<<endl;
		ftrace<<"!-- grammaire:"<<nompref_gra<<" --!"<<endl;
		ftrace<<"!-- trace des regles utilisees --!"<<endl;
                ftrace<<endl;
	}
	if (graphon)
	{
		suff=".gph";
		fslach<<"  -------------------------------------------------------------- \n";
		fslach<<"   Ce fichier contient les mots transcrits avec les graphones\n";
		fslach<<"              separes par des slaches \n";
		fslach<<"  --------------------------------------------------------------  \n\n\n\n";
	}
}


void main_trans()
{ int z;
  char xz;
  using namespace std;

  bool entree_ecran;

	    fin_anormale=false;
	    entree_ecran=true;
            graphon=false;
            statistique=false;
            trace=false;
	    stat_tri=false;
	    if (entree_ecran)
		{

           //     cout<<"Vous avez le choix entre :"<<endl;
            //    cout<<"1. Faire la Transcription phonetique d'un texte . "<<endl;
           //     cout<<"2. quitter l'application. "<<endl<<endl;
           //     cin>>z;
          //      cout<<z<<endl;
          z=1;
                if (z==1)
                {
                saisir_nom_gram();
                ifstream fens("gram.ens");

                 ofstream ftransfert("ftransfert");
                ofstream ftexte("gram.phon");
                 ofstream fslach("story.gph");
                 ifstream texte1("story.txt");
                if(!fens.is_open())
                 exit(-1);
                if(fens.bad())
                 exit(-1);
               fens>>noskipws;
               texte1>>noskipws;
                saisir_gram(fens);
                ifstream top("gram.rg");
                if(!top.is_open())
                 exit(-1);
                if(top.bad())
                 exit(-1);

                ifstream f_dep("gram.tab");
                if(!f_dep.is_open())
                 exit(-1);
                if(f_dep.bad())
                 exit(-1);

                lire_top(f_dep,top);
                top.close();
                f_dep.close();

            //    cout<<"Voulez-vous la trace de la realisation des regles (o/n)?"<<endl;
             //   cin>>xz;
             xz='o';
                trace=((xz=='o')||(xz=='O'));
             //   cout<<"Voulez-vous les stat de la realisation des regles (o/n)?"<<endl;
            //    cin>>xz;
            xz='n' ;
                statistique=((xz=='o')||(xz=='O'));
                if (trace)
                    marque_trace = '\n';

                if (stat_tri)
                        statistique=true;
                ofstream fstat("story.sta");
                ofstream txttrans("story.tra");
                ofstream fres("fichier_res_transc.res");
                ofstream ftrace("story.trc");

  //              TDateTime x,y;
  //              x=Time();
                //int hx,mx,sx,msx;
                //DecodeTime(x,hx,mx,sx,msx);
                //cout<<"The Time before running= "<<hx<<mx<<sx<<msx<<endl;*/
                ecrire_entete_fichiers(ftrace,fslach,fstat);
                traiter_texte(texte1,ftrace,txttrans,fslach,fres,ftexte);
                //TDateTime y;
   //             y=Time();
    //            Word hx,mx,sx,msx;
   //             DecodeTime(x,hx,mx,sx,msx);
    //            cout<<"The Time before running= "<<hx<<":"<<mx<<":"<<sx<<":"<<msx<<endl;
     //           Word hy,my,sy,msy;
     //           DecodeTime(y,hy,my,sy,msy);
      //          cout<<"The Time after running= "<<hy<<":"<<my<<":"<<sy<<":"<<msy<<endl; */


					if (statistique && !stat_tri)
						stat_imprimer(fstat);
					if (graphon)
						fslach.close();
					if (trace)
						ftrace.close();
					if (statistique || stat_tri)
						fstat.close();
					texte1.close();
					txttrans.close();
					if (fin_anormale)
						cout<<"Fin Anormale : Vuillez ouvrir le fichier fichier_res_transc.res"<<'\n';
                        }  // if (rep=="1")
                        else
                          return;
		} 
}




























