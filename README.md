# Projet-B1-C

Problème possible: sleep() fonctionnant sous unix devrait être Sleep() sous windows.
----> FIX: Sur Code::Blocks faire un rechercher et reemplacer (ctrl+shift+r) et remplacer tous les sleep en Sleep et sélectionner "Project Files" en bas de la page et s'assurer que "Target" vise "All project files" puis faire Replace et cocher "All". L'autre erreur vient des couleurs, pas de fix fonctionnel si ce n'est de remplacer toutes les variables dans chaque printf, je suis désolé pour cette partie.

Fonctionnalités non implémentées:
pvBoost doublant les PV et les PV MAX lors d'un combat puis les redivise par deux à la fin de celui-ci
healthBoost faisant de même avec la force
Dialogues et miniBoss dans la grotte
Améliorations des combats avec l'annulation du tour si le joueur n'a pas de potions...
Améliorations de la fluidité des dialogues (\n et sleep()) et de l'aspect du jeu

AIDE UTILE/TRICHE:
Faire 4 lors d'un combat tue le monstre instantanément pour continuer et tester le jeu plus vite. Ce n'est pas précisé dans le jeu. (il faut le faire 2 fois avec les gardes et le boss)

Bonne journée/soirée/matinée/nuitée..!

Il faut supprimer le fichier test.c (et le main.o éventuellement), je n'ai pas réussi en les pushant a les supprimer avec git (pas avec le git intégré à XCode et je ne suis pas très connaisseur de github pour le moment donc c'est ce que j'ai remarqué)
