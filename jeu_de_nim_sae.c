/* ---------------------------------------------------------------------
 * Auteur : DOISY Noa BUT 1 Informatique 
 * Date de Création : 09 sept 2024
 ------------------------------------------------------------------------*/

#include <stdio.h>    // Inclus pour les opérations d'entrée/sortie (printf)
#include <stdlib.h>   // Inclus pour les fonctions utilitaires (rand, srand)
#include <stdbool.h>  // Inclus pour utiliser des types booléens (true, false)
#include <time.h>     // Inclus pour utiliser time() afin d'initialiser le générateur aléatoire

/*---------Lexique---------*/

int NbrObjet;        // Nombre de bâtons sur le plateau de jeu
int prisj1, prisj2;  // Nombre de bâtons pris par le joueur naïf (prisj1) et le joueur intelligent (prisj2)
char* msg1;          // Message affiché si le joueur naïf gagne
char* msg2;          // Message affiché si le joueur intelligent gagne


/*------Fonction------*/

/**
 * Fonction qui simule le comportement du joueur naïf
 * Le joueur naïf choisit un nombre aléatoire de bâtons à prendre (entre 1 et 3)
 * @return Le nombre de bâtons que le joueur naïf décide de prendre
 */
int RobotNaif() {
    // Fonction qui choisit un nombre aléatoire de bâtons à prendre (entre 1 et 3)
    int alea = rand() % 3 + 1; // Génère un nombre aléatoire de 1 à 3
    return alea; // Renvoie le nombre choisi
}

/**
 * Fonction qui simule le comportement du joueur intelligent
 * Le joueur intelligent choisit un nombre de bâtons à prendre pour forcer une victoire
 * @param choixjnaif Le nombre de bâtons pris par le joueur naïf lors de son tour
 * @param reste Le nombre de bâtons restants sur le plateau
 * @return Le nombre de bâtons que le joueur intelligent décide de prendre
 */
int RobotIntelligent(int choixjnaif, int reste) {
    // Fonction qui détermine le nombre de bâtons à prendre pour gagner
    // Stratégie pour ramener le nombre de bâtons restants à un multiple de 4
    int intel = 4 - choixjnaif;

    // s'assure de prendre au moins 1 et au plus ce qui reste
    if (intel < 1) {
        intel = 1;
    }
    if (intel > reste) {
        intel = reste;
    }
    return intel; // Renvoie le nombre calculé de bâtons à prendre
}


/*------Main------*/


int main(int argc, char** argv) {

    // Message de lancement du jeu de Nim
    printf("Début du jeu de Nim entre un joueur naïf et un joueur intelligent\n");

    // Initialisation des messages de victoire pour les deux joueurs
    msg1 = "Le joueur naïf a gagné contre le joueur intelligent !!!";
    msg2 = "Le joueur intelligent a gagné contre le joueur naïf !";

    // Initialisation du générateur de nombres aléatoires
    srand(time(NULL)); // Permet d'obtenir une séquence différente de nombres aléatoires à chaque exécution
    NbrObjet = 16; // Nombre initial de bâtons sur la table

    while (NbrObjet > 0) { // Boucle tant qu'il reste des bâtons

        // Tour du joueur naïf
        prisj1 = RobotNaif(); // Obtient le nombre de bâtons que le joueur naïf choisit
        NbrObjet = NbrObjet -  prisj1; // Met à jour le nombre de bâtons restants
        printf("\nNombre de bâtons pris par le Joueur naïf : %d ; Il reste donc %d bâtons.\n", prisj1, NbrObjet); // Affiche la progression du jeu

        // Vérification de la victoire du joueur naïf
        if (NbrObjet <= 0) { // Si le nombre de bâtons atteint 0
            printf("%s", msg1); // Affiche le message de victoire pour le joueur naïf
            return 0; // Fin du programme
        }

        // Tour du joueur intelligent
        prisj2 =RobotIntelligent(prisj1,NbrObjet); // Obtient le nombre de bâtons que le joueur intelligent choisit
        // Tour du joueur intelligent
        prisj2 = RobotIntelligent(prisj1, NbrObjet); // Obtient le nombre de bâtons que le joueur intelligent choisit
        NbrObjet = NbrObjet - prisj2; // Met à jour le nombre de bâtons restants
        printf("Nombre de bâtons pris par le Joueur intelligent : %d ; Il reste donc %d bâtons.\n\n", prisj2, NbrObjet); // Affiche la progression du jeu
        if (NbrObjet <= 0) { // Si le nombre de bâtons atteint 0
            printf("%s", msg2); // Affiche le message de victoire pour le joueur intelligent
            return 0; // Fin du programme
        }
    }

    return 0; // Fin du programme (bien que cela ne devrait pas être atteint ici)
}
