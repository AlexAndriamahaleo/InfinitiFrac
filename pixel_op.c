/*
**************************** 
* ANDRIAMAHALEO ALEX (C) EN COLLABORATION AVEC EL-YOUSFI AYOUB
* VERSION BETA 1.0.0 GCC V0.8
* PIXEL_OP.C 2016
* UNIX UBUNTU 14.04 LTS
****************************
*/

#include "pixel_op.h"
#include "pixel_type.h"

PIXEL *initPixel( int R, int G, int B) // type IMAGE *
{
	PIXEL *init = malloc(sizeof(PIXEL)) ;
	init->R = R ;
	init->G = G ;
	init->B = B ;
	
	return init ;
	
}

void libere_pixel(PIXEL *pix)
{
	free(pix);
}
