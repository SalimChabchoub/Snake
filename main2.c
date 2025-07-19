#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h> 
#include "monde.h"
#include "graphe.h"




int main(void){
    initscr();
    srand(time(NULL));
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    curs_set(false);
    start_color();
    Monde mon  =monde_initialiser(10,30,6,3);
    interface_afficher_monde(mon);
    int cmp = 0 ;
    
    refresh();
    while(getch()!='\n');//premier clic sur entrer pour commencer le mouvement du serpent
    while (!monde_est_mort_serpent(mon)){
        

        monde_evoluer_serpent(&mon);
        interface_afficher_monde(mon);
        if (cmp > 100){
            mon.vitesse = 1 ;
            cmp=0;
        }
        usleep((int)(250000/ mon.vitesse));
        interface_piloter(&mon);
        cmp ++ ;
        refresh();
    }
    clear();
    interface_Game_Over(mon) ;
    usleep(3000000 ) ;
    endwin();

    
    return 0 ;  
}