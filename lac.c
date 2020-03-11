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

extern int *barque;
extern int *lampe;
extern int sentier;

void lac(){
    if(*lampe==0){
        printf(CYAN "Vous avancez le long d'un chemin et apercevez un lac devant vous.\n");
        sleep(1);
        printf(CYAN "Vous avez besoin d'une barque pour passer le lac!\n\n");
        sleep(1);
        if (*barque==1){
            printf(CYAN "Vous utilisez votre barque pour voguer sur le lac\n");
            sleep(1);
        }
        while(*barque!=1){
            printf(RED "Vous n'avez pas l'objet nécessaire pour traverser le lac.\n");
            sleep(1);
            if(sentier==1){
                printf(CYAN "Vous êtes retourné dans la forêt pour chercher la barque.\n");
                sleep(1);
                *barque+=1;
            }
            else{
                printf(RED "Vous devriez explorer la forêt...\n\n");
                sleep(1);
                auberge();
            }
        }

        printf(CYAN "Un obstacle obstrue le passage du lac, Vous apercevez qu'il se divise au loin.\n");
        sleep(1);
        printf(YELLOW "1:Pagayer pour aller à droite\n");
        printf("2:Pagayer pour aller à gauche\n" WHITE);
        switch(choice()){
            case 1:
                printf(CYAN "Vous voguez à droite de l'obstacle sans encombre\n");
                sleep(1);
                break;
                
            default:
                printf(CYAN "Vous voguez à gauche de l'obstacle mais un "RED "monstre" CYAN " vous agresse...\n");
                sleep(1);
                combat();
                break;
        }   

        printf(CYAN "Vous arrivez de de l'autre côté du lac, une " YELLOW "lampe" CYAN " est posée devant un buisson.\n");
        sleep(1);
        printf(CYAN "Vous vous approchez du buisson pour la ramasser lorsqu'un "RED "garde royal" CYAN " surgit et vous agresse\n");
        garde();

        printf(CYAN "Vous avez vaincu un "RED"garde royal et vous récuperez la "YELLOW"lampe\n");
        *lampe+=1;
        auberge();
    }
    else{
        printf(CYAN "Vous n'avez plus rien à trouver ici.\nRetour à l'auberge.\n");
        sleep(1);
        auberge();
    }
}
