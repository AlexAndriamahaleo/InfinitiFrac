/*
**************************** 
* ANDRIAMAHALEO ALEX (C) EN COLLABORATION AVEC EL-YOUSFI AYOUB
* Programmation modulaire par ANDRIAMAHALEO ALEX
* VERSION 10.1.0 GCC V0.8
* KOCH_ZOOM.C 2016
* UNIX UBUNTU 14.04 LTS
****************************
*/

#include "koch_zoom.h"

void zoom (int x, int y, int w, int h, double percent, Global_data *z, PLISTE l, Ez_event *ev)
{

	// Affectation des données de la fenetre flocon dans la structure Zoom_data
	z->zoom_x = x;
	z->zoom_y = y;
	
	z->w = w;
	z->h = h;

	z->zoom_percent = percent / 100;

	// Calcul de la taille de la fenêtre du zoom
	z->zoom_wz = z->w / z->zoom_percent; 
	z->zoom_hz = z->h / z->zoom_percent;


	PLISTE tmp = malloc(sizeof(EPOINT));
	PLISTE key_press = malloc(sizeof(EPOINT));
	l = lire_liste(z->BUF_fichier_point);
	tmp = l;
	key_press = l;


	double x_init = z->zoom_percent * (l->x + z->zoom_dplt_h) -  z->zoom_percent/2 * (z->zoom_x + (z->zoom_x - z->zoom_wz));
	
	double y_init = z->zoom_percent * (l->y + z->zoom_dplt_v) -  z->zoom_percent/2 * (z->zoom_y + (z->zoom_y - z->zoom_hz));


	while(l->next != NULL) {
		l->x = z->zoom_percent * (l->x + z->zoom_dplt_h) - z->zoom_percent/2 * (z->zoom_x + (z->zoom_x - z->zoom_wz));
		l->y = z->zoom_percent * (l->y + z->zoom_dplt_v) - z->zoom_percent/2 * (z->zoom_y + (z->zoom_y - z->zoom_hz));
		l = l->next;
	}
	
	l->x = z->zoom_percent * (l->x + z->zoom_dplt_h) - z->zoom_percent/2 * (z->zoom_x + (z->zoom_x - z->zoom_wz));
	l->y = z->zoom_percent * (l->y + z->zoom_dplt_v) - z->zoom_percent/2 * (z->zoom_y + (z->zoom_y - z->zoom_hz));

	switch(ev->key_sym) {
		case XK_Down :
			while (key_press->next != NULL) {
				key_press->x += 10;
				key_press = key_press->next;
			}
	}

	while(tmp->next != NULL) {
		ez_draw_line(ev->win, tmp->x, tmp->y, tmp->next->x, tmp->next->y);
		tmp = tmp->next;
	}

	ez_draw_line(ev->win, l->x, l->y, x_init, y_init);

}


void zoom_on_expose (Ez_event *ev)
{
	Global_data *zexp = ez_get_data(ev->win) ;
	

	ez_set_thick(1);
	ez_set_nfont(0);
	
	int w, h;
	
	ez_window_get_size (zexp->window_zoom, &w, &h);
	
	ez_set_color(ez_get_RGB(240,230,140));	
    ez_fill_rectangle(ev->win, 0, 0, w, h);
	
	ez_set_color(ez_get_RGB(0,0,0));
	ez_fill_rectangle(ev->win, w-75, h-(40*h/41), w-10, h-(13*h/14)); // Interieur
	
	ez_set_color(ez_get_RGB(255, 0, 0));
	ez_draw_rectangle(ev->win, w-75, h-(40*h/41), w-10, h-(13*h/14)); // Contour
	
	ez_set_color(ez_white);
	ez_draw_text(ev->win, EZ_MC, w-40, h-(19*h/20), "Retour");
	
	PLISTE l = malloc(sizeof(EPOINT));


	ez_set_color(ez_blue);
	zoom (zexp->zoom_mx, zexp->zoom_my, w, h, zexp->zoom_recup_percent, zexp, l, ev);


	ez_set_color (ez_blue);
	ez_draw_text(ev->win, EZ_BL, 1, h, "EL YOUSFI Ayoub (C) version 10.3.1");
	ez_draw_text (ev->win, EZ_BR, w, h, "mx = %d | my = %d | dplt vertical = %.0lf | dplt horizontal %.0lf | Zoom = %.0lf%%", zexp->zoom_mx, zexp->zoom_my, zexp->zoom_dplt_v, zexp->zoom_dplt_h, zexp->zoom_recup_percent); 

}


void zoom_on_key_press (Ez_event *ev)
{
	Global_data *zkp = ez_get_data(ev->win) ;
	
	switch (ev->key_sym)
	{        
		case XK_KP_Add      : zkp->zoom_recup_percent += 10; ez_send_expose (ev->win); break;
		case XK_KP_Subtract : zkp->zoom_recup_percent -= 10; ez_send_expose (ev->win); break;
		
		case XK_Up			: zkp->zoom_dplt_v += 5; ez_send_expose (ev->win); break;
		case XK_Down		: zkp->zoom_dplt_v -= 5; ez_send_expose (ev->win); break;
		case XK_Left		: zkp->zoom_dplt_h += 5; ez_send_expose (ev->win); break;
		case XK_Right		: zkp->zoom_dplt_h -= 5; ez_send_expose (ev->win); break;
	}

}

void zoom_on_button_press (Ez_event *ev)
{
	Global_data *zbp = ez_get_data(ev->win) ;
	int w, h;
	
	ez_window_get_size (zbp->window_zoom, &w, &h);
	
	if( (ev->mx > w-75) && (ev->mx < w-10) && (ev->my > h-(40*h/41)) && (ev->my < h-(13*h/14)) )
	{
		zbp->k_enable_zoom = 0 ;
		ez_window_destroy(zbp->window_zoom) ;
	}
}


void zoom_on_window_close (Ez_event *ev)
{
	Global_data *zwc = ez_get_data(ev->win) ;
	
    zwc->k_enable_zoom = 0 ;
    ez_window_destroy (zwc->window_zoom); 
}


void zoom_event (Ez_event *ev)
{
	switch (ev->type) {
		case Expose      : zoom_on_expose       (ev); break;
		case KeyPress    : zoom_on_key_press    (ev); break;
		case ButtonPress : zoom_on_button_press (ev); break ;
		case WindowClose : zoom_on_window_close (ev); break;
	}

}

void flocon_to_zoom(Ez_event *ev)
{
	Global_data *ftz = ez_get_data(ev->win) ;
	
	if(ftz->k_enable_zoom == 1)
		ez_window_destroy(ftz->window_zoom);
	
	ftz->k_enable_zoom = 1 ;
	ftz->window_zoom = ez_window_create (ftz->zoom_win_w, ftz->zoom_win_h, "Zoom", zoom_event);
	ez_window_dbuf(ftz->window_zoom, 1);
	ez_set_data(ftz->window_zoom, ftz);
}
