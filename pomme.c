#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <assert.h>
#include <time.h>
#include "pomme.h"


Pomme pomme_aleatoire(int nb_lignes,int nb_colonnes){
    Pomme p;
    
    (p.cord).x = rand() % (nb_colonnes) + (COLS-1)/2-nb_colonnes/2 ;
    (p.cord).y = rand() % (nb_lignes) +(LINES-1)/2-nb_lignes/2;
    
    return p;
}

Listpomme alloue_pomme(Pomme p){
    Listpomme l = malloc(sizeof(Cel));
    assert(l!= NULL);
    l->p = p;
    l->suivant =NULL;
    return l;
}


int est_pomme(Listpomme pommier,Case c){
    Listpomme tmp = pommier;
    while(tmp!= NULL){
        if (identiques(tmp->p.cord,c))
            return 1;
        tmp = tmp->suivant;
    }
    return 0;
}
