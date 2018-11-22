/*
**************************** 
* ANDRIAMAHALEO ALEX (C) EN COLLABORATION AVEC EL-YOUSFI AYOUB
* Programmation modulaire par ANDRIAMAHALEO ALEX
* VERSION 10.1.0 GCC V0.8
* MENU_JULIA.H 2016
* UNIX UBUNTU 14.04 LTS
****************************
*/

#ifndef __MENU_JULIA__
#define __MENU_JULIA__

#include "ez-draw.h"
#include "ppm_image.h"
#include "julia.h"
#include "global_data.h"

int 	menu_julia_input (Ez_event *ev, char *s);
void 	menu_julia_display (Ez_window win, Global_data *disp);

void 	menu_julia_on_expose (Ez_event *ev);
void 	menu_julia_on_key_press (Ez_event *ev);
void 	effacer(Global_data *m) ;
int 	menu_julia_button(Ez_event *ev);
void 	menu_julia_on_button_press (Ez_event *ev);
void 	menu_julia_event (Ez_event *ev);

void 	menu_julia(Global_data *global);


#endif
