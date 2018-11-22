/*
**************************** 
* ANDRIAMAHALEO ALEX (C) EN COLLABORATION AVEC EL-YOUSFI AYOUB
* VERSION 2.2.1 GCC V0.8
* PPM.C 2016
* UNIX UBUNTU 14.04 LTS
****************************
*/

#include "ppm.h"



void draw_ligne(int x1, int y2, int x2)
{
	int x ;
	for(x=x1 ; x <= x2 ; x++){
		tab_ppm[y2][x] = 1 ;
	}
}


void Bresenham(int x1, int y1, int x2, int y2)
{
	int y ;
	int x ;
	
	int dx = x2 - x1 ;
	int dy = y2 - y1 ;
	
	int IncX, IncY ;
	
	//---------- CAS PARTICULIERS  -------------//
	if( dx > 0 && dy == 0){
		draw_ligne(x1,y2,x2);
	}
	
	if( dx < 0 && dy == 0){
		draw_ligne(x2,y2,x1);
	}
	//--------------------------------------------//
	
	
	//---------- CALCUL DES OCTANTS  -------------//
	
	if(dx > 0){
		IncX = 1 ;
	}
	
	// dx < 0
	else{
		IncX = -1 ;
		dx = -dx ;
	}
	
	if(dy > 0){
		IncY = 1 ;
	}
	
	// dy < 0
	else{
		IncY = -1 ;
		dy = -dy ;
	}
	
	//--------------------------------------------//
	
	
	
	if(dx > dy){
		int incrE = 2*dy ;
		int incrNE = 2*(dy-dx) ;
	
		int e = 2*dy - dx ;
		
		x = x1 ;
		y = y1 ;
	
		while(x != x2 && y != y2){
			tab_ppm[y][x] = 1 ;
		
			if( e > 0 ){
				y += IncY ;
				e += incrNE ;
				x += IncX ;
			}
			else{
				e += incrE ;
				y += IncY ;
			}
		}
	}
	
	// dx < dy
	
	else{
		
		int incrE = 2*dx ;
		int incrNE = 2*(dx-dy) ;
	
		int e = 2*dx - dy ;
		
		x = x1 ;
		y = y1 ;
	
		while(x != x2 && y != y2){
			tab_ppm[y][x] = 1 ;
		
			if( e > 0 ){
				y += IncY ;
				e += incrNE ;
				x += IncX ;
			}
			else{
				y += IncY ;
				e += incrE ;
			}
		}
	}
	
}


int ppm(int width, int height, int color_max, char *fp, char *nfs)
{
	
	int i, j, q, s ;
	int a, b, c, d ;
	
	int aa, bb, cc, dd ;
	
	for(q=0; q<height ; q++){
		for(s=0 ; s<width ; s++){
			tab_ppm[q][s] = 0 ;
		}
	}
	
	PLISTE ppm = lire_liste(fp);
	PLISTE tmp = ppm->next ;
	
	PLISTE init = ppm ;
	
	while(ppm != NULL && tmp != NULL){
		
		a = (int) ppm->x ;
		b = (int) ppm->y ;
		
		c = (int) tmp->x;
		d = (int) tmp->y;
		
		Bresenham(a,b,c,d);
		
		
		ppm = ppm->next ;
		tmp = ppm->next ;
		
	}
	
	
	aa = (int) init->x ;
	bb = (int) init->y ;
	
	cc = (int) ppm->x ;
	dd = (int) ppm->y ;
	
	Bresenham(cc,dd,aa,bb);
	
	
	char *nf = nfs ;
	
	FILE* f = fopen(nf,"w");
	
	fprintf(f,"P3\n");
	fprintf(f,"# format de l'image\n");
	fprintf(f,"%d %d\n", width, height);
	
	fprintf(f,"# val color max\n");
	fprintf(f,"%d", color_max);
	
	for(i=0 ; i < height ; i++){ 
		fprintf(f,"\n");
		
		for(j=0 ; j < width ; j++){ 
			if(tab_ppm[i][j] != 0)
				fprintf(f,"%d %d %d ", 0, 0, 0); 
			else
				fprintf(f,"%d %d %d ", color_max, color_max, color_max);
		}
	}
	
	
	return 0 ;
}	

