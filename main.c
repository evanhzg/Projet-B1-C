#include <stdio.h>
#include <stdlib.h>

char *name = NULL;

void start(){
    printf("Salut, je suis le Professeur Chen, comment t'appelles-tu?\n");
    scanf("%c",&name);
    printf("Ton nom est donc %c, c'est bien ça?",&name);
}

void loadSave(){
}

void credits(){
    printf("\nProjet réalisé dans le cadre du cours de C en première année de Bachelor à Ynov Ingésup Paris.\n");
}

void menu(){
    int choice;
    printf("MAIN MENU:\n");
    printf("1: New Game\n");
    printf("2: Load Saved Game\n");
    printf("3: About\n");
    printf("4: Exit\n");
    scanf("%d",&choice);
    if(choice==1){
        start();
    }
    else if(choice==2){
        loadSave();
    }
    else if(choice==3){
        credits();
    }
    else if(choice==4){
        printf("Game quit.");
    }
}


int main(){
    menu();
}
