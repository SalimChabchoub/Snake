#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <assert.h>
#include <time.h>
#include "serpent.h"



Casesnake alloue_corps(Case cas){
    Cellule * l = malloc(sizeof(Cellule));
    assert(l!= NULL);
    l->c = cas;
    l->next =NULL;
    return l;
}


Casesnake push_back_list(Casesnake li , Case c)
{
    Casesnake  element= alloue_corps(c);
    if (li== NULL)
        return  element ;
    Casesnake temp ;
    temp = li ;
    while (temp->next != NULL )
        temp = temp->next;
    temp->next = element ;
    return li ;
}

Serpent serpent_initialiser(int nb_lignes,int nb_colonnes, int taille){
    Case c;
    Serpent snake;
    snake.corps=NULL;
    c.y = nb_lignes/2 +(LINES-1)/2- nb_lignes/2;
    c.x = nb_colonnes/2+(COLS-1)/2-nb_colonnes/2;
    snake.corps=alloue_corps(c);
    for (int i=1;i<taille;i++){
        c.x -- ;
        snake.corps = push_back_list(snake.corps,c);
    }
    snake.dir = EST;
    return snake;
}


Case serpent_case_visee(Serpent serp){
    Case visee;
    if (serp.dir ==NORD){
        visee.x=((serp.corps)->c).x;
        visee.y=((serp.corps)->c).y - 1; 

    }
    else if (serp.dir == SUD){
        visee.x=((serp.corps)->c).x;
        visee.y=((serp.corps)->c).y + 1; 

    }
    else if (serp.dir ==EST){
        visee.x=((serp.corps)->c).x + 1;
        visee.y=((serp.corps)->c).y; 

    }
    else {
        visee.x=((serp.corps)->c).x - 1;
        visee.y=((serp.corps)->c).y; 

    }
    return visee;
}
