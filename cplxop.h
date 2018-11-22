/*
**************************** 
* USED BY ANDRIAMAHALEO ALEX (C)
* VERSION BETA 1.0.0 GCC V0.8
* CPLXOP.H 2016
* UNIX UBUNTU 14.04 LTS
****************************
*/


#ifndef __CPLXOP__
#define __CPLXOP__

#include "cplx.h"
#include <stdlib.h>

/* Calcule la somme de deux complexes 
 * Allocation memoire d'un nouveau pointeur.
 * 
 * INPUT: pointeurs vers des complexes (operandes)
 * OUTPUT: pointeur sur resultat, un complexe.
 */
COMPLEXE * add_cplx (COMPLEXE*, COMPLEXE*);

/* Calcule la soustraction entre deux complexes z1-z2 
 * Allocation memoire d'un nouveau pointeur.
 * 
 * INPUT: pointeurs vers des complexes (operandes)
 *        entier, si 1 = moins unaire (oppose), si 2 = moins binaire 

 * OUTPUT: pointeur sur resultat, un complexe.
 */
COMPLEXE * moins_cplx (COMPLEXE*, COMPLEXE*,int);

/* Calcule la multiplication entre deux complexes 
 * Allocation memoire d'un nouveau pointeur.
 * 
 * INPUT: pointeurs vers des complexes (operandes)
 * OUTPUT: pointeur sur resultat, un complexe.
 */

COMPLEXE * mul_cplx (COMPLEXE*, COMPLEXE*);

/* Calcule le produit d'un complexe et d'un reel
 * Allocation memoire d'un nouveau pointeur.
 * 
 * INPUT: pointeur sur un complexe et un reel (operandes)
 * OUTPUT: pointeur sur resultat, un complexe.
 */
COMPLEXE * mul_cplx_reel (COMPLEXE*, double);


#endif
