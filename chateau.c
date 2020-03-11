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

void chateau(){
    if(*clefs==1){
        printf(CYAN "Vous utilisez la " YELLOW "clé " CYAN "pour rentrer dans le chateau.\n\n");
        sleep(1);
        printf(CYAN "Vous apercevez des escaliers en face de vous ainsi qu une porte sur votre droite avec ecrit 'bureau' dessus\n");
        sleep(1);
        printf(YELLOW "1:Prendre les escaliers\n");
        sleep(1);
        printf(YELLOW "2:Rentrer dans le bureau\n" WHITE);
        sleep(1);
        switch(choice()){
            case 1:
                printf(CYAN "Vous montez les escaliers, un garde royal vous agresse en haut des marches.\n");
                garde();
            
            case 2:
                printf(CYAN "Vous pénétrez dans le bureau, un garde royal vous agresse.\n");
                garde();
        }
        printf(GREEN "vous récuperez tous vos "YELLOW"PV\n");
        player.pv=player.max_pv;
        sleep(1);
        printf(CYAN "Vous venez de vaincre le "RED"garde royal"CYAN", vous entendez vote téléphone sonner dans votre poche, c'est Pablito.\n");
        sleep(1);
        printf(WHITE "Je vois que tu viens de vaincre le garde royal, je suis au bout du chateau rejoint moi le plus vite possible.\n");
        sleep(1);
        printf(CYAN"Vous courez à travers le château et vous apercevez une grande porte méttalique\n");
        sleep(1);
        printf(CYAN"Un sentiment de crainte et de doute vous envahit mais vous poussez la porte et apercevez le professeur Pablito\n");
        sleep(1);
        printf(WHITE"Bonjour %s, je vois que tu as traversé de nombreuses épreuve pour arriver jusque ici.\n",player.name);
        sleep(1);
        printf(WHITE "Mais ta dernière épreuve... C'EST MOI! Prepare toi !\n");
        sleep(1);
        printf(RED "Pablito vous agresse\n");
        sleep(1);

        boss();

        printf(CYAN "Vous avez battu Pablito, une "YELLOW"grosse clé"CYAN" tombe de sa poche, vous la ramasser et apercevez une grande porte au fond de l'allée\n ");
        sleep(1);
        printf(CYAN"Vous poussez la porte et voyez un sentier qui mène à la ville la plus proche, un sentiment de soulagement vous envahit\n");
        sleep(1);
        printf(CYAN"Vous vous retournez une dernière en direction du chateau, mais..."RED"plus rien.\n ");
        sleep(1);
        printf(CYAN "Le chateau à disparu ainsi que la grotte, l'épaisse forêt et le lac.\n");
        sleep(1);
        printf(CYAN "Pourtant cela ne vous tracasse pas plus que ça, vous continuez à avancer le regarde vide en vous demandant... Mais qui etait ce fameux Pablito..?\n\n");
        sleep(1);
        gagne();
        }
    else{
        printf(RED"Vous n'avez pas la "YELLOW"clé"RED", revenez quand vous l'aurez.\n");
        sleep(1);
        printf(GREEN"Elle se trouve dans la grotte à l'Ouest!\n");
        sleep(1);
    }
}
    
