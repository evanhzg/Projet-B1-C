#include <stdio.h>
#include <stdlib.h>
#include "var.h"

int inv[10];

int *couteau=&inv[0];           // On aurait pu faire un struct mais on l'a fait avant le cours sur la commande struct donc on garde le tableau (revient au même,
int *potions=&inv[1];           // c'est juste moins bien organisé) et on a ajouté des variables associées à chaque case du tableau pour mieux s'y retrouver
int *clefs=&inv[2];
int *lampe=&inv[3];
int *piles=&inv[4];             // ABANDONNÉ (laissé dans l'optique d'une suite)
int *parapluie=&inv[5];
int *strBoost=&inv[6];
int *pvBoost=&inv[7];
int *barque=&inv[8];

int dirForet=0;
int dirLac=0;
int dirGrotte=0;
int dirChateau=0;
int sentier=0;
int entree;

int maxChoix;
int xpRequise=100;      // Passage de paliers (définit niveau des ennemis)
int main(){
    menu();
}
