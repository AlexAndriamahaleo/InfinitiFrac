/*
**************************** 
* ANDRIAMAHALEO ALEX (C) EN COLLABORATION AVEC EL-YOUSFI AYOUB
* Programmation modulaire par ANDRIAMAHALEO ALEX
* VERSION 10.1.0 GCC V0.8
* FLOCON_KOCH.H 2016
* UNIX UBUNTU 14.04 LTS
****************************
*/

#ifndef __FLOCON_KOCH__
#define __FLOCON_KOCH__

#include "ez-draw.h"
#include "listep.h"
#include "listep_op.h"
#include "global_data.h"
#include "koch_zoom.h"

void 	flocon_on_expose (Ez_event *ev);
void 	flocon_on_button_press (Ez_event *ev);
void 	flocon_on_motion_notify (Ez_event *ev);
void 	flocon_to_zoom(Ez_event *ev);
int 	flocon_release(Ez_event *ev);
void 	flocon_on_button_release (Ez_event *ev);
void 	flocon_on_window_close(Ez_event *ev);
void 	flocon_event (Ez_event *ev);
void 	calcul_triangle_tier(PLISTE koch, double x_init, double y_init, double x_suiv, double y_suiv);
void 	generateur_koch(double longueur, double ax, double ay, int n, Ez_event *ev);
void 	flocon_de_koch(Global_data *fk, Ez_event *ev);
void 	menu_to_koch(Ez_event *ev);

#endif
