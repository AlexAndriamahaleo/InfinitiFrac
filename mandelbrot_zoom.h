/*
**************************** 
* ANDRIAMAHALEO ALEX (C) EN COLLABORATION AVEC EL-YOUSFI AYOUB
* VERSION BETA 1.0.0 GCC V0.8
* MANDELBROT_ZOOM.H 2016
* UNIX UBUNTU 14.04 LTS
****************************
*/

#ifndef __MANDEL_ZOOM__
#define __MANDEL_ZOOM__

#include "ez-draw.h"
#include "mandel_calcul.h"

void mandel_zoom_expose(Ez_event *ev) ;
void mandel_zoom_on_window_close(Ez_event *ev) ;
void mandel_zoom_event(Ez_event *ev) ;
void zoom_sur_mandelbrot(Global_data *ZSM) ;


#endif
