/*
**************************** 
* ANDRIAMAHALEO ALEX (C) EN COLLABORATION AVEC EL-YOUSFI AYOUB
* VERSION BETA 1.0.0 GCC V0.8
* MANDELBROT.C 2016
* UNIX UBUNTU 14.04 LTS
****************************
*/

#include "ez-draw.h"
#include "mandelbrot.h"


void mandel_on_window_close(Ez_event *ev)
{
	Global_data * mwc = ez_get_data(ev->win);
	
	(void)ev;
	
	ez_window_destroy(mwc->window_mandelbrot);
	mwc->window_mandelbrot = None ;
	mwc->enable_mandelbrot = 0 ;
	
	mwc->save_statut = 0 ;
	strncpy(mwc->fois_zoom,"1",BUF_MAX);
	
	ez_send_expose(mwc->logiciel);
}


void ppm_button(Ez_event *ev, Global_data *mb)
{
	strncpy(mb->save_image,"images/Mandelbrot/mandelbrot_",BUF_MAX);
	if(atoi(mb->fois_zoom) == 1)
		strcat(mb->save_image,"normal");
	else
	{
		strcat(mb->save_image,"zoom_x");
		strcat(mb->save_image,mb->fois_zoom);
	}
	
	strcat(mb->save_image,".ppm");
	
	mb->save_statut = save_ppm(mb->mandelbrot,mb->save_image);
	
	ez_send_expose (ev->win);
	ez_start_timer(ev->win,3000);
}

void mandel_on_button_release (Ez_event *ev)
{
	ez_send_expose(ev->win);
	
}

void mandel_on_button_press (Ez_event *ev)
{
	Global_data *mbp = ez_get_data(ev->win) ;
	
	int w, h;
	
	mbp->tmpx = ev->mx ;
	mbp->tmpy = ev->my ;
	
	
	ez_window_get_size (mbp->window_mandelbrot, &w, &h);
	
	if( (ev->mx > w-100) && (ev->mx < w-10) && (ev->my > h-(40*h/41)) && (ev->my < h-(13*h/14)) )
	{
		ppm_button(ev,mbp);
	}
	else if( (ev->mx > w/30-10) && (ev->mx < w/30+50) && (ev->my > h-(40*h/41)) && (ev->my < h-(13*h/14)) )
	{
		mandel_on_window_close(ev) ;
	}
	else
	{
		ez_send_expose(mbp->window_mandelbrot);
	}
}

void mandel_on_expose (Ez_event *ev)
{
	int w, h, i, j ;
	Ez_uint8 r,g,b ;
	
	
	
	Global_data *m = ez_get_data(ev->win);
	
	ez_window_get_size(ev->win, &w, &h);
	
	double x_min, x_max, y_min, y_max ;
	
	m->zoom_fois = atoi(m->fois_zoom) ;
	
	x_min = (-1.85 / m->zoom_fois) ;
	x_max = (2.4 / m->zoom_fois) ;
	y_min = (-1.5 / m->zoom_fois) ;
	y_max = (1.5 / m->zoom_fois) ;
	
	m->mandelbrot = genererMandelbrot(w,h,x_min, x_max, y_min, y_max);
	
	for(i=0 ; i < m->mandelbrot->largeur ; i++){
		for(j=0 ; j < m->mandelbrot->hauteur ; j++){
			
			r =  m->mandelbrot->tab[i][j].R ;
			g =  m->mandelbrot->tab[i][j].G ;
			b =  m->mandelbrot->tab[i][j].B ;
			
			ez_set_color (ez_get_RGB(r,g,b));
			
			ez_draw_point (ev->win, i, j);
		}
	}
	
	ez_set_color(ez_get_RGB(0,0,0));
	ez_fill_rectangle(ev->win, w/30-10, h-(40*h/41), w/30+50, h-(13*h/14)); // Retour
	
	if(m->save_statut == 1)
	{
		ez_set_color(ez_get_RGB(0,255,0));
		ez_fill_rectangle(ev->win, w-100, h-(40*h/41), w-10, h-(13*h/14)); // Sauvegarde vert
	}
	else
		ez_fill_rectangle(ev->win, w-100, h-(40*h/41), w-10, h-(13*h/14)); // Sauvegarde normal
	
	
	ez_set_color(ez_get_RGB(255, 0, 0));
	ez_draw_rectangle(ev->win, w-100, h-(40*h/41), w-10, h-(13*h/14)); // Sauvegarde
	ez_draw_rectangle(ev->win, w/30-10, h-(40*h/41), w/30+50, h-(13*h/14)); // Retour 
	
	ez_set_color(ez_white);
	ez_draw_text(ev->win, EZ_MC, w-55, h-(19*h/20), "Sauvegarde");
	ez_draw_text(ev->win, EZ_MC, w/30+20, h-(19*h/20), "Retour");
	
	ez_set_nfont (0);
	ez_draw_text(ev->win, EZ_BL, 1, h, "ANDRIAMAHALEO Alex (C) version 10.3.1");

}

void mandel_on_timer_notify(Ez_event *ev)
{
	Global_data *mtn = ez_get_data(ev->win);
	
	if(mtn->save_statut == 1)
	{
		ez_start_timer(ev->win,10);
		mtn->save_statut = 0 ;
		ez_send_expose (ev->win);
	}
	
}

void mandel_event (Ez_event *ev)
{
    
    switch (ev->type) {
        case Expose   : mandel_on_expose    (ev); break;        
        case ButtonPress : mandel_on_button_press (ev); break;
        case WindowClose : mandel_on_window_close (ev); break;
        case TimerNotify : mandel_on_timer_notify (ev); break;
    }
}

void mandelbrot_image(Global_data *mandel)
{
	
	
	
	if(mandel->window_mandelbrot != None)
	{
		ez_window_destroy(mandel->window_mandelbrot);
		mandel->window_mandelbrot = ez_window_create (700, 500, "Fractale de Mandelbrot", mandel_event);
	}
	else
		mandel->window_mandelbrot = ez_window_create (700, 500, "Fractale de Mandelbrot", mandel_event);
	
    ez_set_data(mandel->window_mandelbrot,mandel);
    ez_window_dbuf(mandel->window_mandelbrot, 1);
    mandel->enable_mandelbrot = 1 ;
    
    ez_auto_quit (0);
    
}

