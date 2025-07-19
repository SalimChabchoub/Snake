
#ifndef SERPENT_H
#define SERPENT_H

#include "pomme.h"

typedef enum {
    NORD,
    SUD,
    EST,
    OUEST,
}Direction;

typedef struct Cellule {
    Case c;
    struct Cellule *next;
}Cellule,*Casesnake;

typedef struct{
    Direction dir;
    Casesnake corps;

}Serpent;

/* cette fonction initialise le serpent au milieu de la grille et son corps
 en fonction de sa taille et le renvoie*/
Serpent serpent_initialiser(int nb_lignes,int nb_colonnes, int taille);

/* cette fonction fait l'allocation pour construire le corps du serpent
qui est formé d'une liste de case elle renvoit une liste */
Casesnake alloue_corps(Case c);


/*cette fonction alloue une cellule à l'ajoute à la
fin de la liste*/
Casesnake push_back_list(Casesnake li , Case c);

/* cette fonction déplace le serpent à la case visé  et renvoie les coordonnées
de sa tete après le déplacement */
Case serpent_case_visee(Serpent serp);

#endif