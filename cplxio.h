/*
**************************** 
* USED BY ANDRIAMAHALEO ALEX (C)
* VERSION BETA 1.0.0 GCC V0.8
* CPLXIO.H 2016
* UNIX UBUNTU 14.04 LTS
****************************
*/


#ifndef __CPLXIO__
#define __CPLXIO__

#include "cplx.h"
#include <stdio.h>
#include <stdlib.h>
#include "util.h"

/*
 * Cree un complexe a partir de deux reels.
 * 
 * INPUT: reel partie reelle, reel partie imaginaire
 * OUTPUT: pointeur sur struct Complexe, allocation memoire dans la 
 * fonction
 */ 
COMPLEXE * create_complexe(double r, double i);

/* Le format est la lecture de deux reels de type long, separes
 * par un espace (partie reelle suivie de partie imaginaire).
 * La fonction renvoit un pointeur vers le complexe nouvellement lu.
 * L'affectation memoire se fait dans la fonction.
 *
 * INPUT: --
 * OUTPUT: pointeur sur nouvelle structure de complexe
 * 
 */

COMPLEXE * lire_complexe(void);

/* Ecrit le complexe sans le i, comme deux coordonnees separees par un
 * espace. 
 * Le format est le meme que pour la lecture (partie reelle puis 
 * imaginaire). 
 * 
 * INPUT: pointeur sur un element de structure de complexe.
 * OUTPUT: --
 * 
 */

void ecrire_complexe (COMPLEXE *);

void clean_stdin(void);
#endif
