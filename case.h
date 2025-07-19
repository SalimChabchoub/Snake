#ifndef CASE_H
#define CASE_H

typedef struct {
    int x;
    int y;
}Case;



/* cette fonction compare entre deux cases passés en paramétre elle envoie 1 
si les deux cases sont identiques 0 sinon*/
int identiques(Case c1,Case c2);


/* cette fonction si la case est hors quadrillage ou pas */
int hors_quadrillage(int nb_lignes,int nb_colonnes,Case c);
#endif
