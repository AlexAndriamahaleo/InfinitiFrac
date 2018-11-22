/*
**************************** 
* ANDRIAMAHALEO ALEX (C) EN COLLABORATION AVEC EL-YOUSFI AYOUB
* VERSION 2.2.1 GCC V0.8
* PPM_IMAGE.C 2016
* UNIX UBUNTU 14.04 LTS
****************************
*/

#include "ppm_image.h"


int save_ppm(IMAGE *img, char *nfs)
{
	int i, j ;
	int r,g,b ;
	
	char *nf = nfs ;
	
	FILE* f = fopen(nf,"w");
	
	fprintf(f,"P3\n");
	fprintf(f,"# format de l'image\n");
	fprintf(f,"%d %d\n", img->largeur, img->hauteur);
	
	fprintf(f,"# val color max\n");
	fprintf(f,"%d",255);
	
	
	for(i=0 ; i < img->hauteur ; i++)
	{ 
		fprintf(f,"\n");
		
		for(j=0 ; j < img->largeur ; j++)
		{ 
			r = img->tab[j][i].R ;
			g = img->tab[j][i].G ;
			b = img->tab[j][i].B ;
			
			fprintf(f,"%d %d %d ", r, g, b); 
		}
	}
	return 1 ;
}	

