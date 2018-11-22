/*
**************************** 
* ANDRIAMAHALEO ALEX (C) EN COLLABORATION AVEC EL-YOUSFI AYOUB
* VERSION BETA 1.0.0 GCC V0.8
* MANDELBROT_ZOOM.C 2016
* UNIX UBUNTU 14.04 LTS
****************************
*/

#include "ez-draw.h"
#include "mandelbrot_zoom.h"


double position_X(Ez_event *ev) // retourne le coefficient pour X
{
	int w, h;
	
	ez_window_get_size (ev->win, &w, &h);
	
	Global_data *posX = ez_get_data(ev->win);
	
	if( posX->tmpx < w/8 )
		return -3.5 ;
	else if( posX->tmpx > w/8 && posX->tmpx < (2*w)/8 )
		return -2.5 ;
	else if( posX->tmpx > (2*w)/8 && posX->tmpx < (3*w)/8 )
		return -1.5 ;
	else if( posX->tmpx > (3*w)/8 && posX->tmpx < 4*w/8 )
		return -0.5 ;
	else if( posX->tmpx > 4*w/8 && posX->tmpx < 5*w/8 )
		return 0.5 ;
	else if( posX->tmpx > 5*w/8 && posX->tmpx < 6*w/8 )
		return 1.5 ;
	else if( posX->tmpx > 6*w/8 && posX->tmpx < 7*w/8 )
		return 2.5 ;
	else if( posX->tmpx > 7*w/8 )
		return 3.5 ;
	else
		return 0 ;
}

double position_Y(Ez_event *ev) // retourne le coefficient pour Y
{
	int w, h;
	
	ez_window_get_size (ev->win, &w, &h);
	
	Global_data *posY = ez_get_data(ev->win);
	
	if( posY->tmpy < w/8 )
		return -3.5 ;
	else if( posY->tmpy > h/8 && posY->tmpy < (2*h)/8 )
		return -2.5 ;
	else if( posY->tmpy > (2*h)/8 && posY->tmpy < (3*h)/8 )
		return -1.5 ;
	else if( posY->tmpy > (3*h)/8 && posY->tmpy < 4*h/8 )
		return -0.5 ;
	else if( posY->tmpy > 4*h/8 && posY->tmpy < 5*h/8 )
		return 0.5 ;
	else if( posY->tmpy > 5*h/8 && posY->tmpy < 6*h/8 )
		return 1.5 ;
	else if( posY->tmpy > 6*h/8 && posY->tmpy < 7*h/8 )
		return 2.5 ;
	else if( posY->tmpy > 7*h/8 )
		return 3.5 ;
	else
		return 0 ;
}



void mandel_zoom_expose(Ez_event *ev)
{
	int w, h, i, j ;
	Ez_uint8 r,g,b ;
	
	Global_data *m_zoom_expose = ez_get_data(ev->win) ;
	
	ez_window_get_size(ev->win, &w, &h);
	
	double x_min, x_max, y_min, y_max ;
	
	if(m_zoom_expose->enable_zoom_mandel == 1)
	{
		m_zoom_expose->zoom_fois = atoi(m_zoom_expose->fois_zoom);
	}
	else
		m_zoom_expose->zoom_fois = 1 ;
	
	
	x_min = (-1.85 / m_zoom_expose->zoom_fois) ;
	x_max = (2.4 / m_zoom_expose->zoom_fois) ;
	y_min = (-1.5 / m_zoom_expose->zoom_fois) ;
	y_max = (1.5 / m_zoom_expose->zoom_fois) ;
	
	m_zoom_expose->image_zoom = genererMandelbrot(w,h,x_min, x_max, y_min, y_max,m_zoom_expose);
	
	for(i=0 ; i < m_zoom_expose->image_zoom->largeur ; i++){
		for(j=0 ; j < m_zoom_expose->image_zoom->hauteur ; j++){
			
			r =  m_zoom_expose->image_zoom->tab[i][j].R ;
			g =  m_zoom_expose->image_zoom->tab[i][j].G ;
			b =  m_zoom_expose->image_zoom->tab[i][j].B ;
			
			ez_set_color (ez_get_RGB(r,g,b));
			
			ez_draw_point (ev->win, i, j);
		}
	}
	
	ez_set_color(ez_get_RGB(0,0,0));
	ez_fill_rectangle(ev->win, w/30-10, h-(40*h/41), w/30+50, h-(13*h/14)); // Retour
	ez_set_color(ez_get_RGB(255, 0, 0));
	ez_draw_rectangle(ev->win, w/30-10, h-(40*h/41), w/30+50, h-(13*h/14)); // Retour 
	ez_set_color(ez_white);
	ez_draw_text(ev->win, EZ_MC, w/30+20, h-(19*h/20), "Retour");
	
	ez_set_nfont (1);
	ez_draw_text(ev->win, EZ_BR, w,h, "Zoom : %d%%", (m_zoom_expose->zoom_fois)*100 ) ;
}


void mandel_zoom_on_window_close(Ez_event *ev)
{
	Global_data *zoom_close = ez_get_data(ev->win) ;
	
	(void)ev;
	
	ez_window_destroy(zoom_close->window_zoom_mandelbrot);
	zoom_close->enable_zoom_mandel = 0 ;
	zoom_close->window_zoom_mandelbrot = None ;
}

void mandel_zoom_event(Ez_event *ev)
{
	switch(ev->type)
	{
		case Expose : mandel_zoom_expose(ev); break ;
		case WindowClose : mandel_zoom_on_window_close(ev); break ;
	}
}

void zoom_sur_mandelbrot(Global_data *ZSM)
{
	
	
	if( ZSM->window_zoom_mandelbrot != None )
	{
		ez_window_destroy(ZSM->window_zoom_mandelbrot);
		ZSM->window_zoom_mandelbrot = ez_window_create( 700, 500, "Zoom", mandel_zoom_event);
	}
	else
		ZSM->window_zoom_mandelbrot = ez_window_create( 700, 500, "Zoom", mandel_zoom_event);
	
	ez_set_data(ZSM->window_zoom_mandelbrot, ZSM);
	ez_window_dbuf(ZSM->window_zoom_mandelbrot,1);
	ZSM->enable_zoom_mandel = 1 ;
	ez_auto_quit(0);
}
