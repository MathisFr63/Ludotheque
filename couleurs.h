#ifndef COULEURS
#define COULEURS

#include <stdio.h>

#define couleur(param) printf("\033[%sm",param)

#define clrscr() printf("\033[H\033[2J")

#endif