/*
****************************
* ANDRIAMAHALEO ALEX (C) EN COLLABORATION AVEC EL-YOUSFI AYOUB
* Programmation modulaire par ANDRIAMAHALEO ALEX
* VERSION 10.1.0 GCC V0.8
* FLOCON_KOCH.C 2016
* UNIX UBUNTU 14.04 LTS
****************************
*/

#include "flocon_koch.h"

void flocon_on_expose (Ez_event *ev)
{

	int xx, yy ;
	int w, h ;

	Global_data *fexp = ez_get_data(ev->win) ;

	ez_window_get_size(fexp->window_flocon, &w, &h);

	PLISTE pl = lire_liste(fexp->BUF_fichier_point);


	ez_set_color(ez_get_RGB(0,0,0));

  ez_fill_rectangle(ev->win, 0, 0, w, h);


	ez_set_color(ez_get_RGB(0,0,0));
	ez_fill_rectangle(ev->win, w-75, h-(40*h/41), w-10, h-(13*h/14)); // Interieur

	ez_set_color(ez_get_RGB(255, 0, 0));
	ez_draw_rectangle(ev->win, w-75, h-(40*h/41), w-10, h-(13*h/14)); // Contour

	ez_set_color(ez_white);
	ez_draw_text(ev->win, EZ_MC, w-40, h-(19*h/20), "Retour");


	ez_set_color(ez_get_RGB(30, 144, 255));

	ez_set_thick(1);
	ez_set_nfont(1);
	PLISTE tmp = malloc(sizeof(EPOINT));
	PLISTE init = malloc(sizeof(EPOINT));

	init = pl ;
	tmp = pl->next ;

	while(pl != NULL && tmp != NULL){

		xx = pl->x ;
		yy = pl->y ;
		ez_draw_line(ev->win, xx, yy, tmp->x, tmp->y);
		pl = pl->next ;
		tmp = pl->next ;
	}

    ez_draw_line(ev->win, init->x, init->y, pl->x, pl->y);


     ez_set_nfont (0);
	ez_set_color(ez_get_RGB(30, 144, 255));
	 ez_draw_text(ev->win, EZ_BL, 1, h, "ANDRIAMAHALEO Alex (C) version 10.3.1");
}

int flocon_release(Ez_event *ev)
{
	int w, h;

	Global_data *szoom = ez_get_data(ev->win) ;

	ez_window_get_size(szoom->window_flocon, &w, &h);


	szoom->zoom_win_w = w ;
	szoom->zoom_win_h = h ;

	szoom->zoom_mx = ev->mx;
	szoom->zoom_my = ev->my;

	szoom->zoom_dplt_h = 0;
	szoom->zoom_dplt_v = 0;

	if(atof(szoom->menu_zoom) != 0)
		szoom->zoom_recup_percent = atof(szoom->menu_zoom);

	flocon_to_zoom(ev);

	if( (ev->mx > w-75) && (ev->mx < w-10) && (ev->my > h-(40*h/41)) && (ev->my < h-(13*h/14)) )
    {
		return 1 ;
	}
	else
		return 0 ;
}

void flocon_on_button_release (Ez_event *ev)
{
	int k ;

	k = flocon_release(ev);

	if(k == 1)
		flocon_on_window_close(ev);
	else
		ez_send_expose (ev->win);

}

void flocon_on_button_press (Ez_event *ev)
{
	int w, h ;

	Global_data *fkey = ez_get_data(ev->win) ;

	ez_window_get_size(fkey->window_flocon, &w, &h);

    if( (ev->mx > w-75) && (ev->mx < w-10) && (ev->my > h-(40*h/41)) && (ev->my < h-(13*h/14)) )
    {
			flocon_on_window_close(ev);
	}

}

void flocon_on_window_close(Ez_event *ev)
{
	Global_data *zoom = ez_get_data(ev->win) ;

	if(zoom->k_enable_zoom == 1)
	{
		ez_window_destroy(zoom->window_zoom);
		zoom->window_zoom = None ;
		zoom->k_enable_zoom = 0 ;
	}

    if(zoom->k_enable_flocon == 1)
    {
		ez_window_destroy(zoom->window_flocon);
		zoom->window_flocon = None ;
		zoom->k_enable_flocon = 0 ;
	}
}

void flocon_event (Ez_event *ev)
{
    switch (ev->type) {
        case Expose   : flocon_on_expose    (ev); break;
        case ButtonPress : flocon_on_button_press (ev); break ;
        case ButtonRelease : flocon_on_button_release (ev); break;
        case WindowClose : flocon_on_window_close (ev); break;
    }
}

void calcul_triangle_tier(PLISTE koch, double x_init, double y_init, double x_suiv, double y_suiv)
{

	double cx, cy ;
	double dx, dy ;
	double ex, ey ;

	// calcul point premier tier
	cx = x_init + ((x_suiv-x_init)/3) ;
	cy = y_init + ((y_suiv-y_init)/3) ;

	// calcul point deuxième tier
	dx = x_init + (2*((x_suiv-x_init)/3)) ;
	dy = y_init + (2*((y_suiv-y_init)/3)) ;

	// calcul point pic du triangle
	ex = ((cx+dx)/2) + (dy-cy)*(sqrt(3)/2);
	ey = ((cy+dy)/2) - (dx-cx)*(sqrt(3)/2);

	insert_after(koch, dx, dy);
	insert_after(koch, cx, cy);
	insert_after(koch->next, ex, ey);


}


void generateur_koch(double longueur, double ax, double ay, int n, Ez_event *ev)
{
	Global_data *gk = ez_get_data(ev->win) ;

	double bx, by, zx, zy ;

	PLISTE koch = init_liste(ax,ay) ;
	PLISTE init = koch ;
			// Calcul de l'itaration 0 //
	zx = ax + longueur ;
	zy = ay ;
	insert_after(koch , zx , zy ) ;

	bx = ax + (longueur/2) ;
	by = ay - (longueur*(sqrt(3)/2));

	insert_after(koch , bx , by ) ;
			//-------------------------//

	while(n > 0){

		while(koch->next != NULL){
			calcul_triangle_tier(koch, koch->x, koch->y, koch->next->x, koch->next->y);

			koch = koch->next->next->next->next ;
		}
		n--;
		calcul_triangle_tier(koch, koch->x, koch->y, init->x, init->y);
		koch = init ;
	}
	ecrire_liste(gk->BUF_fichier_point, init) ;

}


void flocon_de_koch(Global_data *fk, Ez_event *ev)
{

	strcat(fk->fichier_point,"long_");
	strcat(fk->fichier_point,fk->longueur);
	strcat(fk->fichier_point,"_X_");
	strcat(fk->fichier_point,fk->coorX);
	strcat(fk->fichier_point,"_Y_");
	strcat(fk->fichier_point,fk->coorY);
	strcat(fk->fichier_point,"_IT_");
	strcat(fk->fichier_point,fk->iteration);
	strcat(fk->fichier_point,".in");

	sprintf(fk->BUF_fichier_point,"fichier_point/%s",fk->fichier_point);

	strncpy(fk->fichier_point,"",BUF_MAX);

	strcat(fk->nom_de_fichier_sauvegarde,"long_");
	strcat(fk->nom_de_fichier_sauvegarde,fk->longueur);
	strcat(fk->nom_de_fichier_sauvegarde,"_X_");
	strcat(fk->nom_de_fichier_sauvegarde,fk->coorX);
	strcat(fk->nom_de_fichier_sauvegarde,"_Y_");
	strcat(fk->nom_de_fichier_sauvegarde,fk->coorY);
	strcat(fk->nom_de_fichier_sauvegarde,"_IT_");
	strcat(fk->nom_de_fichier_sauvegarde,fk->iteration);
	strcat(fk->nom_de_fichier_sauvegarde,".ppm");

	sprintf(fk->BUF_nom_de_fichier_sauvegarde, "images/Koch/%s",fk->nom_de_fichier_sauvegarde);


	strncpy(fk->nom_de_fichier_sauvegarde,"",BUF_MAX);

	fk->k_count = -1 ;
	fk->k_longueur = atof(fk->longueur);
	fk->k_x = atof(fk->coorX);
	fk->k_y = atof(fk->coorY);
	fk->k_n = atoi(fk->iteration);

	generateur_koch(fk->k_longueur,fk->k_x,fk->k_y,fk->k_n,ev);

}

void menu_to_koch(Ez_event *ev)
{
	Global_data *koch = ez_get_data(ev->win) ;

	flocon_de_koch(koch,ev);

    if(koch->window_flocon == None){
		koch->window_flocon = ez_window_create (koch->k_win_w, koch->k_win_h, "Flocon de Koch", flocon_event);
		ez_set_data(koch->window_flocon,koch);
	}
	else {
		ez_window_destroy(koch->window_flocon);
		koch->window_flocon = ez_window_create (koch->k_win_w, koch->k_win_h, "Flocon de Koch", flocon_event);
		ez_set_data(koch->window_flocon,koch);
	}
	koch->k_flag_koch = TRUE ;
	koch->k_enable_flocon = 1 ;

}
