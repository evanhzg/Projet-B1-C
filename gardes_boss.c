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
void garde(){
    gardes.force=30;
    gardes.pv=150;
    printf(MAGENTA "Vous affrontez un garde.\n" RESET);
    
    while(player.pv>0 && gardes.pv>0){                                                            // %tage de chances que le garde touche le joueur (20 au lvl.1)
        int critChc = rand() % 100+1;
        int atkCrit;
        
        //%chances critique
        if(critChc<=30){
            atkCrit=player.force;
        }
        else{
            atkCrit=0;
        }
        
        printf(GREEN "\nQue voulez-vous faire?\n1=atk\n2=potion\n" RESET);
        
        switch(choice()){
            case 1:
                if (atkCrit>0){
                    printf(RED "COUP CRITIQUE! DÉGÂTS X2" RESET);
                }
                printf(GREEN "Vous attaquez le garde, vous lui infligez " CYAN "%d " GREEN "dégâts.\n" RESET,player.force+atkCrit);
                gardes.pv-=player.force;                                                           // Dégâts dépendent de la force du joueur (qui est son arme, en réalité)
                if(gardes.pv<=0){                                                                  // Mort du garde
                    gardes.pv=0;                                                                   // Pour que ça n'affiche pas une valeur inférieure à 0 (prévention d'erreur)
                    printf(RED "Le garde est mort. Vous gagnez " MAGENTA "500" RED "xp.\n" RESET);
                    player.xp+=500;                                                                 // Augmente l'xp du joueur proportionnellement au lvl du garde
                    paliers();
                }
                break;
                
            case 2:
                if(*potions>0){
                    printf(GREEN "Vous utilisez une potion et récupérez tous vos PV." YELLOW "(+%d PV)\n" RESET,player.max_pv-player.pv);
                    player.pv=player.max_pv;
                    potions-=1;
                    sleep(1);
                }
                break;
                
            default:
                choice();
                break;
        }
        
        if(gardes.pv>0){                                                                           // Tour du gardes: il a un %tage de chances de rater la cible
            printf(CYAN "Le garde vous a touché! Vous perdez " RED "%d" CYAN "PV.\n\n" RESET,gardes.force);
            player.pv-=gardes.force;
            if(player.pv<=0){
                perdu();
            }
        }
        printf(GREEN "%s HP: %d " RED "Garde HP: %d\n",player.name,player.pv,gardes.pv);
    }
}

void boss(){
        pablito.force=25;
        pablito.pv=300;
        printf(MAGENTA "Vous affrontez Pablito.\n" RESET);
        
        while(player.pv>0 && pablito.pv>0){                                                            // %tage de chances que le garde touche le joueur (20 au lvl.1)
            int critChc = rand() % 100+1;
            int atkCrit;
            
            //%chances critique
            if(critChc<=30){
                atkCrit=player.force;
            }
            else{
                atkCrit=0;
            }
            
            printf(GREEN "\nQue voulez-vous faire?\n1=atk\n2=potion\n" RESET);
            
            switch(choice()){
                case 1:
                    if (atkCrit>0){
                        printf(RED "COUP CRITIQUE! DÉGÂTS X2" RESET);
                    }
                    printf(GREEN "Vous attaquez le garde, vous lui infligez " CYAN "%d " GREEN "dégâts.\n" RESET,player.force+atkCrit);
                    pablito.pv-=player.force;                                                           // Dégâts dépendent de la force du joueur (qui est son arme, en réalité)
                    if(pablito.pv<=0){                                                                  // Mort du garde
                        pablito.pv=0;                                                                   // Pour que ça n'affiche pas une valeur inférieure à 0 (prévention d'erreur)
                        gagne();
                    }
                    break;
                    
                case 2:
                    if(*potions>0){
                        printf(GREEN "Vous utilisez une potion et récupérez tous vos PV." YELLOW "(+%d PV)\n" RESET,player.max_pv-player.pv);
                        player.pv=player.max_pv;
                        potions-=1;
                        sleep(1);
                    }
                    break;
                    
                default:
                    choice();
                    break;
            }
            
            if(gardes.pv>0){                                                                           // Tour du gardes: il a un %tage de chances de rater la cible
                printf(CYAN "Le garde vous a touché! Vous perdez " RED "%d" CYAN "PV.\n\n" RESET,gardes.force);
                player.pv-=gardes.force;
                if(player.pv<=0){
                    perdu();
                }
            }
            printf(GREEN "%s HP: %d " RED "Garde HP: %d\n",player.name,player.pv,gardes.pv);
        }
    }
    
}
