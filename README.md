# CPE_TP_C_2

## Automates de programmation

Implémentation d'un automate pour vérifier la syntaxe d'une phrase.
Un jeu de test de 14 phrases est utilisé, et l'utilisateur peut rentrer lui-même une phrase.
Un dictionnaire peut être passé en paramètre. Il viendra en plus du dictionnaire de base.
Un makefile est inclut pour faciliter la compilation.

## Librairie "automaton.h"

Une librairie a été créée pour gérer l'automate.
Une matrice de transition est générée pour faire correspondre des états et types de mots lus.
Un dictionnaire est écrit en dur dans le fichier header de la librairie.

## Librairie "file.h"

Une librairie permettant d'interprêter un dictionnaire supplémentaire depuis un fichier.
