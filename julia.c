/*
**************************** 
* ANDRIAMAHALEO ALEX (C) EN COLLABORATION AVEC EL-YOUSFI AYOUB
* VERSION BETA 1.0.0 GCC V0.8
* JULIA.C 2016
* UNIX UBUNTU 14.04 LTS
****************************
*/

#include "ez-draw.h"
#include "julia.h"

void julia_on_window_close(Ez_event *ev)
{
	Global_data *jwc = ez_get_data(ev->win);
	
	(void)ev;
	
	ez_window_destroy(jwc->window_julia);
	jwc->enable_julia = 0 ;
	jwc->window_julia = None ;
	ez_send_expose(jwc->menu_julia);
	
}

void ppm_julia_button(Ez_event *ev, Global_data *jb)
{
	strncpy(jb->save_julia,"images/Julia/julia_",BUF_MAX);

	strcat(jb->save_julia,jb->ConstX);
	strcat(jb->save_julia,"_");
	strcat(jb->save_julia,jb->ConstY);	
	strcat(jb->save_julia,".ppm");
	
	jb->save_statut = save_ppm(jb->julia,jb->save_julia);
	
	ez_send_expose (ev->win);
	
	ez_start_timer(ev->win,3000);
}

void julia_on_button_press(Ez_event *ev)
{
	Global_data *jbp = ez_get_data(ev->win);
	
	int w, h ;
	
	ez_window_get_size(jbp->window_julia, &w, &h);
	
	if( (ev->mx > w-100) && (ev->mx < w-10) && (ev->my > h-(40*h/41)) && (ev->my < h-(13*h/14)) )
	{
		ppm_julia_button(ev,jbp);
	}
	else if( (ev->mx > w/30-10) && (ev->mx < w/30+50) && (ev->my > h-(40*h/41)) && (ev->my < h-(13*h/14)) )
	{
		julia_on_window_close(ev);
	}
	
}

void julia_on_expose (Ez_event *ev)
{
	int w, h, i, j ;
	Ez_uint8 r,g,b ;
	
	double Cre, Cim ;
	
	ez_window_get_size(ev->win, &w, &h);
	
	Global_data *joexp = ez_get_data(ev->win);
	
	Cre = atof(joexp->ConstX);
	Cim = atof(joexp->ConstY);
	
	joexp->julia = genererJulia(w,h,Cre,Cim,-1.85, 2.4, -1.5, 1.5);
	
	for(i=0 ; i < joexp->julia->largeur ; i++){
		for(j=0 ; j < joexp->julia->hauteur ; j++){
			
			r =  joexp->julia->tab[i][j].R ;
			g =  joexp->julia->tab[i][j].G ;
			b =  joexp->julia->tab[i][j].B ;
			
			ez_set_color (ez_get_RGB(r,g,b));
			
			ez_draw_point (ev->win, i, j);
		}
	}
	
	ez_set_color(ez_get_RGB(255,20,147));
	ez_fill_rectangle(ev->win, w/30-10, h-(40*h/41), w/30+50, h-(13*h/14)); // Retour
	
	if(joexp->save_statut == 1)
	{
		ez_set_color(ez_get_RGB(255,165,0));
		ez_fill_rectangle(ev->win, w-100, h-(40*h/41), w-10, h-(13*h/14)); // Sauvegarde orange
	}
	else
		ez_fill_rectangle(ev->win, w-100, h-(40*h/41), w-10, h-(13*h/14)); // Sauvegarde normal
	
	
	
	ez_set_color(ez_black);
	ez_draw_rectangle(ev->win, w-100, h-(40*h/41), w-10, h-(13*h/14)); // Sauvegarde
	ez_draw_rectangle(ev->win, w/30-10, h-(40*h/41), w/30+50, h-(13*h/14)); // Retour 
	
	ez_draw_text(ev->win, EZ_MC, w-55, h-(19*h/20), "Sauvegarde");
	ez_draw_text(ev->win, EZ_MC, w/30+20, h-(19*h/20), "Retour");
	
	ez_set_nfont (0);
    ez_draw_text(ev->win, EZ_BL, 1, h, "ANDRIAMAHALEO Alex (C) version 10.3.1");
}

void julia_on_key_press (Ez_event *ev)
{
    switch (ev->key_sym) {
        case XK_q : julia_on_window_close (ev); break;
    }

}

void julia_on_timer_notify(Ez_event *ev)
{
	Global_data *jtn = ez_get_data(ev->win);
	
	if(jtn->save_statut == 1)
	{
		ez_start_timer(ev->win,10);
		jtn->save_statut = 0 ;
		ez_send_expose (ev->win);
	}
	
}

void julia_event (Ez_event *ev)
{
    
    switch (ev->type) {
        case Expose   : julia_on_expose    (ev); break;
        case KeyPress : julia_on_key_press (ev); break;
        case ButtonPress : julia_on_button_press (ev); break;
        case WindowClose : julia_on_window_close (ev); break;
        case TimerNotify : julia_on_timer_notify (ev); break;
    }
}

void julia_image(Global_data *julia)
{
	
	
	
	if(julia->window_julia != None)
	{
		ez_window_destroy(julia->window_julia);
		julia->window_julia = ez_window_create (700,500, "Fractale de Julia", julia_event);
	}
	else		
		julia->window_julia = ez_window_create (700,500, "Fractale de Julia", julia_event);
	
	ez_set_data(julia->window_julia,julia);
	ez_window_dbuf(julia->window_julia, 1);
	julia->j_flag_julia = TRUE ;
	julia->enable_julia = 1 ;
    ez_auto_quit (0);
    
}

