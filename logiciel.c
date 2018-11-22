/*
****************************
* ANDRIAMAHALEO ALEX (C) EN COLLABORATION AVEC EL-YOUSFI AYOUB
* Programmation modulaire par ANDRIAMAHALEO ALEX
* VERSION 10.3.1 GCC V0.8
* LOGICIEL.C 2016
* UNIX UBUNTU 14.04 LTS
* UPDATE ON LINUX MINT 18
* VERSION 11.0.0
****************************
*/

#include "logiciel.h"

int logiciel_input (Ez_event *ev, char *s)
{

    Global_data *loginp = ez_get_data(ev->win) ;


    int i ;

    switch (ev->key_sym) {

        case XK_BackSpace :
        	i = strlen (s);
            if (i == 0) break;
            s[i-1] = 0;
            return 1;

		case XK_Return :
		case XK_KP_Enter :
		case XK_Tab :
        case XK_space :

			strncpy (loginp->fois_zoom, s, BUF_MAX);
        	strncpy(s,"",BUF_MAX);
        	loginp->mandel_flag_zoom = -1 ;

        	return 2;

        default :
        	if (ev->key_count != 1) break;
            i = strlen (s);
            if (i >= BUF_MAX-1) break;
            s[i] = ev->key_string[0]; s[i+1] = 0;
            return 1;
    }
    return 0;
}

void logiciel_display(Ez_event *ev, Global_data *logdisp)
{
	int w, h ;

    ez_window_get_size(ev->win, &w, &h) ;

    ez_set_color(ez_get_RGB(47,79,79));
    ez_fill_rectangle(ev->win, 0, 0, w, h);

    ez_set_color(ez_black);
    ez_set_nfont (3);
    ez_draw_text(ev->win, EZ_TC, w/2, h/30, "LOGICIEL DE FRACTALE");

    ez_set_nfont (2);
    ez_draw_text (ev->win, EZ_TC, w/2, h/5, "Vous avez ici le choix entre 3 fractales\nCliquez sur l'une d'elle pour y acceder\nAmusez-vous bien avec nos fractales");

    ez_set_color(ez_get_RGB(0,139,139));
    ez_fill_rectangle (ev->win, w/30-8, h/2-50, w/30+190, h/2+50); // Koch
    ez_fill_rectangle(ev->win, w/2-120,  h/2-50, w/2+125, h/2+50); // Mandelbrot
    ez_fill_rectangle(ev->win, w-210,  h/2-50, w-10, h/2+50); // Julia
    ez_fill_rectangle(ev->win, w-150, h-(h/5), w-10, h-(h/9)); // Quitter

    ez_set_color(ez_black);
    ez_set_thick(3);
    ez_draw_rectangle (ev->win, w/30-8, h/2-50, w/30+190, h/2+50); // Koch
    ez_draw_rectangle(ev->win, w/2-120,  h/2-50, w/2+125, h/2+50); // Mandelbrot
    ez_draw_rectangle(ev->win, w-210,  h/2-50, w-10, h/2+50); // Julia
    ez_draw_rectangle(ev->win, w-150, h-(h/5), w-10, h-(h/9)); // Quitter


    ez_set_thick(2);
    ez_draw_text(ev->win, EZ_MC, w/30+90, h/2, "Von Koch\n(Courbe de)");
    ez_draw_text(ev->win, EZ_MC, w/2, h/2, "Mandelbrot\n(Ensemble de)");
    ez_draw_text(ev->win, EZ_MC, w-110, h/2, "Julia\n(Ensemble de)");
    ez_draw_text(ev->win, EZ_MC, w-80, h-(h/6.5), "Quitter");

    if(logdisp->enable_mandelbrot == 1)
    {
		switch(logdisp->mandel_flag_zoom)
		{
			case 1 :
					ez_set_color(ez_get_RGB(0,139,139));
					ez_fill_rectangle(ev->win, w/2-120, h/2+60, w/2+125, h/2+100); // Zoom
					ez_set_color(ez_black);
					ez_set_thick(3);
					ez_draw_rectangle(ev->win, w/2-120, h/2+60, w/2+125, h/2+100); // Zoom
					ez_set_thick(2);
					ez_draw_text(ev->win, EZ_TC, w/2, h/2+70, "Mandelbrot Zoom : x%d", atoi(logdisp->BUF_fois_zoom));
					break ;

			default :
					ez_set_color(ez_get_RGB(0,139,139));
					ez_fill_rectangle(ev->win, w/2-120, h/2+60, w/2+125, h/2+100); // Zoom
					ez_set_color(ez_black);
					ez_set_thick(3);
					ez_draw_rectangle(ev->win, w/2-120, h/2+60, w/2+125, h/2+100); // Zoom
					ez_set_thick(2);
					ez_draw_text(ev->win, EZ_TC, w/2, h/2+70, "Mandelbrot Zoom : x%d", atoi(logdisp->fois_zoom));
					break ;
		}

	}


    ez_set_nfont (0);
	ez_set_color (ez_black);
    ez_draw_text(ev->win, EZ_BL, 1, h, "ANDRIAMAHALEO Alex (C) stable version 11.0.0 (before 10.3.1) avec la collaboration d' EL YOUSFI Ayoub");
}

void logiciel_on_expose(Ez_event *ev)
{
	Global_data *lexp = ez_get_data(ev->win) ;
    logiciel_display(ev,lexp);
}

void logiciel_on_button_press(Ez_event *ev)
{
	int w, h ;

    Global_data *lbp = ez_get_data(ev->win) ;

    ez_window_get_size(ev->win, &w, &h) ;


	if( ( (ev->my > h/2-50) && (ev->my < h/2+50) ) && ( (ev->mx > w/30-8) && (ev->mx < w/30+190) ) )
	{
		if(lbp->menu != None)
		{
			ez_window_destroy(lbp->menu);
			effacer(lbp);
			menu_koch(lbp) ;
			lbp->k_enable_menu = 1 ;
			ez_send_expose(ev->win);
		}
		else
		{
			menu_koch(lbp) ;
			lbp->k_enable_menu = 1 ;
			ez_send_expose(ev->win);
		}
	}
	if( ( (ev->my > h/2-50) && (ev->my < h/2+50) ) && ( (ev->mx > w/2-120) && (ev->mx < w/2+125) ) )
	{
		mandelbrot_image(lbp);
		ez_send_expose(ev->win);
	}
	if( ( ( (ev->my > h/2+60) && (ev->my < h/2+100) ) && ( (ev->mx > w/2-120) && (ev->mx < w/2+125) ) ) && (lbp->enable_mandelbrot == 1) )
	{
		lbp->mandel_flag_zoom = 1 ;
	}
	if( ( (ev->my > h/2-50) && (ev->my < h/2+50) ) && ( (ev->mx > w-210) && (ev->mx < w-10) ) )
	{
		ez_send_expose(ev->win);
		menu_julia(lbp);
	}
	if( ( (ev->my > h-(h/5)) && (ev->my < h-(h/9)) ) && ( (ev->mx > w-150) && (ev->mx < w-10) ) )
	{
		logiciel_on_window_close (ev);
	}
}

void logiciel_on_key_press (Ez_event *ev)
{
	int w, h ;

    ez_window_get_size(ev->win, &w, &h) ;

    Global_data *key = ez_get_data(ev->win) ;

    int k = logiciel_input (ev, key->BUF_fois_zoom);
    if (k > 0)
		ez_send_expose (ev->win);
}

void logiciel_on_window_close (Ez_event *ev)
{
	(void)ev;
    ez_quit ();
}

void logiciel_event (Ez_event *ev)
{

    switch (ev->type) {
        case Expose   : logiciel_on_expose    (ev); break;
        case KeyPress : logiciel_on_key_press (ev); break;
        case ButtonPress : logiciel_on_button_press (ev); break ;
        case WindowClose : logiciel_on_window_close (ev); break;
    }
}

int main()
{
	Global_data logi ;

	global_init(&logi);

	if (ez_init() < 0) exit(1);

	logi.logiciel = ez_window_create(700,600,"Logiciel de generation de Fractale", logiciel_event);

	ez_set_data(logi.logiciel,&logi);
	ez_window_dbuf(logi.logiciel, 1);

	ez_auto_quit (0);

	ez_main_loop();

	exit(0) ;
}
