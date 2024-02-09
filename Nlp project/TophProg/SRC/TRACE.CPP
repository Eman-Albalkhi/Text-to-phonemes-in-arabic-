// Program Name: trace

#include "trace.h"


void construire_trace()
{
	if (tete_trace==NULL)
	{
		maillon1_trace=new list_trace;
		tete_trace=maillon1_trace;
		// with maillon1_trace* do {
		maillon1_trace->indice_regle=indice_cour;
		maillon1_trace->suivant=NULL;
	}
	else
	{
		maillon2_trace=maillon1_trace;
                maillon1_trace=new list_trace;
		maillon2_trace->suivant=maillon1_trace;
		// with maillon1_trace* do
		maillon1_trace->indice_regle=indice_cour;
		maillon1_trace->suivant=NULL;
	}
}

void disposer_trace(list_trace *p)
{
	if (p != NULL)
	{
		if (p->suivant==NULL)
			delete[] p;
		else
		{
			disposer_trace(p->suivant);
			delete[] p;
		}
	}
	tete_trace=NULL;
}


			


