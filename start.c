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
extern int *couteau;
extern int *potions;

void start(){                   // Lancement du jeu et choix initiaux jusqu'aux choix selon les zones (forêt,lac,grotte,château)
    *potions=2;
    player.max_pv=100;
    player.pv=player.max_pv;
    player.palier=1;
    int verifName=0;
    printf(CYAN "Salut, je suis le Professeur Pablito, comment t'appelles-tu?\n" RESET);
    while(verifName!=1){
        printf(GREEN "Entre ton pseudo:\n" WHITE);
        scanf("%s",player.name);
        printf(CYAN "Ton nom est donc %s, c'est bien ça?\n"YELLOW"1: oui\n2: non\n" WHITE,player.name);
        scanf("%d",&verifName);
    }
    printf(CYAN "Ok, %s.\n",player.name);
    sleep(1);
    printf("...\n");
    sleep(1);
    printf("prêt?\n");
    sleep(1);
    
    
    for(int i=0;i<3;i++){
        printf("-\n");
        sleep(1);
    }
    printf("...\n");
    printf(CYAN "Vous vous réveillez en pleine forêt, au milieu de la nuit.\n" RESET);
    sleep(1);
    printf(GREEN "- - Vous venez de ramasser un " RED "couteau " GREEN "- -\n" RESET);
    *couteau = 1;
    player.force=20;
    monstre.force=20;
    monstre.chance=20;
    monstre.palier=player.palier;
    monstre.pv=40+(40*monstre.palier);
    printf(CYAN "Cette forêt est inquiétante... Vous sentez une présence s'approcher...\n");
    
    for(int i=0;i<3;i++){
        printf("-\n");
        sleep(1);
    }
    
    printf(CYAN "Cette présence.. c'est un " RED "MONSTRE" CYAN ", tu vas en affronter plusieurs et celui-ci sera ton premier.\nIl est de niveau 1, profites-en: ils ne seront pas tous aussi faciles à battre.\n\n");
    
    combat();
    
    printf(CYAN "Le telephone sonne...\n");
    sleep(1);
    printf(WHITE "Prof: Félicitations, tu viens de passer niveau 2. Les monstres deviendront de plus en plus forts durant ton aventure, prépares-toi bien!\n");
    sleep(1);
    printf(MAGENTA "%s: Quelqu'un peut m'expliquer ce qu'il se passe? J'ai failli mourir!!\n", player.name);
    sleep(1);
    printf(WHITE "Prof: Tu as été touché par le monstre. Certains monstres te donneront des potions de soin, des piles ou des clefs en guise de butin, utilise la potion pour te soigner.\n");
    sleep(1);
    printf(GREEN "%s se soigne et regagne" YELLOW " 20 " GREEN "PV\n",player.name);
    printf(WHITE "Prof: Tu vois le grand château derrière toi? Je suis enfermé dedans! Aides-moi à en sortir et je t'aiderai à partir d'ici.\n");
    sleep(1);
    printf(MAGENTA "%s: Quoi !? Comment ?!!\n",player.name);
    sleep(1);
    printf(WHITE "Je dois te laisser... fais un tour au château quand tu peux.\n");
    sleep(1);

    printf(CYAN "Vous voyez un sentier avec une auberge au loin, voulez vous emprunté le sentier ou rester avec la depouille du monstre ?\n"YELLOW"1:Prendre le sentier\n2:Rester avec le monstre\n" WHITE);
    sleep(1);
    
    maxChoix=2;
    
    switch(choice()){
        case 1:
            printf(CYAN"Vous marchez sur le sentier et vous arrivez devant une auberge qui semble abandonnée\n");
            sleep(1);
            auberge();
            
        default:
            printf(CYAN "une odeur mortuaire sort du cadavre, vous decidez de prendre la route de l'auberge\n");
            auberge();
    }
}
