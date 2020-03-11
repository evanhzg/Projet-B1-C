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
    if(*clefs>=0){
        printf("Vous utilisez la clé pour rentrer dans le chateau.\n");
        sleep(1);
        printf("Vous apercevez des escaliers en face de vous ainsi qu une porte sur votre droite avec ecrit 'bureau' dessus\n");
        sleep(1);
        printf("1:Prendre les escaliers\n");
        sleep(1);
        printf("2:Rentrer dans le bureau\n");
        sleep(1);
        switch(choice()){
            case 1:
                printf("Vous montez les escaliers, un garde royal vous agresse en haut des marches.\n");
                garde();
            
            case 2:
                printf("Vous pénétrez dans le bureau, un garde royal vous agresse.\n");
                garde()
        }
        printf("vous récuperez 100% de vos PV\n");
        player.pv=player.max_pv;
        sleep(1);
        printf("Vous venez de vaincre le garde royal, vous entendez vote téléphone sonner dans votre poche, c'est Pablito.\n");
        sleep(1);
        printf("Je vois que tu viens de vaincre le garde royal, je suis au bout du chateau rejoint moi le plus vite possible.\n");
        sleep(1);
        printf("Vous courez à travers le château et vous apercevez une grande porte méttalique\n");
        sleep(1);
        printf("Un sentiment de crainte et de doute vous envahit mais vous pousser la porte et apercevez le professeur Pablito\n");
        sleep(1);
        printf("Bonjour nom du joueur, je vois que tu as traversé de nombreuses épreuve pour arriver jusque ici.\n");
        sleep(1);
        printf("Mais ta dernière épreuve... C'EST MOI! Prepare toi !\n");
        sleep(1);
        printf("Pablito vous agresse\n");
        sleep(1);

        boss();

        printf("Vous avez battu Pablito, une grosse clé tombe de sa poche, vous la ramasser et apercevez une grande porte au fond de l'allée\n ");
        printf("Vous poussez la porte et voyez un sentier qui mène à la ville la plus proche, un sentiment de soulagement vous envahit\n");
        printf("Vous vous retournez une dernière en direction du chateau, mais...plus rien.\n ")
        printf("Le chateau à disparu ainsi que la grotte, l'épaisse forêt et le lac.\n")
        printf("Pourtant cela ne vous tracasse pas plus que ça, vous continuez à avancer le regarde vide en vous demandant... Mais qui etait ce fameux pablito ?");

        }
    }
    
