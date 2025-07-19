#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <assert.h>
#include <time.h>
#include "monde.h"


Monde monde_initialiser(int nb_lignes,int nb_colonnes, int taille_serpent, int nb_pom){
    Monde monde;
    monde.largeur = nb_colonnes;
    monde.hauteur = nb_lignes;
    monde.nb_pomme =0;
    monde.vitesse = 1 ;
    monde.listpom=NULL;
    monde.snake = serpent_initialiser(nb_lignes,nb_colonnes,taille_serpent);
    for (int i=0;i<nb_pom;i++){
        monde_ajouter_pomme(&monde);
    }
    return monde;

}



int monde_est_mort_serpent(Monde mon){
    Case visee = serpent_case_visee(mon.snake);
    if (identiques(visee,mon.listpom->p.cord))
        return 1;
    Casesnake l = (mon.snake).corps;
    while ((l->next != NULL)){
            if (identiques(visee,l->c))
                return 1;
            l= l->next ;
    }
    return hors_quadrillage(mon.hauteur,mon.largeur,visee);

}


void monde_ajouter_pomme(Monde *m){
    
    int test ;
    do {
        test =1;
        Pomme p = pomme_aleatoire(m->hauteur,m->largeur); 
        Listpomme temp = m->listpom;
        if (temp!=NULL){ 
            while(temp->suivant!=NULL && test == 1){ // cette boucle c'est pour vérifier si la pomme existe déja !!
                if (identiques(p.cord,(m->listpom->p).cord))
                    test=0;
                temp = temp->suivant ;
            }
        }
        Cellule *l = (m->snake).corps;
        //cette boucle vérifier si la pomme n'apparait pas sur le serpent!!
        while ((l-> next != NULL)&& (test == 1)){
            if (identiques(p.cord,l->c))
                test =0;
            l= l-> next ;
        }
        if (test == 1){
            Listpomme tmp =NULL;
            tmp = alloue_pomme(p);
            if (m->listpom == NULL)
                m->listpom =tmp;
            else{
                tmp->suivant = m->listpom;
                m->listpom = tmp;
            }     
        }
    }while (test==0);
}


void monde_evoluer_serpent(Monde *mon){
    
    Case visee =serpent_case_visee(mon->snake);
    Casesnake tmp = mon->snake.corps->next;
    Case case_tmp1 =(mon->snake).corps->c;
    Case case_tmp2;
    mon->snake.corps->c = visee;
    
    while(tmp!=NULL){
        case_tmp2 = tmp->c;
        tmp ->c =case_tmp1;
        case_tmp1 = case_tmp2;
        tmp = tmp->next;
    }
    Casesnake l = mon->snake.corps;
    if (est_pomme(mon->listpom,visee)){
        push_back_list(l,case_tmp1);
        Listpomme pommier =mon->listpom;
        if (identiques(pommier->p.cord,visee)){
            
            mon->listpom = pommier->suivant ;
            pommier->suivant = NULL ;
            free (pommier); 
        }
        else {

            Listpomme pommier1 = mon->listpom ;
            
            while(!identiques(pommier->p.cord,visee)){
                if (pommier == mon->listpom->suivant){
                    mon->nb_pomme += 2 ;  // cette pomme qui va manger va lui rajouter 3 points
                    mon->vitesse ++ ; // en augmente la vitesse en double
                }
                pommier1 = pommier ;
                pommier =pommier->suivant;
            }

            pommier1->suivant = pommier->suivant ;
            pommier->suivant = NULL ;
            free(pommier);
        }
        monde_ajouter_pomme(mon);
        mon->nb_pomme++;


    }
}




