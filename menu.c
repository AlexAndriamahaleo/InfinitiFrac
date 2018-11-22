/*
****************************
* ANDRIAMAHALEO ALEX (C) EN COLLABORATION AVEC EL-YOUSFI AYOUB
* Programmation modulaire par ANDRIAMAHALEO ALEX
* VERSION 10.1.0 GCC V0.8
* MENU.C 2016
* UNIX UBUNTU 14.04 LTS
****************************
*/

#include "menu.h"



int menu_input (Ez_event *ev, char *s)
{

    Global_data *inp = ez_get_data(ev->win) ;


    int i ;
    int j = inp->k_count ;


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

      			if(j == 0)
            {
              strncpy (inp->longueur, s, BUF_MAX);
              strncpy(s,"",BUF_MAX);

              if(inp->k_flag_koch == TRUE)
              {
                menu_to_koch(ev);
                inp->k_enable_flocon = 1 ;
      	      }
              else
              		inp->k_count++ ;
            }

       			if(j == 1)
            {
              strncpy (inp->coorX, s, BUF_MAX);
              strncpy(s,"",BUF_MAX);

              if(inp->k_flag_koch == TRUE)
              {
                menu_to_koch(ev);
                inp->k_enable_flocon = 1 ;
    	        }
            	else
            		inp->k_count++ ;
           	}

      			if(j == 2)
            {
      				strncpy (inp->coorY, s, BUF_MAX);
              strncpy(s,"",BUF_MAX);

              if(inp->k_flag_koch == TRUE)
              {
      					menu_to_koch(ev);
      					inp->k_enable_flocon = 1 ;
              }
              else
              	inp->k_count++ ;
              }


              if(j == 3)
              {
                strncpy (inp->iteration, s, BUF_MAX);
                strncpy(s,"",BUF_MAX);

                menu_to_koch(ev);
                inp->k_enable_flocon = 1 ;

                return 2;

      			}

      			if(j == 4)
            {
      				strncpy (inp->menu_zoom, s, BUF_MAX);
              strncpy (s, "", BUF_MAX);

      				inp->k_count = -1;

      				return 2 ;
      			}
            return 1 ;

    		case XK_Escape:
    		case XK_R :
        case XK_r :
    			effacer(inp);
    			ez_window_destroy(inp->menu);
    			inp->menu = None ;
    			inp->k_enable_menu = 0 ;

    			break;

            default :
            	if (ev->key_count != 1) break;
                i = strlen (s);
                if (i >= BUF_MAX-1) break;
                s[i] = ev->key_string[0]; s[i+1] = 0;
                return 1;
      }
        return 0;
}

void menu_display (Ez_window win, Global_data *disp)
{
    int w, h ;

    ez_window_get_size(win, &w, &h) ;

    ez_set_color(ez_get_HSV(220,1,1));
    ez_fill_rectangle(win, 0, 0, w, h);


    ez_set_color(ez_black);
    ez_set_nfont (3);
    ez_draw_text(win, EZ_TC, w/2, h/30, "FRACTALE DE KOCH - PARAMETRES");

    ez_set_nfont (2);

    if(disp->k_flag_koch != TRUE)
       ez_draw_text (win, EZ_TL, w/30, h/4, "Cliquez sur un champ puis tapez vos parametres\nEnsuite tapez \"Entrer\" pour passer au parametre suivant");
    else
       ez_draw_text (win, EZ_TL, w/30, h/4, "Cliquez sur le parametre que vous souhaitez modifier\nPuis tapez \"Entrer\"");

     ez_set_nfont (1);

    //----------------------------INTERIEUR DU RECTANGLE---------------------------

    ez_set_color (ez_get_HSV(180,1,1));

    ez_fill_rectangle(win, w/30-10, h-(40*h/41), w/30+50, h-(13*h/14)); // Retour
    ez_fill_rectangle (win, w/30-10, h/2-25, w/30+150, h/2+25); // longueur
    ez_fill_rectangle(win, w/30-10, h/2+100, w/30+150, h/2+150); // Sauvegarde


    ez_fill_rectangle(win, w/2-80, h/2-65, w/2+80, h/2-20); // X
    ez_fill_rectangle(win, w/2-80, h/2+5, w/2+80, h/2+50); // Y
    ez_fill_rectangle(win, w/2-80, h/2+105, w/2+80, h/2+150); // Zoom


    ez_fill_rectangle(win, w-135, h/2-25, w-10, h/2+25); // iteration
    ez_fill_rectangle(win, w-135, h/2+100, w-10, h/2+150); // Effacer

    ez_fill_rectangle(win, w-75, h-(40*h/41), w-10, h-(13*h/14)); // Aide

    //----------------------------CONTOUR DU RECTANGLE---------------------------

    ez_set_color(ez_black);
    ez_set_thick(3);

    ez_draw_rectangle(win, w/30-10, h-(40*h/41), w/30+50, h-(13*h/14)); // Retour
    ez_draw_rectangle(win, w/30-10, h/2-25, w/30+150, h/2+25); // longueur
    ez_draw_rectangle(win, w/30-10, h/2+100, w/30+150, h/2+150); // Sauvegarde

    ez_draw_rectangle(win, w/2-80, h/2-65, w/2+80, h/2-20); // X
    ez_draw_rectangle(win, w/2-80, h/2+5, w/2+80, h/2+50); // Y
    ez_draw_rectangle(win, w/2-80, h/2+105, w/2+80, h/2+150); // Zoom

    ez_draw_rectangle(win, w-135, h/2-25, w-10, h/2+25); // iteration
    ez_draw_rectangle(win, w-135, h/2+100, w-10, h/2+150); // Effacer

    ez_draw_rectangle(win, w-75, h-(40*h/41), w-10, h-(13*h/14)); // Aide

    //---------------------------------------------------------------------------

    ez_set_thick(1);
    ez_set_color (ez_black);
    ez_set_nfont (1);


    ez_draw_text(win, EZ_MR, w-62, h/2+125, "Effacer");
    ez_draw_text(win, EZ_MC, w-40, h-(19*h/20), "Aide");
    ez_draw_text(win, EZ_MC, w/30+20, h-(19*h/20), "Retour");

    switch(disp->k_count){
    	case 0 :
    		ez_draw_text(win, EZ_ML, w/30, h/2, "Longueur : %s_", disp->setting);
    		ez_draw_text(win, EZ_TC, w/2, h/2-50, "Coordonee X : %s_", disp->coorX);
    		ez_draw_text(win, EZ_TC, w/2, h/2+20, "Coordonee Y : %s_", disp->coorY);
    		ez_draw_text(win, EZ_MR, w-20, h/2, "Iteration : %s_", disp->iteration);
    		ez_draw_text(win, EZ_ML, w/30+25, h/2+125, "Sauvegarde");
    		ez_draw_text(win, EZ_TC, w/2, h/2+120, "Zoom : %s_",disp->menu_zoom);
    		break ;
    	case 1 :
    		ez_draw_text(win, EZ_ML, w/30, h/2, "Longueur : %s_", disp->longueur);
    		ez_draw_text(win, EZ_TC, w/2, h/2-50, "Coordonee X : %s_", disp->setting);
    		ez_draw_text(win, EZ_TC, w/2, h/2+20, "Coordonee Y : %s_", disp->coorY);
    		ez_draw_text(win, EZ_MR, w-20, h/2, "Iteration : %s_", disp->iteration);
    		ez_draw_text(win, EZ_ML, w/30+25, h/2+125, "Sauvegarde");
    		ez_draw_text(win, EZ_TC, w/2, h/2+120, "Zoom : %s_",disp->menu_zoom);
    		break ;
    	case 2 :
    		ez_draw_text(win, EZ_ML, w/30, h/2, "Longueur : %s_", disp->longueur);
    		ez_draw_text(win, EZ_TC, w/2, h/2-50, "Coordonee X : %s_", disp->coorX);
    		ez_draw_text(win, EZ_TC, w/2, h/2+20, "Coordonee Y : %s_", disp->setting);
    		ez_draw_text(win, EZ_MR, w-20, h/2, "Iteration : %s_", disp->iteration);
    		ez_draw_text(win, EZ_ML, w/30+25, h/2+125, "Sauvegarde");
    		ez_draw_text(win, EZ_TC, w/2, h/2+120, "Zoom : %s_",disp->menu_zoom);
    		break ;
    	case 3 :
    		ez_draw_text(win, EZ_ML, w/30, h/2, "Longueur : %s_", disp->longueur);
    		ez_draw_text(win, EZ_TC, w/2, h/2-50, "Coordonee X : %s_", disp->coorX);
    		ez_draw_text(win, EZ_TC, w/2, h/2+20, "Coordonee Y : %s_", disp->coorY);
    		ez_draw_text(win, EZ_MR, w-20, h/2, "Iteration : %s_", disp->setting);
    		ez_draw_text(win, EZ_ML, w/30+25, h/2+125, "Sauvegarde");
    		ez_draw_text(win, EZ_TC, w/2, h/2+120, "Zoom : %s_",disp->menu_zoom);
    		break ;
    	case 4 :
			ez_draw_text(win, EZ_ML, w/30, h/2, "Longueur : %s_", disp->longueur);
    		ez_draw_text(win, EZ_TC, w/2, h/2-50, "Coordonee X : %s_", disp->coorX);
    		ez_draw_text(win, EZ_TC, w/2, h/2+20, "Coordonee Y : %s_", disp->coorY);
    		ez_draw_text(win, EZ_MR, w-20, h/2, "Iteration : %s_", disp->iteration);
    		ez_draw_text(win, EZ_ML, w/30+25, h/2+125, "Sauvegarde");
    		ez_draw_text(win, EZ_TC, w/2, h/2+120, "Zoom : %s_",disp->setting);
    		break ;
    	default :
    		ez_draw_text(win, EZ_ML, w/30, h/2, "Longueur : %s_", disp->longueur);
    		ez_draw_text(win, EZ_TC, w/2, h/2-50, "Coordonee X : %s_", disp->coorX);
    		ez_draw_text(win, EZ_TC, w/2, h/2+20, "Coordonee Y : %s_", disp->coorY);
    		ez_draw_text(win, EZ_MR, w-20, h/2, "Iteration : %s_", disp->iteration);
    		ez_draw_text(win, EZ_ML, w/30+25, h/2+125, "Sauvegarde");
    		ez_draw_text(win, EZ_TC, w/2, h/2+120, "Zoom : %s_",disp->menu_zoom);
    		break ;
    }

    ez_set_color(ez_black);
	ez_set_nfont (2);

	if(disp->k_sauvegarde == 0)
		ez_draw_text(win, EZ_ML, w/30, h/2+181, "Sauvegarde terminee\n%s",disp->BUF_nom_de_fichier_sauvegarde);


	if(disp->k_enable_help == 1)
    {
		disp->image_aide_koch = ez_image_load(disp->aide_koch);
		ez_image_paint(win,disp->image_aide_koch,0,0);
	}

    ez_set_nfont (0);
	ez_set_color (ez_black);
    ez_draw_text(win, EZ_BL, 1, h, "ANDRIAMAHALEO Alex (C) version 10.3.1");



}

void menu_on_expose (Ez_event *ev)
{
    Global_data *exp = ez_get_data(ev->win) ;

    menu_display (ev->win, exp);
}

void menu_on_key_press (Ez_event *ev)
{
    Global_data *key = ez_get_data(ev->win) ;

    int k = menu_input (ev, key->setting);
    if (k > 0)
    	ez_send_expose (ev->win);
}

void effacer(Global_data *m)
{
	m->k_flag_koch = FALSE ;
	m->k_sauvegarde = -1 ;
	strncpy(m->longueur,"",BUF_MAX);
	strncpy(m->coorX,"",BUF_MAX);
	strncpy(m->coorY,"",BUF_MAX);
	strncpy(m->iteration,"",BUF_MAX);
	strncpy(m->menu_zoom,"",BUF_MAX);
	strncpy(m->setting,"",BUF_MAX);

	if(m->k_enable_flocon == 1)
	{
		ez_window_destroy(m->window_flocon);
		m->window_flocon = None ;
		m->k_enable_flocon = 0 ;
	}

	if(m->k_enable_zoom == 1)
	{
		ez_window_destroy(m->window_zoom);
		m->window_zoom = None ;
		m->k_enable_zoom = 0 ;
	}
}

void menu_on_window_close (Ez_event *ev)
{
    Global_data *mw = ez_get_data(ev->win) ;
    effacer(mw);
    ez_window_destroy(ev->win);
    mw->menu = None ;
}

int menu_button(Ez_event *ev)
{
	int w, h ;

    Global_data *mb = ez_get_data(ev->win) ;

    ez_window_get_size(ev->win, &w, &h) ;



	if( ( (ev->mx > w/30-10) && (ev->mx < w/30+50) ) && ( (ev->my > h-(40*h/41)) && (ev->my < h-(13*h/14)) ) )
		return 1 ;

	if( ( (ev->mx > w/30-10) && (ev->mx < w/30+150)	) && ( (ev->my > h/2-25) && (ev->my < h/2+25) ) ) // LONGEUR
	{
		mb->k_sauvegarde = -1 ;
		mb->k_count = 0 ;
	}

	else if( ( (ev->mx > w/30-10) && (ev->mx < w/30+150)	) && ( (ev->my > h/2+100) && (ev->my < h/2+150) ) ) // SAUVEGARDE
	{
		if(mb->k_flag_koch == TRUE)
				mb->k_sauvegarde = ppm(w,h,255,mb->BUF_fichier_point,mb->BUF_nom_de_fichier_sauvegarde);
	}

	else if( ((ev->mx > w/2-80) && (ev->mx < w/2+80)) && ( (ev->my > h/2-65) && (ev->my < h/2-20))	) // COOR X
	{
		mb->k_sauvegarde = -1 ;
		mb->k_count = 1 ;
	}
	else if( ((ev->mx > w/2-80) && (ev->mx < w/2+80)) && ( (ev->my > h/2+5) && (ev->my < h/2+50) )	) // COOR Y
	{
		mb->k_sauvegarde = -1 ;
		mb->k_count = 2 ;
	}
	else if( ((ev->mx > w/2-80) && (ev->mx < w/2+80)) && ( (ev->my > h/2+105) && (ev->my < h/2+150) )	) // ZOOM
	{
		mb->k_count = 4 ;
	}

	else if( ( (ev->mx > w-135) && (ev->mx < w-10) ) && ( (ev->my > h/2-25) && (ev->my < h/2+25) ) ) // ITERATION
	{
		mb->k_sauvegarde = -1 ;
		mb->k_count = 3 ;
	}
	else if( ( (ev->mx > w-135) && (ev->mx < w-10) ) && ( (ev->my > h/2+100) && (ev->my < h/2+150) ) )
		effacer(mb);
	else if( ((ev->mx > w-75) && (ev->mx < w-10)) && (( ev->my > h-(40*h/41)) && (ev->my < h-(13*h/14)) ) ) // AIDE
	{
		mb->k_enable_help = 1 ;
	}
	else
	{
		mb->k_count = -1;
		mb->k_enable_help = 0 ;
	}


	return 0 ;
}

void menu_on_button_press (Ez_event *ev)
{
	int r ;

	r = menu_button(ev);

	if(r == 1)
		menu_on_window_close(ev);
	else
		ez_send_expose (ev->win);

}



void menu_event (Ez_event *ev)
{

    switch (ev->type) {
        case Expose   : menu_on_expose    (ev); break;
        case KeyPress : menu_on_key_press (ev); break;
        case ButtonPress : menu_on_button_press (ev); break ;
        case WindowClose : menu_on_window_close (ev); break;
    }
}

void global_init(Global_data *g)
{
	g->k_win_w = 700 ;
	g->k_win_h = 600 ;
	g->k_flag_koch = FALSE ;
	g->k_sauvegarde = -1 ;
	g->k_enable_flocon = 0 ;
	g->k_enable_zoom = 0 ;
	g->k_enable_menu = 0 ;
	g->window_flocon = None ;
	g->menu = None ;
	g->k_enable_help = 0 ;
	g->aide_koch = "images/Help/koch_help.png" ;

	g->show = 0 ;
	strncpy(g->setting,"",BUF_MAX);
	strncpy(g->longueur,"",BUF_MAX);
	strncpy(g->coorX,"",BUF_MAX);
	strncpy(g->coorY,"",BUF_MAX);
	strncpy(g->iteration,"",BUF_MAX);
	strncpy(g->menu_zoom,"",BUF_MAX);

	strncpy(g->fichier_point,"",BUF_MAX);
	strncpy(g->nom_de_fichier_sauvegarde,"",BUF_MAX);

	strncpy(g->BUF_fichier_point,"",BUF_MAX);
	strncpy(g->BUF_nom_de_fichier_sauvegarde,"",BUF_MAX);

	g->zoom_recup_percent = 100 ;
	g->zoom_dplt_h = 0 ;
	g->zoom_dplt_v = 0 ;

	g->window_mandelbrot = None ;
	g->window_zoom_mandelbrot = None ;
	g->enable_mandelbrot = 0 ;
	g->save_statut = 0 ;
	strncpy(g->fois_zoom,"1",BUF_MAX);
	strncpy(g->BUF_fois_zoom,"",BUF_MAX);
	g->mandel_flag_zoom = 0 ;
	g->enable_zoom_mandel = 0 ;
	g->zoom_fois = atoi(g->fois_zoom);

	g->window_julia = None ;
	g->menu_julia = None ;
	g->enable_julia = 0 ;
	strncpy(g->ConstX,"",BUF_MAX);
	strncpy(g->ConstY,"",BUF_MAX);
	strncpy(g->setting_xy,"",BUF_MAX);
	g->j_count = -1 ;
	g->j_enable_help = 0 ;
	g->aide_julia = "images/Help/julia_help.png" ;

}

void menu_koch(Global_data *global)
{

    global->menu = ez_window_create (global->k_win_w, global->k_win_h, "				FRACTALE DE KOCH - PARAMETRES", menu_event);

    ez_set_data(global->menu,global);

    ez_window_dbuf(global->menu, 1);

    ez_auto_quit (0);
}
