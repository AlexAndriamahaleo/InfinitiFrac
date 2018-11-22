/*
**************************** 
* ANDRIAMAHALEO ALEX (C) EN COLLABORATION AVEC EL-YOUSFI AYOUB
* VERSION BETA 1.0.0 GCC V0.8
* MANDELBROT.H 2016
* UNIX UBUNTU 14.04 LTS
****************************
*/


#ifndef __MANDEL__
#define __MANDEL__

#include "ez-draw.h"
#include "mandel_calcul.h"
#include "global_data.h"
#include "ppm_image.h"

void mandel_on_window_close(Ez_event *ev);
void ppm_button(Ez_event *ev, Global_data *mb);
void mandel_on_button_press (Ez_event *ev);
void mandel_on_expose (Ez_event *ev);
void mandel_on_timer_notify(Ez_event *ev);
void mandel_event (Ez_event *ev);
void mandelbrot_image(Global_data *mandel);

#endif
