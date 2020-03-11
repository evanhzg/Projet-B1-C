/*//HEALTH BOOST
printf(GREEN "Vous trouvez une potion bleue mystérieuse dans le coffre...\n" RESET);
player.pvBoost+=1;
printf(CYAN "Tu viens de trouver une " RED "potion de Health Boost" CYAN ", fais attention: c'est la seule que tu peux trouver. Elle n'est utilisable qu'une fois et elle doublera ta vie max durant toute la durée d'un combat (même si tu as déjà perdu des PV). Utilise-la avec précaution.\n" RESET);

//HP BOOST
printf(GREEN "Vous trouvez une potion rouge mystérieuse dans le coffre...\n" RESET);
player.strBoost+=1;
printf(CYAN "Tu viens de trouver une " RED "potion de Strength Boost" CYAN ", fais attention: c'est la seule que tu peux trouver. Elle n'est utilisable qu'une fois et elle doublera ta force durant toute la durée d'un combat. Utilise-la avec précaution.\n" RESET);

//NEED BOAT
if(player.barque!=1){
    printf(RED "L'eau est trop profonde ici! tu ne peux pas traverser... Reviens quand tu pourras.\n" RESET);
    printf(CYAN "Vous retournez à l'auberge\n" RESET);
    auberge();
}


//AUBERGE
if(firstTime=1){
    printf(CYAN "Vous vous approchez de l'auberge quand une vieille aubergiste sort et s'approche de vous.\n")
    printf(MAGENTA "Aubergiste: Oh...\n");
    sleep(1);
    printf("Aubergiste: Nous n'avons plus de place pour dormir, désolé. Que recherchez-vous?\n");
    sleep(1);
    printf("Aubergiste: ...\n");
    sleep(1);
    printf("Aubergiste: ...\n");
    sleep(1);
    printf("Aubergiste: Encore un qui se réveille en pleine forêt...\n");
    sleep(1);
    printf("Aubergiste: Je ne peux pas plus vous aider. Repassez quand vous voulez mais ne me mêlez pas à vos histoires.\n");
    sleep(1);
    printf(CYAN "L'aubergiste s'éloigne. Vous avez le choix entre 4 chemins, où allez-vous?\n1 = EST (?)\n2 = SUD (?)\n3 = OUEST (?)\n4 = NORD (?)\n" RESET);
    choix=0;
    while(choix!=1 && choix!=2 && choix!=3 && choix!=4){
        scanf("%d",choix);
        if(choix==1){
            printf(CYAN "Vous vous redirigez vers la forêt\n"  RESET);
            dirForet+=1;
            foret();
        }
        
        if(choix==2){
            printf(CYAN "Vous vous dirigez vers le sud\n"  RESET);
            dirChateau+=1;
            chateau();
        }
        
        if(choix==3){
            printf(CYAN "Vous vous dirigez vers l'ouest\n"  RESET);
            dirGrotte+=1;
            grotte();
        }
        
        if(choix==4){
            printf(CYAN "Vous vous dirigez vers le nord\n"  RESET);
            dirLac+=1;
            lac();
        }
        
        else{
            printf(RED "Vous avez dû vous tromper... Réessayez.\n" CYAN "Vous avez le choix entre 4 chemins, où allez-vous?\n1 = EST (?)\n2 = SUD (?)\n3 = OUEST (?)\n4 = NORD (?)\n" RESET);
        }
    }
}

//FORET
foret(){
    
}


//BARQUE (SENTIER?)
printf(GREEN "Vous trouvez une " RED "barque" GREEN "dans le coffre\n");
barque+=1;
printf(CYAN "Oh, une barque... Je pense que ça pourra te servir. Garde-là pour le moment.\n ");
sleep(1);
printf(GREEN "‰s attache la barque à son dos avec de la corde trouvée dans le coffre.\n" RESET);
*/
