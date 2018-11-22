/*
****************************
* ANDRIAMAHALEO ALEX (C) EN COLLABORATION AVEC EL-YOUSFI AYOUB
* Programmation modulaire par ANDRIAMAHALEO ALEX
* VERSION 10.1.0 GCC V0.8
* MENU_JULIA.C 2016
* UNIX UBUNTU 14.04 LTS
****************************
*/

#include "menu_julia.h"



int menu_julia_input (Ez_event *ev, char *s)
{
    Global_data *julia_input = ez_get_data(ev->win) ;

    int i ;
    int j = julia_input->j_count ;

    switch (ev->key_sym)
    {
		case XK_BackSpace :
        	i = strlen (s);
            if (i == 0) break;
            s[i-1] = 0;
            return 1;

		case XK_Return :
		case XK_KP_Enter :
		case XK_Tab :
        case XK_space :

			if(j==0)
			{
				strncpy(julia_input->ConstX,s,BUF_MAX);
				strncpy(s,"",BUF_MAX);

				if(julia_input->j_flag_julia == TRUE)
				{
					julia_image(julia_input);
					julia_input->enable_julia = 1 ;
					julia_input->j_count = -1 ;
				}
				else
					julia_input->j_count++ ;
			}

			if(j==1)
			{
				strncpy(julia_input->ConstY,s,BUF_MAX);
				strncpy(s,"",BUF_MAX);

				julia_image(julia_input);
				julia_input->enable_julia = 1 ;
				julia_input->j_count = -1 ;
				julia_input->j_flag_julia = TRUE ;

				return 2 ;
			}

			if(julia_input->enable_julia == 0 && j == -1)
			{
				julia_image(julia_input);
				julia_input->enable_julia = 1 ;
				return 2 ;
			}

			return 1 ;

		default :
        	if (ev->key_count != 1) break;
            i = strlen (s);
            if (i >= BUF_MAX-1) break;
            s[i] = ev->key_string[0]; s[i+1] = 0;
            return 1 ;
	}

    return 0;
}

void menu_julia_display (Ez_window win, Global_data *julia_disp)
{
	int w, h ;

    ez_window_get_size(win, &w, &h) ;

    ez_set_color(ez_get_RGB(255,192,203));
    ez_fill_rectangle(win, 0, 0, w, h);


    ez_set_color(ez_black);
    ez_set_nfont (3);
    ez_draw_text(win, EZ_TC, w/2, h/30, "FRACTALE DE JULIA - PARAMETRES");

    ez_set_nfont (2);

    if(julia_disp->j_flag_julia == TRUE)
		ez_draw_text (win, EZ_TL, w/30, h/4, "Cliquez sur le parametre que vous souhaitez modifier\nPuis tapez \"Entrer\"\nOu\nTapez \"Entrer\" pour re-afficher votre fractale");
	else
		ez_draw_text (win, EZ_TL, w/30, h/4, "Cliquez sur le premier champ puis tapez vos parametres\nEnsuite tapez \"Entrer\" pour passer au parametre suivant");

	ez_set_nfont (1);

	//----------------------------INTERIEUR DU RECTANGLE---------------------------

	ez_set_color(ez_get_RGB(255,20,147));

	ez_fill_rectangle(win, w/30-10, h-(40*h/41), w/30+50, h-(13*h/14)); // Retour
	ez_fill_rectangle(win,w/8-20, h/2-35, 3.5*w/8, h/2+35); // Re
	ez_fill_rectangle(win,4.5*w/8,h/2-35,7.2*w/8,h/2+35); // Im
	ez_fill_rectangle(win, w-75, h-(40*h/41), w-10, h-(13*h/14)); // Aide

	//----------------------------CONTOUR DU RECTANGLE---------------------------

	ez_set_color(ez_black);
    ez_set_thick(3);

    ez_draw_rectangle(win, w/30-10, h-(40*h/41), w/30+50, h-(13*h/14)); // Retour
    ez_draw_rectangle(win,w/8-20, h/2-35, 3.5*w/8, h/2+35);
	ez_draw_rectangle(win,4.5*w/8,h/2-35,7.2*w/8,h/2+35);
	 ez_draw_rectangle(win, w-75, h-(40*h/41), w-10, h-(13*h/14)); // Aide

	//---------------------------------------------------------------------------

	ez_set_thick(1);
    ez_set_color (ez_black);
    ez_set_nfont (1);

    ez_draw_text(win, EZ_MC, w-40, h-(19*h/20), "Aide");
    ez_draw_text(win, EZ_MC, w/30+20, h-(19*h/20), "Retour");


    switch(julia_disp->j_count)
    {
		case 0 :
			ez_draw_text(win,EZ_ML, w/8, h/2, "Partie Reelle : %s_", julia_disp->setting_xy );
			ez_draw_text(win,EZ_ML, (4.5*w/8)+20, h/2, "Partie Imaginaire : %s_", julia_disp->ConstY);
			break ;
		case 1 :
			ez_draw_text(win,EZ_ML, w/8, h/2, "Partie Reelle : %s_", julia_disp->ConstX );
			ez_draw_text(win,EZ_ML, (4.5*w/8)+20, h/2, "Partie Imaginaire : %s_", julia_disp->setting_xy);
			break ;
		default :
			ez_draw_text(win,EZ_ML, w/8, h/2, "Partie Reelle : %s_", julia_disp->ConstX );
			ez_draw_text(win,EZ_ML, (4.5*w/8)+20, h/2, "Partie Imaginaire : %s_", julia_disp->ConstY);
			break ;

	}

     if(julia_disp->j_enable_help == 1)
    {
		julia_disp->image_aide_julia = ez_image_load(julia_disp->aide_julia);
		ez_image_paint(win,julia_disp->image_aide_julia,0,0);
	}

    ez_set_nfont (0);
	ez_set_color (ez_black);
    ez_draw_text(win, EZ_BL, 1, h, "ANDRIAMAHALEO Alex (C) version 10.3.1");

}

void menu_julia_on_expose (Ez_event *ev)
{
    Global_data *julia_exp = ez_get_data(ev->win) ;

    menu_julia_display (ev->win, julia_exp);
}

void menu_julia_on_key_press (Ez_event *ev)
{
    Global_data *julia_key = ez_get_data(ev->win) ;

    int k = menu_julia_input (ev, julia_key->setting_xy);

    if(k > 0)
        ez_send_expose (ev->win);
}

void effacer_julia(Global_data *j)
{
	j->j_flag_julia = FALSE ;
	strncpy(j->ConstX,"",BUF_MAX);
	strncpy(j->ConstY,"",BUF_MAX);
	strncpy(j->setting_xy,"",BUF_MAX);

	if(j->enable_julia == 1)
	{
		ez_window_destroy(j->window_julia);
		j->window_julia = None ;
		j->enable_julia = 0 ;
	}
}

void menu_julia_on_window_close (Ez_event *ev)
{
    Global_data *jw = ez_get_data(ev->win) ;
    effacer_julia(jw);
    ez_window_destroy(ev->win);
    jw->menu_julia = None ;
}

int menu_julia_button(Ez_event *ev)
{
	int w, h ;

	Global_data *jb = ez_get_data(ev->win) ;

    ez_window_get_size(ev->win, &w, &h) ;

    if( (ev->mx > w/30-10) && (ev->mx < w/30+50) )
		if( (ev->my > h-(40*h/41)) && (ev->my < h-(13*h/14)) )
		{
			return 1 ;
		}

	if( ((ev->mx > w/8-20) && (ev->mx < 3.5*w/8)) && ((ev->my > h/2-35) && (ev->my < h/2+35)) )
	{
		jb->j_count = 0 ; // si modif RE
	}
	else if( (ev->mx > 4.5*w/8) && (ev->mx < 7.2*w/8) && (ev->my > h/2-35) && (ev->my < h/2+35) )
		jb->j_count = 1 ; // si modif IM
	else if( ((ev->mx > w-75) && (ev->mx < w-10)) && (( ev->my > h-(40*h/41)) && (ev->my < h-(13*h/14)) ) )
	{
		jb->j_enable_help = 1 ;
	}
	else
	{
		jb->j_count = -1 ; // default
		jb->j_enable_help = 0 ;
	}
	return 0 ;
}

void menu_julia_on_button_press (Ez_event *ev)
{
	int r ;

	r = menu_julia_button(ev);

	if(r == 1)
		menu_julia_on_window_close(ev);
	else
		ez_send_expose (ev->win);

}

void menu_julia_event (Ez_event *ev)
{

    switch (ev->type) {
        case Expose   : menu_julia_on_expose    (ev); break;
        case KeyPress : menu_julia_on_key_press (ev); break;
        case ButtonPress : menu_julia_on_button_press (ev); break ;
        case WindowClose : menu_julia_on_window_close (ev); break;
    }
}

void menu_julia(Global_data *parametre)
{
    if(parametre->menu_julia != None)
    {
		ez_window_destroy(parametre->menu_julia) ;
	    parametre->menu_julia = ez_window_create (parametre->k_win_w, parametre->k_win_h, "				FRACTALE DE JULIA - PARAMETRES", menu_julia_event);
	}
	else
		parametre->menu_julia = ez_window_create (parametre->k_win_w, parametre->k_win_h, "				FRACTALE DE JULIA - PARAMETRES", menu_julia_event);

    ez_set_data(parametre->menu_julia,parametre);
    ez_window_dbuf(parametre->menu_julia, 1);
    ez_auto_quit (0);
}
