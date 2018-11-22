/*
****************************
* ANDRIAMAHALEO ALEX (C)
* VERSION BETA 1.1.0 GCC V0.8
* LISTEP_OP.C 2016
* UNIX UBUNTU 14.04 LTS
****************************
*/


#include <stdlib.h>
#include <stdio.h>
#include "listep.h"
#include "listep_op.h"	

PLISTE init_liste(double xx, double yy)
{

	PLISTE liste = malloc(sizeof(EPOINT));
	
	liste->x = xx ;
	liste->y = yy ;
	liste->next = NULL ;
	
	return liste ;
	
}

EPOINT * insert_after(EPOINT * elt, double xx, double yy)
{
	
	EPOINT *new_pt = init_liste(xx,yy);
	
	new_pt->next = elt->next ;
	elt->next = new_pt ;
	
	return new_pt ;
}


EPOINT * remove_after(EPOINT * elt)
{
	
	elt->next = elt->next->next ;
	free(elt->next);
	
	return elt ;
}

PLISTE lire_liste(char * nf)
{

	double xx, yy;
	PLISTE liste ;
	PLISTE tmp ;
	
	FILE* fichier = NULL;
	fichier = fopen(nf,"r");
	
	int m = fscanf(fichier, "%lf %lf", &xx, &yy);
	m +=1 ;
	
	tmp = init_liste(xx,yy);
	liste = tmp ;
	
	while(fscanf(fichier, "%lf %lf", &xx, &yy) != EOF){
		tmp->next = insert_after(tmp,xx,yy);
		tmp = tmp->next ;
	}
	
	fclose(fichier);

	return liste ;
}


void ecrire_liste(char * nf, PLISTE pl)
{

	double xx, yy;
	FILE* fichier ;
	fichier = fopen(nf, "w");
	
	while( pl != NULL){
		xx = pl->x ;
		yy = pl->y ;
		pl = pl->next ;
		fprintf(fichier,"%.2lf %.2lf\n", xx, yy);
	}

	fclose(fichier);
}
	
	
	
	
	
	
	
	
	
	
