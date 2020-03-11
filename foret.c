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

extern int dirForet;
extern int maxChoix;
extern int sentier;
extern int *barque;

void empSentier(){
    printf(CYAN "Vous apercevez, au pied d'un arbre, une barque\n");
    sleep(1);
    printf(CYAN "Vous vous approchez de l'arbre lorsqu'un" RED " monstre" CYAN " vous agresse\n");
    sleep(1);
    combat();
    printf(CYAN "Vous avez vaincu le monstre et vous pouvez prendre la barque\n");
    sleep(1);
    printf(YELLOW "1:Prendre la barque\n");
    printf("2:Laisser la barque au pied de l'arbre\n" WHITE);
    switch(choice()){
        case 1:
            printf(GREEN "Vous prenez la " YELLOW "barque" GREEN " et la mettez dans votre inventaire.\n");
            *barque=1;
            printf(CYAN "Vous retournez à l'auberge.");
            
        case 2:
            printf(CYAN "Vous laissez la barque et retournez à l'auberge\n");
            sentier+=1;
            auberge();
    }

    if (*barque==1){
        printf(CYAN "Votre téléphone sonne, vous repondez.\n");
        sleep(1);
        printf(WHITE "Bravo %s, tu viens de trouver une barque. Il y a un lac pas très loin de l'auberge il me semble, tu devrait y faire un tour.\n",player.name);
        sleep(1);
        printf(MAGENTA "Professeur Pablito, attendez... comment savez-vous où je suis ? M'espionner-vous c'est vous qui m'avez mis ici !?\n");
        sleep(1);
        printf(WHITE "Je vous expliquerai plus tard. Le temps presse, dépêchez vous !!\n");
        sleep(1);
        printf(CYAN "Le téléphone se coupe, vous retournez à l'auberge\n");
        sleep(1);
        auberge();
    }
}

void empBoueux(){
    printf(RED "Vous tombez face à un monstre\n" RESET);
    combat();
    printf(GREEN "Le monstre vous drop une potion!" RESET);
}


void foret(){
    printf(CYAN "Vous venez de rentrer dans la forêt.\n");
    sleep(1);
    printf(CYAN "Vous apercevez au loin un chemin boueux et un sentier sur votre droite.\n");
    sleep(1);
    printf(YELLOW "1:Prendre le sentier sur votre droite\n");
    printf("2:Prendre le chemin boueux.\n" WHITE);
    switch(choice()){
        default:
            printf(CYAN "Vous empruntez le sentier.\n");
            sleep(1);
            empSentier();
            
        case 2:
            printf(CYAN "Vous decidez de longer le chemin boueux\n");
            sleep(1);
            empBoueux();
    }
}


