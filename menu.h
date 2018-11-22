/*
**************************** 
* ANDRIAMAHALEO ALEX (C) EN COLLABORATION AVEC EL-YOUSFI AYOUB
* Programmation modulaire par ANDRIAMAHALEO ALEX
* VERSION 10.1.0 GCC V0.8
* MENU.H 2016
* UNIX UBUNTU 14.04 LTS
****************************
*/

#ifndef __MENU__
#define __MENU__

#include "ez-draw.h"
#include "ez-image.h"
#include "ppm.h"
#include "flocon_koch.h"
#include "global_data.h"

int 	menu_input (Ez_event *ev, char *s);
void 	menu_display (Ez_window win, Global_data *disp);

void 	menu_on_expose (Ez_event *ev);
void 	menu_on_key_press (Ez_event *ev);
void 	effacer(Global_data *m) ;
int 	menu_button(Ez_event *ev);
void 	menu_on_button_press (Ez_event *ev);
void 	menu_event (Ez_event *ev);

void 	global_init(Global_data *g);

void 	menu_koch(Global_data *global);


#endif
