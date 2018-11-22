/*
**************************** 
* ANDRIAMAHALEO ALEX (C) EN COLLABORATION AVEC EL-YOUSFI AYOUB
* VERSION BETA 1.0.0 GCC V0.8
* JULIA.H 2016
* UNIX UBUNTU 14.04 LTS
****************************
*/


#ifndef __JULIA__
#define __JULIA__

#include "ez-draw.h"
#include "mandel_calcul.h"
#include "global_data.h"
#include "ppm_image.h"

void julia_on_window_close(Ez_event *ev);
void julia_on_expose (Ez_event *ev);
void julia_event (Ez_event *ev);
void julia_image(Global_data *julia);

#endif

