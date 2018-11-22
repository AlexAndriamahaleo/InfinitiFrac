/*
**************************** 
* ANDRIAMAHALEO ALEX (C) EN COLLABORATION AVEC EL-YOUSFI AYOUB
* VERSION BETA 1.0.0 GCC V0.8
* IMAGE_TYPE.H 2016
* UNIX UBUNTU 14.04 LTS
****************************
*/


#ifndef __IMAGE__
#define __IMAGE__

#include "pixel_type.h"

typedef struct IMAGE IMAGE ;

struct IMAGE
{
	PIXEL **tab ;		
	int hauteur ;
	int largeur ;
};


#endif
