#ifndef POMME_H
#define POMME_H

#include "case.h"
#include "serpent.h"



typedef struct {
    Case cord;
}Pomme;

typedef struct Cel{
    Pomme p;
    struct Cel *suivant;
}Cel,*Listpomme;


/* cette fonction fait l'allocation de la liste des pommes à partir d'une
 pomme passé en paramètre elle renvoie la liste chainé des pommes  */
Listpomme alloue_pomme(Pomme p);


/*Cette fonction prend la longueur et la largeur du quadrillage et 
renvoie les coordonnées aléatoire d'une pomme de type Pomme */
Pomme pomme_aleatoire(int nb_lignes, int nb_colonnes);



/*si la case contient une poomme on renvoie 1 sinon 0 */
int est_pomme(Listpomme pommier,Case c);

#endif
