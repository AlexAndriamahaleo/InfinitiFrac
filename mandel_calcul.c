/*
**************************** 
* ANDRIAMAHALEO ALEX (C) EN COLLABORATION AVEC EL-YOUSFI AYOUB
* VERSION BETA 1.0.0 GCC V0.8
* MANDEL_CALCUL.C 2016
* UNIX UBUNTU 14.04 LTS
****************************
*/


#include "mandel_calcul.h"


COMPLEXE *convertir_cplx_coor(int i, int j, int w, int h, double c_x, double c_y)
{
	
	COMPLEXE *c = create_complexe(i,j);
	
	c->re =( ( i*c_x ) / w - (c_x/1.95) ) + i/w ;
	c->im =( ( j*c_y ) / h - (c_y/2.0) ) + j/h ;
	
	return c ;
}


COMPLEXE *convertir_cplx(int i, int j, IMAGE *PM, double c_x, double c_y)
{
	COMPLEXE *c = create_complexe(i,j);
	c->re =( ( ( i*c_x ) / PM->largeur ) - (c_x/1.95) ) ;
	c->im =( ( ( j*c_y ) / PM->hauteur ) - (c_y/2.0) ) ;
	
	return c ;
}


int convergence(COMPLEXE *z, COMPLEXE *cst, int MAX)
{
	int k = 0 ;
	
	do{
		double tmp = z->re ;
		z->re = (z->re*z->re) - (z->im*z->im) + cst->re ;
		z->im = 2.0*z->im*tmp + cst->im ;
		k++ ;
	}
	while( ((z->re*z->re) + (z->im*z->im) < 4) && (k < MAX) );
	
	return k ;
}


IMAGE *genererMandelbrot(int w, int h, double xmin, double xmax, double ymin, double ymax )
{
	int i, j, c, max ;
	double comp_x, comp_y ;

	COMPLEXE *z ;
	COMPLEXE *z0 ;
	
	comp_x = (xmax - xmin) ;
	comp_y = (ymax - ymin) ;
	
	max = MAX_ITER_MANDEL ;	
	
	IMAGE *img = initImage(h,w) ;
	
	PIXEL *noir = initPixel(0,0,0);
	
	for(i=0 ; i < img->largeur ; i++)
	{
		for(j=0; j < img->hauteur ; j++)
		{
			z0 = convertir_cplx( i, j, img, comp_x, comp_y) ;
			z0->re -= 0.35 ;
			
			z = convertir_cplx( i, j, img, comp_x, comp_y) ;
			z->re -= 0.35 ;
			
			c = convergence(z,z0,MAX_ITER_MANDEL);
			
			PIXEL *couleur = initPixel(0,(c*MAX_ITER_MANDEL)%255,(c*MAX_ITER_MANDEL)%255);
			PIXEL *couleur_ext = initPixel((c*max*MAX_ITER_MANDEL)%200,(c*max*MAX_ITER_MANDEL)%200, (c*max*MAX_ITER_MANDEL)%255);
			
			if(max > 1)
				max-- ;
			
			if (c < MAX_ITER_MANDEL){
				if(c < 10)
					SetPixel(img,couleur_ext,i,j) ;
				else
					SetPixel(img,couleur,i,j) ;
			}
			else
				SetPixel(img,noir,i,j) ;
		}
	}

	
	return img ;
}


IMAGE *genererJulia(int w, int h, double C_re, double C_im, double xmin, double xmax, double ymin, double ymax)
{
	IMAGE *img = initImage(h,w);
	
	int i, j, c, max ;
	double comp_x, comp_y ;
	
	COMPLEXE *z ;
	COMPLEXE *z0 = create_complexe(C_re, C_im);
	
	comp_x = (xmax - xmin) ;
	comp_y = (ymax - ymin) ;
	
	max = MAX_ITER_JULIA ;
	
	PIXEL *noir = initPixel(0,0,0);
	
	
	for(i=0 ; i < img->largeur ; i++)
	{
		for(j=0; j < img->hauteur ; j++)
		{
			
			z = convertir_cplx( i, j, img, comp_x, comp_y);
			
			c = convergence(z,z0,MAX_ITER_JULIA);
			
			PIXEL *couleur = initPixel(0,(c*MAX_ITER_MANDEL)%255,(c*MAX_ITER_MANDEL)%255);
			
			PIXEL *couleur_ext = initPixel(255,(c*max*MAX_ITER_MANDEL)%255,255);
			
			if(max > 1)
				max-- ;
			
			if (c < MAX_ITER_JULIA){
				if(c < 10)
					SetPixel(img,couleur_ext,i,j) ;
				else
					SetPixel(img,couleur,i,j) ;
			}
			else
				SetPixel(img,noir,i,j) ;
		}
	}
	
	return img ;
}

