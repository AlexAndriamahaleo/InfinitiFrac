/*
**************************** 
* ANDRIAMAHALEO ALEX (C)
* VERSION BETA 1.0.0 GCC V0.8
* CPLXOP.C 2016
* UNIX UBUNTU 14.04 LTS
****************************
*/


#include <stdlib.h>
#include <stdio.h>
#include "cplx.h"


COMPLEXE * add_cplx (COMPLEXE* cpx1, COMPLEXE* cpx2){
	COMPLEXE* cpx_add = malloc(sizeof(double));
	
	cpx_add->re = cpx1->re + cpx2->re ;
	cpx_add->im = cpx1->im + cpx2->im ;
	
	return cpx_add ;
	
}

COMPLEXE * moins_cplx (COMPLEXE* cpx1, COMPLEXE* cpx2,int FLAG_OP){
	
	COMPLEXE* cpx_moins = malloc(sizeof(double));
	
	if(FLAG_OP == 1){
		cpx_moins->re = - (cpx1->re) ;
		cpx_moins->im = - (cpx1->im) ;
	}
	else {
		cpx_moins->re = cpx1->re - cpx2->re ;
		cpx_moins->im = cpx1->im - cpx2->im ;
	}
	
	return cpx_moins ;
}


COMPLEXE * mul_cplx (COMPLEXE* cpx1, COMPLEXE* cpx2){
	
	COMPLEXE* cpx_mul = malloc(sizeof(double));
	
	cpx_mul->re = ((cpx1->re)*(cpx2->re) - (cpx1->im)*(cpx2->im)) ;
	cpx_mul->im = ((cpx1->re)*(cpx2->im) + (cpx1->im)*(cpx2->re)) ;
	
	return cpx_mul ;
}


COMPLEXE * mul_cplx_reel (COMPLEXE* cpx, double a){

	COMPLEXE* cpx_reel = malloc(sizeof(double));
	
	cpx_reel->re = a * (cpx->re) ;
	cpx_reel->im = a * (cpx->im) ;
		
	return cpx_reel ;
}
