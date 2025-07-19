#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "graphe.h"




void interface_afficher_quadriallage(Monde mon){
    int y_depart =(LINES-1)/2-mon.hauteur/2;
    int x_depart = (COLS-1)/2-mon.largeur/2;
    init_pair(1,COLOR_WHITE,COLOR_WHITE);
    for (int i=0;i<mon.hauteur;i++){
        for(int j=0;j<mon.largeur;j++){
            attron(COLOR_PAIR(1)); 
            mvaddch(y_depart+i,x_depart+j,' ');
            attroff(COLOR_PAIR(1));
        refresh();
            
        }
    }
}

void interface_afficher_pomme(Pomme pom)
{
    
    init_pair(6,COLOR_YELLOW,COLOR_YELLOW);
    int x_depart = pom.cord.x;
    int y_depart =  pom.cord.y;
    attron(COLOR_PAIR(6));
    mvprintw(y_depart,x_depart," ");
    attroff(COLOR_PAIR(6));
    refresh();

}


void interface_afficher_serpent(Serpent ser){
    init_pair(3,COLOR_GREEN,COLOR_WHITE);
    init_pair(4,COLOR_GREEN,COLOR_GREEN);
    attron(COLOR_PAIR(3));
    mvprintw(ser.corps->c.y ,ser.corps->c.x,"O");
    attroff(COLOR_PAIR(3));
    Casesnake temp = ser.corps->next;
    while(temp != NULL){
        attron(COLOR_PAIR(4));
        mvprintw(temp->c.y ,temp->c.x," ");
        attroff(COLOR_PAIR(4));
        temp=temp->next;
    }
    refresh();
}

void interface_afficher_monde(Monde mon){
    interface_afficher_quadriallage(mon);
    Listpomme tmp = mon.listpom;
    while (tmp!=NULL){
        if (tmp == mon.listpom){
            init_pair(5,COLOR_BLACK,COLOR_BLACK);
            int x_depart = tmp->p.cord.x;
            int y_depart =  tmp->p.cord.y;
            attron(COLOR_PAIR(5));
            mvprintw(y_depart,x_depart," ");
            attroff(COLOR_PAIR(5));
            refresh();

        }
        else if (tmp == mon.listpom->suivant){
            init_pair(2,COLOR_RED,COLOR_RED);
            int x_depart = tmp->p.cord.x;
            int y_depart =  tmp->p.cord.y;
            attron(COLOR_PAIR(2));
            mvprintw(y_depart,x_depart," ");
            attroff(COLOR_PAIR(2));
            refresh();

        }
        else {
        interface_afficher_pomme(tmp->p);
        
        }
        tmp =tmp->suivant;
    }
    interface_afficher_serpent(mon.snake);
    mvprintw((LINES-1)/2+mon.hauteur/2 +1,(COLS-1)/2+mon.largeur/2 -15 ,"Pomme mangées : %d",mon.nb_pomme);
    refresh();
}

void interface_piloter(Monde *mon){
    int touche ;

    touche = getch();
    if (touche=='z' && mon->snake.dir!=SUD )
        mon->snake.dir = NORD ;
        
    else if (touche=='s' && mon->snake.dir!=NORD)
        mon->snake.dir = SUD ;
        
    else if (touche=='q'&& mon->snake.dir!=EST)
        mon->snake.dir = OUEST;
        
    else if (touche=='d'&& mon->snake.dir!=OUEST)
        mon->snake.dir = EST ;
    else if (touche=='\n')
        while (getch()!='\n');
//     }
}

void interface_Game_Over(Monde mon){
    init_pair(4, COLOR_BLACK, COLOR_RED); 
    wbkgd(stdscr, COLOR_PAIR(4));// définition de la couleur d'arrière-plan de la fenêtre
    mvprintw((LINES-1)/2,(COLS-1)/2 - 7,"**** GAME OVER ****");
    mvprintw((LINES-1)/2 + 2 ,(COLS-1)/2,"SCORE : %d",mon.nb_pomme);
    refresh();
}