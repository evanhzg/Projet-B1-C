// LIBRAIRIES
#include "var.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
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

void menu(){                    // Menu de base, choix entre 4 options: nvelle sauvegarde, rejouer ancienne sauvegarde, voir les crédits et quitter le jeu
    printf("MAIN MENU:\n");
    printf(GREEN "1: NEW GAME\n" RESET);
    printf(MAGENTA "2: LOAD SAVED GAME\n" RESET);
    printf(YELLOW "3: ABOUT\n" RESET);
    printf(RED "4: EXIT\n" BLUE);
    while (*choice!=1 && *choice!=2 && *choice!=3 && *choice!=4){
        switch (choice()){
            case 1:
                start();
                break;
            case 2:
                loadSave();
                break;
            case 3:
                credits();
                break;
            case 4:
                exit(0);
            default:
                menu();
        }
    }
}

void loadSave(){
    menu();
}

void credits(){                 // Crédits (c'est explicite.)
    printf(GREEN "\nProjet réalisé dans le cadre du cours de C en première année de Bachelor à Ynov Ingésup Paris. Le groupe est constitué de Evan Hoiizey, Ryad Carmoun et Alexandre Hamza.\n" RESET);
    printf("--\n");
    for(int i=0;i<5;i++){
        sleep(1);
        printf("--\n");
    }
    menu();
}
