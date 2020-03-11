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

void auberge(){
    printf(WHITE"Vous etes à l'auberge. Où aller ensuite?\n" YELLOW "1 = EST\n2 = SUD\n3 = OUEST\n4 = NORD\n" WHITE);
    switch(choice()){
        case 1:
            foret();
        case 2:
            chateau();
        case 3:
            grotte();
        case 4:
            lac();
    }
}
