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

extern int *clefs;
extern int *lampe;

void grotte(){
    if(*lampe==1){
        printf(WHITE "WIP\n");
        sleep(1);
        printf(YELLOW "Vous obtenez la clé du château!\n");
        sleep(1);
        *clefs+=1;
        printf("Vous retournez à l'auberge/n");
        auberge();
    }
    else{
        printf(CYAN "Il vous faut une "YELLOW"lampe"CYAN", il fait trop sombre.\n"WHITE"Il y en a une au lac...\n");
        sleep(1);
        sleep(1);
        auberge();
    }
}
