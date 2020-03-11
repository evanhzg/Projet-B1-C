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

extern int maxChoix;
extern int *potions;

// COMBATS CONTRE LES MONSTRES
void combat(){
    monstre.pv=40+20*player.palier;
    printf(MAGENTA "\nVous affrontez un monstre de niveau " RED "%d" MAGENTA ".\n" RESET,monstre.palier);
    
    while(player.pv>0 && monstre.pv>0){                                                             // Le combat ne se finit que si l'un des deux tombe a 0 ou moins de PV
        int atkMonstre = rand() % 100+1;                                                            // %tage de chances que le monstre touche le joueur (20 au lvl.1)
        int critChc = rand() % 100+1;
        int atkCrit;
        int fuite = rand() % 100+1;
        
        //%chances critique
        if(critChc<=30){
            atkCrit=player.force;
        }
        else{
            atkCrit=0;
        }
        maxChoix=3;
        
        printf(GREEN "\nQue voulez-vous faire?\n1=atk\n2=fuir\n3=potion\n" WHITE);
        switch(choice()){
            case 1:
                if (atkCrit>0){
                    printf(RED "COUP CRITIQUE! DÉGÂTS X2\n" RESET);
                    sleep(1);
                }
                printf(GREEN "Vous attaquez le monstre, vous lui infligez " CYAN "%d " GREEN "dégâts.\n" RESET,player.force+atkCrit);
                sleep(1);
                monstre.pv-=player.force+atkCrit;                                                           // Dégâts dépendent de la force du joueur (qui est son arme, en réalité)
                if(monstre.pv<=0){                                                                  // Mort du monstre
                    monstre.pv=0;                                                                   // Pour que ça n'affiche pas une valeur inférieure à 0 (prévention d'erreur)
                    printf(RED "Le monstre est mort. Vous gagnez " MAGENTA "%d" RED "xp.\n" RESET,100*monstre.palier);
                    sleep(1);
                    player.xp+=100*monstre.palier;                                                  // Augmente l'xp du joueur proportionnellement au lvl du monstre
                    paliers();
                }
                break;
                
            case 2:
                if (fuite<=20){
                    printf(RED "Vous fuyez le combat avec succès.\n");
                    monstre.pv=0;
                    player.xp-=monstre.palier;
                    if(player.xp<0){
                        player.xp=0;
                    }
                }
                break;
                
            case 3:
                if(*potions>0){
                    printf(GREEN "Vous utilisez une potion et récupérez tous vos PV." YELLOW "(+%d PV)\n" RESET,player.max_pv-player.pv);
                    player.pv=player.max_pv;
                    potions-=1;
                    sleep(1);
                }
                break;
                
            case 4:
                monstre.pv=0;
        }
        
        if(monstre.pv>0){                                                                           // Tour du monstre: il a un %tage de chances de rater la cible
            if(atkMonstre<=monstre.chance){
                printf(CYAN "Le monstre vous a touché! Vous perdez " RED "%d" CYAN "PV.\n" RESET,monstre.force);
                sleep(1);
                player.pv-=monstre.force;
            }
            else{
                printf(MAGENTA "Le monstre vous a manqué!\n\n" RESET);
                sleep(1);
            }
            printf(GREEN "%s HP: %d " RED "Monstre (lvl.%d) HP: %d\n\n",player.name, player.pv, monstre.palier, monstre.pv);
            sleep(1);
        }
    }
}
