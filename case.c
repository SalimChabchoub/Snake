#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "case.h"


int identiques(Case c1, Case c2){
    if (c1.x==c2.x && c1.y==c2.y)
        return 1;
    return 0;
}

int hors_quadrillage(int nb_lignes,int nb_colonnes,Case c){
    if (c.x>=(COLS-1)/2+nb_colonnes/2 || c.x<=(COLS-1)/2-nb_colonnes/2-1 || c.y>=(LINES-1)/2 + nb_lignes/2 || c.y<=(LINES-1)/2- nb_lignes/2-1)
        return 1;
    return 0;
}