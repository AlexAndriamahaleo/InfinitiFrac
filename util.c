

#include "util.h"

/* Vide l'entree standard (utile avant de lire la reponse
 * a une question dans un menu, par exemple)
 *
 * INPUT: --
 * OUTPUT: --
 * 
 */

void clean_stdin(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

