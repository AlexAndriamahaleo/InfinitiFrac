/*
**************************** 
* ANDRIAMAHALEO ALEX (C) EN COLLABORATION AVEC EL-YOUSFI AYOUB
* Programmation modulaire par ANDRIAMAHALEO ALEX
* VERSION 10.1.0 GCC V0.8
* KOCH_ZOOM.H 2016
* UNIX UBUNTU 14.04 LTS
****************************
*/

#ifndef __KOCH_ZOOM__
#define __KOCH_ZOOM__

#include "global_data.h"
#include "ez-draw.h"
#include "listep.h"
#include "listep_op.h"

void 	zoom (int x, int y, int w, int h, double percent, Global_data *z, PLISTE l, Ez_event *ev);
void 	zoom_on_expose (Ez_event *ev);
void 	zoom_on_window_close (Ez_event *ev);
void 	zoom_on_key_press (Ez_event *ev);
void 	zoom_on_button_press (Ez_event *ev);
void 	zoom_event (Ez_event *ev);
void 	flocon_to_zoom(Ez_event *ev);

#endif
