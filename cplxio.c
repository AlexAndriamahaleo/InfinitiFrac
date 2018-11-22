/*
**************************** 
* ANDRIAMAHALEO ALEX (C)
* VERSION BETA 1.0.0 GCC V0.8
* CPLXIO.C 2016
* UNIX UBUNTU 14.04 LTS
****************************
*/


#include <stdlib.h>
#include <stdio.h>
#include "cplx.h"
#include "util.h"


COMPLEXE * create_complexe(double r, double i){

	COMPLEXE *comp = malloc(sizeof(double));
	
	comp->im = i ;
	comp->re = r ;
	
	return comp ;
	
}


COMPLEXE * lire_complexe(void){
	
	double r, i ;
	COMPLEXE *comp_lu = malloc(sizeof(double));
	
	int m = scanf("%lf %lf", &r, &i);
	m++ ;
	comp_lu = create_complexe(r,i);
	
	return comp_lu ;
}

void ecrire_complexe (COMPLEXE *comp){

	printf("%lf %lf\n", comp->re, comp->im);
	
}

void clean_stdin(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}
