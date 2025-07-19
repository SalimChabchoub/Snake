#ifndef MONDE_H
#define MONDE_H

#include "serpent.h"




typedef struct {
    int hauteur;
    int largeur;
    Serpent snake;
    Listpomme listpom;
    int nb_pomme;
    int vitesse ; // On a ajouté un champ pour vitesse pour faciliter l'option du vitesse

}Monde;




/*cette fonction initialise tout le jeu le quadrillage, le serpent ,le  nombre de pommes
et renvoie le monde qu'on vient d'initialiser avec tout les paramètres */
Monde monde_initialiser(int nb_lignes,int nb_colonnes, int taille_serpent, int nb_pommes);

/* cette fonction renvoie 1 si le serpent meurt quand il se déplace à
la case visée ça veut dire quand il sort du quadrillage ou ton sur une case de
son corps 0 sinon*/
int monde_est_mort_serpent(Monde mon);


/*cette fonction ajoute une pomme dans la listes des pommes du monde 
si les coordonnés de la pomme ne sont pas occupées par une autre pomme 
ou par le serpent elle prend en paramétre l'adresse du monde */
void monde_ajouter_pomme(Monde *m);



/*cette fonction gère le mouvement du serpent et agrandit le serpent si il 
mange une pomme et enlève la pomme mangé de la liste des pommes et ajoute
une nouvelle et elle modifier la vitesse aussi si il a mangé la bonne pomme*/
void monde_evoluer_serpent(Monde *mon);


#endif