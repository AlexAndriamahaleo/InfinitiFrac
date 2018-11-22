/*
****************************
* ANDRIAMAHALEO ALEX (C)
* VERSION BETA 1.1.0 GCC V0.8
* LISTEP_OP.C 2016
* UNIX UBUNTU 14.04 LTS
****************************
*/

#ifndef __LPOINTOP__
#define __LPOINTOP__

#include "listep.h"
#include <stdlib.h>
#include <stdio.h>

/*
 * A COMPLETER PAR D'AUTRES OPERATIONS ESTIMEES UTILES 
 */
  
/*
 * Initialisation avec un point
 * INPUT: coordonnees du point
 * OUTPUT: pointeur sur liste creee
 */
PLISTE init_liste(double xx, double yy);

/*
 * Insere un point apres element elt 
 * INPUT: ptr sur element avant insertion, coordonnees du nouveau point
 * OUTPUT: ptr sur element ajoute
 */
EPOINT * insert_after(EPOINT * elt, double xx, double yy);

/*
 * Supprime un point de la liste apres element elt 
 * INPUT: ptr sur element avant suppression
 * OUTPUT: ptr sur element courant avant suppression
 */
EPOINT * remove_after(EPOINT * elt);

/*
 * Lecture d'une liste de points depuis fichier de nom nf
 * On suppose un point par ligne, avec coordonnees separees par un
 * espace. 
 * INPUT: nom fichier
 * OUTPUT: liste de points lus sur le fichier en entree.
 */  
PLISTE lire_liste(char * nf);

/*
 * Ecriture fichier des points de la liste.
 * Un point par ligne, coordonnees separees par un espace, 
 * RC a la fin d'un point.
 * INPUT: nom fichier d'ecriture, liste a ecrire
 * OUTPUT: --
 */ 
void ecrire_liste(char * nf, PLISTE pl);

#endif
