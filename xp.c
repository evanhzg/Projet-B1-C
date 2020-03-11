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
             
extern int xpRequise;

void paliers(){
    if(player.xp>=xpRequise){
        player.palier+=1;
        player.max_pv+=20;
        monstre.palier+=1;
        monstre.chance+=20;
        xpRequise=xpRequise*2;
        printf(CYAN "Vous venez de monter au niveau " YELLOW "%d" CYAN "!\n" RESET, player.palier);
    }
}
