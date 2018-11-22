/*
**************************** 
* ANDRIAMAHALEO ALEX (C) EN COLLABORATION AVEC EL-YOUSFI AYOUB
* VERSION BETA 1.0.0 GCC V0.8
* IMAGE_OP.H 2016
* UNIX UBUNTU 14.04 LTS
****************************
*/

#ifndef __IMAGE_OP__
#define __IMAGE_OP__

#include "pixel_op.h"
#include "image_type.h"


IMAGE *initImage(int hauteur, int largeur);
void SetPixel(IMAGE *im, PIXEL *p, int lig, int col);
void SupprimerImage(IMAGE *im) ;

#endif
