// LIBRAIRIES
#include "var.h"
#include <time.h>
#include <stdio.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

// COULEURS DE TEXTE (FONCTIONNE SOUS UNIX,PAS TESTÉ SOUS WINDOWS POUR LE MOMENT)
#define RESET  "\x1B[0m"
#define RED  "\x1B[31m"
#define GREEN  "\x1B[32m"
#define YELLOW  "\x1B[33m"
#define BLUE  "\x1B[34m"
#define MAGENTA  "\x1B[35m"
#define CYAN  "\x1B[36m"
#define WHITE  "\x1B[37m"

extern int maxChoix;
extern int xpRequise;
extern int *inv;
extern int *lampe;
extern int *clefs;
extern int *parapluie;
extern int *pvBoost;
extern int *strBoost;
extern int *barque;
extern int *potions;
extern int *couteau;
extern int entree;

int choice(){
    entree=0;
    while(entree==0){
        printf(GREEN "0 montre l'inventaire et 9 ramène au menu (pas de sauvegarde!!)\n" MAGENTA);
        scanf("%d",&entree);
        
        if(entree==0){                                                                                   // Affichage de l'inventaire via la commande "inv"
            printf(GREEN "==INVENTAIRE==\n");
            if(*couteau>0){                                                                                  // N'affiche que si on en possède au moins 1
                printf("Couteau\n");
            }
            if(*potions>0){                                                                                  // Affiche aussi la quantité de l'item en question si possible
                printf("Potions: %d\n",*inv+1);
            }
            else{
            }
            if(*clefs>0){
                printf("Clés: %d\n",*inv+2);
            }
            else{
            }
            if(*lampe>0){
                printf("Lampe\n");
            }
            else{
            }
            if(*parapluie>0){
                printf("Parapluie pour la pluie\n");
            }
            else{
            }
            if(*pvBoost>0){
                printf("PV BOOST\n");
            }
            else{
            }
            if(*strBoost>0){
                printf("STRENGTH BOOST\n");
            }
            else{
            }
            if(*barque>0){
                printf("Barque\n");
            }
            else{
            }
            printf("==============\n"RESET);
            printf(YELLOW "Vous avez %d points d'xp (%d avant le niveau %d).\n\n" RESET,player.xp,xpRequise-player.xp,player.palier+1);
        }
        if(entree==9){
            menu();
        }
    }
    return entree;
}
