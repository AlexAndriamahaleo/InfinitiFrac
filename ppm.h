
/*
**************************** 
* ANDRIAMAHALEO ALEX (C) EN COLLABORATION AVEC EL-YOUSFI AYOUB
* VERSION 2.2.1 GCC V0.8
* PPM.H 2016
* UNIX UBUNTU 14.04 LTS
****************************
*/

#ifndef __PPM__
#define __PPM__

#include <stdio.h>
#include <stdlib.h>
#include "listep.h"
#include "listep_op.h"

int tab_ppm[600][700] ; // [Y][X]

void draw_ligne(int x1, int y2, int x2);
void Bresenham(int x1, int y1, int x2, int y2);
int ppm(int width, int height, int color_max, char *fp, char *nfs);

#endif

