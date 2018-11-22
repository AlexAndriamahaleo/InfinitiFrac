/*
**************************** 
* ANDRIAMAHALEO ALEX (C) EN COLLABORATION AVEC EL-YOUSFI AYOUB
* VERSION BETA 1.0.0 GCC V0.8
* IMAGE_OP.C 2016
* UNIX UBUNTU 14.04 LTS
****************************
*/

#include "image_type.h"
#include "image_op.h"


IMAGE *initImage(int hauteur, int largeur)
{
	int j ;
	
	IMAGE *init = malloc(sizeof(IMAGE));
	
	init->hauteur = hauteur ;
	init->largeur = largeur ;
	
	init->tab = malloc( (init->largeur) * sizeof(PIXEL*) ) ;
	
	for(j=0 ; j < init->largeur ; j++) // pour chaque X
	{
		init->tab[j] = malloc((init->hauteur)*sizeof(PIXEL));
	}
	
	return init ;
	
}

void SetPixel(IMAGE *im, PIXEL *p, int lig, int col)
{
	im->tab[lig][col] = *p ;
}

void SupprimerImage(IMAGE *im)
{
	int i ;
	
	for(i=0 ; i < im->hauteur ; i++){
		libere_pixel(im->tab[i]);
	}
	
	free(im->tab) ;
	
	free(im) ;
	
}
