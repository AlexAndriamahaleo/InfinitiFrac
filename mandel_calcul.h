/*
**************************** 
* ANDRIAMAHALEO ALEX (C) EN COLLABORATION AVEC EL-YOUSFI AYOUB
* VERSION BETA 1.0.0 GCC V0.8
* MANDEL_CALCUL.H 2016
* UNIX UBUNTU 14.04 LTS
****************************
*/


#ifndef __MANDEL_CALCUL__
#define __MANDEL_CALCUL__

#include "image_op.h"
#include "cplxio.h"
#include "cplxop.h"
#include "pixel_op.h"
#include "pixel_type.h"
#include "image_type.h"
#include "image_op.h"
#include "global_data.h"

#define MAX_ITER_MANDEL 1000
#define MAX_ITER_JULIA 1500

COMPLEXE *convertir_cplx(int i, int j, IMAGE *PM, double c_x, double c_y) ;
int convergence(COMPLEXE *z, COMPLEXE *cst, int MAX);
IMAGE *genererMandelbrot(int w, int h, double xmin, double xmax, double ymin, double ymax ) ;
IMAGE *genererJulia(int w, int h, double C_re, double C_im, double xmin, double xmax, double ymin, double ymax);

#endif
