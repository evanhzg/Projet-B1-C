#ifndef var_h
#define var_h
#include <stdio.h>

void start(void);
void auberge(void);
void combat(void);
void garde(void);
void boss(void);
int choice(void);
void foret(void);
void lac(void);
void grotte(void);
void chateau (void);
void loadSave(void);
void credits(void);
void menu(void);
void paliers(void);
void perdu(void);
void gagne(void);


// STRUCT DES MONSTRES ET DU PLAYER, DEFINISSENT PARAMETRES QUI LEUR SERONT ASSIGNÉS
typedef struct perso perso;     // redéfinit "perso" comme un raccourci de la commande "struct perso"


struct perso{
    int pv;
    int max_pv;
    int piles;                  // abandonné, laissé dans le code par manque de temps pour tout réajuster (tout décaler dans le tableau d'inventaire)
    int xp;
    int palier;
    int force;
    int chance;
    char name[40];
};

perso player;                   // Crée un joueur ayant les paramètres définis au-dessus (ils sont tous égaux à 0 par défaut)
perso monstre;                  // Pareil mais pour les monstres, un seul monstre est créé mais il est redéfini et ses paramètres changent à chaque combat
perso gardes;
perso miniboss;
perso pablito;

#endif /* !var_h */
