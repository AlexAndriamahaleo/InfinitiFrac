/*
**************************** 
* ANDRIAMAHALEO ALEX (C) EN COLLABORATION AVEC EL-YOUSFI AYOUB
* Programmation modulaire par ANDRIAMAHALEO ALEX
* VERSION 10.1.0 GCC V0.8
* GLOBAL_DATA.H 2016
* UNIX UBUNTU 14.04 LTS
****************************
*/


#ifndef __GLOBAL_DATA__
#define __GLOBAL_DATA__

#include "ez-draw.h"
#include "ez-image.h"
#include "define.h"
#include "image_op.h"
#include "cplxio.h"
#include "cplxop.h"
#include "pixel_op.h"
#include "pixel_type.h"
#include "image_type.h"
#include "image_op.h"

typedef struct{
	
	//------------------------------KOCH DATA-------------------------------
	
	int 	k_win_w ; // 700
	int 	k_win_h ; // 600
	double 	k_longueur ;
	double 	k_x ;
	double 	k_y ;
	int 	k_n ;
	int 	k_count ;
	int 	k_flag_koch ; // = FALSE
	int 	k_sauvegarde ; // = -1
	int 	k_animation ;
	int		k_enable_flocon ;
	int 	k_enable_zoom ;
	int 	k_enable_menu ;
	Ez_window window_flocon ; // = None
	Ez_window menu ;
	int		k_enable_help ;
	Ez_image *image_aide_koch ;
	char 	*aide_koch ;
	
	//----------------------------------------------------------------------
	
	//------------------------------KOCH GLOBAL-----------------------------
	
	int 	show ; // = 0
	char 	setting[BUF_MAX] ; // 
	char 	longueur[BUF_MAX] ;// 
	char 	coorX[BUF_MAX] ;// 		=	""
	char 	coorY[BUF_MAX] ;// 
	char 	iteration[BUF_MAX] ;// 
	char 	menu_zoom[BUF_MAX] ;// 
	
	char 	fichier_point[BUF_MAX] ;//
	char 	nom_de_fichier_sauvegarde[BUF_MAX] ;// 		=	""
	
	char 	BUF_fichier_point[BUF_MAX] ;// 		=	""
	char 	BUF_nom_de_fichier_sauvegarde[BUF_MAX] ;//
	
	
	//----------------------------------------------------------------------
	
	//------------------------------ZOOM DATA-------------------------------
	
	int zoom_x;  int zoom_y;		// Coordonnees de la souris lors du clic
	int w;  int h;		// Longueur et largeur de la fenetre du flocon
	int zoom_wz; int zoom_hz;		// Longueur et largeur de la fenetre du zoom 
	double zoom_percent;		// Pourcentage du zoom
	Ez_window window_zoom ;
	int zoom_win_w ;
	int zoom_win_h ;
	int zoom_FLAG_WIN ;
	
	//----------------------------------------------------------------------
	
	//------------------------------ZOOM GLOBAL-----------------------------
	
	int    zoom_p ;
	int    zoom_mx, zoom_my;			// Coordonnees de la souris lors du clic
	double zoom_recup_percent ; // = 100
	double zoom_dplt_h ; // = 0
	double zoom_dplt_v ; // = 0
	
	//----------------------------------------------------------------------
	
	//----------------------------MANDELBROT--------------------------------
	
	Ez_window window_mandelbrot ; // = None
	Ez_window window_zoom_mandelbrot ;
	int		enable_mandelbrot ;	// = 0
	int 	enable_zoom_mandel ;
	IMAGE 	*mandelbrot ;
	IMAGE	*image_zoom ;
	
	int		zoom_fois ; 
	char	save_image[BUF_MAX] ;
	char 	fois_zoom[BUF_MAX] ; // pas oublier de changer
	char	BUF_fois_zoom[BUF_MAX] ;
	int		mandel_flag_zoom ; // = 0
	int 	zoom_key_press ;
	int		mandel_mx, mandel_my ;
	double 	tmpx, tmpy ;
	double	axeX, axeY ;
	COMPLEXE *mouse ;
	
	//----------------------------------------------------------------------
	
	//---------------------------------JULIA--------------------------------
	
	Ez_window window_julia ; // = None
	Ez_window menu_julia ; // = None
	char 	ConstX[BUF_MAX] ; // = ""
	char 	ConstY[BUF_MAX] ; // = ""
	char	setting_xy[BUF_MAX] ;
	int 	enable_julia ; // = 0
	int		j_flag_julia ;	
	int 	j_count ;
	char 	save_julia[BUF_MAX];
	IMAGE 	*julia ;
	Ez_image*image_aide_julia ;
	char 	*aide_julia ;
	int		j_enable_help ;
	
	
	//----------------------------------------------------------------------
	
	//---------------------------MANDELBROT & JULIA-------------------------
	
	
	char 	sauvegarde_manju[BUF_MAX] ;// 		=	""
	char 	BUF_sauvegarde_manju[BUF_MAX] ;//		=	""
	int		save_statut ;
	
	//----------------------------------------------------------------------
	
	//------------------------------LOGICIEL--------------------------------
	
	Ez_window logiciel ;
	
	//----------------------------------------------------------------------
	
} Global_data;

#endif
