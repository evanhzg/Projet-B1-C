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
    printf(WHITE "Vous apercevez, au pied d'un arbre, une barque\n");
    sleep(1);
    printf("Vous vous approchez de l'arbre lorsqu'un monstre vous agresse\n");
    sleep(1);
    combat();
    printf("Vous avez vaincu le monstre et vous pouvez prendre la barque\n");
    sleep(1);
    printf("1:Prendre la barque\n");
    printf("2:Laisser la barque au pied de l'arbre\n");
    switch(choice()){
        default:
            printf("Vous prenez la barque et la mettez dans votre inventaire.\n");
            barque+=1;
            
        case 2:
            printf("Vous laissez la barque et retournez à l'auberge\n");
            sentier+=1;
            auberge();
    }

    if (*barque==1){
        printf("Votre téléphone sonne, vous repondez.\n");
        sleep(1);
        printf("Bravo %s, tu viens de trouver une barque. Il y a un lac pas très loin de l'auberge il me semble, tu devrait y faire un tour.\n",player.name);
        sleep(1);
        printf("Professeur Pablito, attendez... comment savez-vous où je suis ? M'espionner-vous c'est vous qui m'avez mis ici !?\n");
        sleep(1);
        printf("Je vous expliquerai plus tard. Le temps presse, dépêchez vous !!\n");
        sleep(1);
        printf("Le téléphone se coupe, vous retournez à l auberge\n");
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
    printf(WHITE "Vous venez de rentrer dans la forêt.\n");
    sleep(1);
    printf("Vous apercevez au loin un chemmin boueux et un sentier sur votre droite.\n");
    sleep(1);
    printf("1:Prendre le sentier sur votre droite\n");
    printf("2:Prendre le chemin boueux.\n");
    switch(choice()){
        default:
            printf("Vous empruntez le sentier.\n");
            sleep(1);
            empSentier();
            
        case 2:
            printf("Vous decidez de longer le chemin boueux\n");
            sleep(1);
            empBoueux();
    }
}


