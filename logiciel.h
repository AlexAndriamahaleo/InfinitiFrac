/*
****************************
* ANDRIAMAHALEO ALEX (C) EN COLLABORATION AVEC EL-YOUSFI AYOUB
* Programmation modulaire par ANDRIAMAHALEO ALEX
* VERSION 10.1.0 GCC V0.8
* LOGICIEL.H 2016
* UNIX UBUNTU 14.04 LTS
****************************
*/

#ifndef __LOGICIEL__
#define __LOGICIEL__

#include <stdio.h>
#include <stdlib.h>
#include "ez-draw.h"
#include "menu.h"
#include "global_data.h"
#include "mandelbrot.h"
#include "menu_julia.h"

int logiciel_input (Ez_event *ev, char *s);
void logiciel_display(Ez_event *ev, Global_data *logdisp);
void logiciel_on_expose(Ez_event *ev);
void logiciel_on_key_press(Ez_event *ev);
void logiciel_on_button_press(Ez_event *ev);
void logiciel_on_window_close (Ez_event *ev);

void logiciel_event (Ez_event *ev);


#endif
