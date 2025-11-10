/* ---------------------------------------------------------------------
 * Auteur : DOISY Noa BUT 1 Informatique
 * Date de Création : 09 sept 2024
 ------------------------------------------------------------------------*/

#include <stdio.h>   // Inclus pour les opérations d'entrée/sortie (printf)
#include <stdlib.h>  // Inclus pour les fonctions utilitaires (rand, srand)
#include <stdbool.h> // Inclus pour utiliser des types booléens (true, false)
#include <time.h>    // Inclus pour utiliser time() afin d'initialiser le générateur aléatoire
#include <string.h>  // Inclus pour les opérations sur les chaînes de caractères (non utilisé ici mais peut être utile)

/*--------- Prototypes des fonctions ---------*/

int RobotNaif(void);
int RobotIntelligent(int reste, int regle);
int TourHumain(int reste);
int parametragePartie(int mode, char *nomJoueur1, char *nomJoueur2);
int getTypeDeJoueur(int numJoueur, int mode);
void deroulementPartie(int mode, int quiCommence, char *nomJoueur1, char *nomJoueur2);
void annoncerVainqueur(int joueurQuiVientDeJouer, int regle, char *nomJoueur1, char *nomJoueur2);
int LireEntier(void);

/*---------Lexique---------*/

int NbBatons;      // Nombre de bâtons sur le plateau de jeu
int regleVictoire; // Stock l'entier represantant la regle de victoire

/*------Fonction------*/

/**
 * Fonction qui simule le comportement du joueur naïf
 * Le joueur naïf choisit un nombre aléatoire de bâtons à prendre (entre 1 et 3)
 * @return Le nombre de bâtons que le joueur naïf décide de prendre
 */
int RobotNaif()
{
    // Fonction qui choisit un nombre aléatoire de bâtons à prendre (entre 1 et 3)
    int alea = rand() % 3 + 1; // Génère un nombre aléatoire de 1 à 3
    return alea;               // Renvoie le nombre choisi
}

/**
 * Fonction qui simule le comportement du joueur intelligent
 * Le joueur intelligent choisit un nombre de bâtons à prendre pour forcer une victoire
 * @param reste Le nombre de bâtons restants sur le plateau
 * @param regle La règle de victoire (1: dernier bâton gagne, 2: dernier bâton perd)
 * @return Le nombre de bâtons que le joueur intelligent décide de prendre
 */
int RobotIntelligent(int reste, int regle)
{

    int a_pris;

    if (regle == 1)
    {
        a_pris = reste % 4;

        if (a_pris == 0)
        {
            return 1;
        }
        else
        {
            return a_pris;
        }
    }
    else
    {
        if (reste == 1)
        {
            return 1;
        }

        a_pris = (reste - 1) % 4;

        if (a_pris == 0)
        {
            return 1;
        }
        else
        {
            return a_pris;
        }
    }
}

/**
 * Fonction qui gère le tour du joueur humain
 * @param reste Le nombre de bâtons restants sur le plateau
 * @return Le nombre de bâtons que le joueur humain décide de prendre
 */
int TourHumain(int reste)
{
    int nbBatonsPris = 0;
    printf("\nCombien de bâtons voulez-vous prendre (1, 2 ou 3) ? ");
    nbBatonsPris = LireEntier();

    while (nbBatonsPris < 1 || nbBatonsPris > 3 || nbBatonsPris > reste)
    {
        printf("\nErreur dans le choix du nombre de batons.\n");
        printf("Il reste %d bâtons. Combien voulez-vous en prendre (1, 2 ou 3) ? ", reste);
        nbBatonsPris = LireEntier();
    }

    return nbBatonsPris;
}

/**
 * Fonction qui paramètre la partie en fonction du mode choisi
 * @param mode Le mode de jeu choisi par l'utilisateur
 * @param nomJoueur1 Pointeur vers la chaîne de caractères pour le nom du joueur 1
 * @param nomJoueur2 Pointeur vers la chaîne de caractères pour le nom du joueur 2
 * @return Le numéro du joueur qui commence la partie (1 ou 2)
 */
int parametragePartie(int mode, char *nomJoueur1, char *nomJoueur2)
{

    int choixUtilisateur;
    int c;

    // Determine le nombre de bâtons
    printf("\nAvec combien de bâtons voulez-vous jouer au début ? ");
    NbBatons = LireEntier();

    while (NbBatons <= 0)
    {
        printf("\nLe nombre de bâtons doit être superieur à 0.\n");
        printf("Avec combien de bâtons voulez-vous jouer au début ? ");
        NbBatons = LireEntier();
    }

    // Determine la regle de victoire
    printf("\nAvec quel règle voulez-vous jouez :\n");
    printf("1. Celui qui prend le dernier baton gagne\n");
    printf("2. Celui qui prend le dernier baton perd\n");
    printf("Votre choix (1 ou 2) : ");
    regleVictoire = LireEntier();

    while (regleVictoire < 1 || regleVictoire > 2)
    {
        printf("\nErreur dans le choix de la règle de victoire.\n");
        printf("Avec quel règle voulez-vous jouez :\n");
        printf("1. Celui qui prend le dernier baton gagne\n");
        printf("2. Celui qui prend le dernier baton perd\n");
        printf("Votre choix (1 ou 2) : ");
        regleVictoire = LireEntier();
    }

    // Definir qui commence
    switch (mode)
    {
    case 1:
        strcpy(nomJoueur1, "Robot Naif 1");
        strcpy(nomJoueur2, "Robot Naif 2");
        printf("\nLa simulation va commencer.Le Robot Naif 1 commence.\n");
        return 1;

    case 2:
        strcpy(nomJoueur1, "Robot Naif");
        strcpy(nomJoueur2, "Robot Intelligent");

        printf("\nQui doit commencer :\n");
        printf("1. %s\n", nomJoueur1);
        printf("2. %s\n", nomJoueur2);
        printf("Votre choix (1 ou 2): ");

        choixUtilisateur = LireEntier();

        while (choixUtilisateur < 1 || choixUtilisateur > 2)
        {
            printf("\nErreur dans le choix du joueur qui commence.\n");
            printf("Qui doit commencer :\n");
            printf("1. %s\n", nomJoueur1);
            printf("2. %s\n", nomJoueur2);
            printf("Votre choix (1 ou 2): ");
            choixUtilisateur = LireEntier();
        }

        return choixUtilisateur;

    case 4:
        strcpy(nomJoueur1, "Robot Intelligent 1");
        strcpy(nomJoueur2, "Robot Intelligent 2");
        printf("\nLa simulation va commencer.Le Robot Intelligent 1 commence.\n");
        return 1;

    case 3:
    case 5:

        if (mode == 3)
        {
            strcpy(nomJoueur1, "Robot Naif");
            strcpy(nomJoueur2, "Joueur Humain");
        }
        else
        {
            strcpy(nomJoueur1, "Robot Intelligent");
            strcpy(nomJoueur2, "Joueur Humain");
        }

        int choixUtilisateurC;
        printf("\nVoulez-vous commencer ?\n1. Oui\n2. Non\nVotre choix (1 ou 2): ");
        choixUtilisateurC = LireEntier();

        while (choixUtilisateurC != 1 && choixUtilisateurC != 2)
        {
            printf("\nChoix invalide.\n");
            choixUtilisateurC = LireEntier();
        }

        printf("\nVoulez-vous vous nommer ?\n1. Oui\n2. Non\nVotre choix (1 ou 2): ");
        choixUtilisateur = LireEntier();

        while (choixUtilisateur != 1 && choixUtilisateur != 2)
        {
            printf("\nChoix invalide. Veuillez taper 1 ou 2 :\n");
            choixUtilisateur = LireEntier();
        }

        if (choixUtilisateur == 1)
        {
            printf("Entrez votre nom : ");
            scanf(" %49[^\n]", nomJoueur2);

            while ((c = getchar()) != '\n' && c != EOF)
                ;

            printf("Bienvenue, %s !\n", nomJoueur2);

            if (choixUtilisateurC == 1)
            {
                return 2; // Le joueur commence
            }
            else
            {
                return 1; // Le robot commence
            }
        }

        if (choixUtilisateurC == 1)
        {
            return 2; // Le joueur commence
        }
        else
        {
            return 1; // Le robot commence
        }

    case 6:
        strcpy(nomJoueur1, "Joueur 1");
        strcpy(nomJoueur2, "Joueur 2");

        printf("\nQui doit commencer :\n");
        printf("1. Joueur 1\n");
        printf("2. Joueur 2\n");
        printf("Votre choix (1 ou 2): ");
        choixUtilisateur = LireEntier();

        while (choixUtilisateur < 1 || choixUtilisateur > 2)
        {
            printf("\nErreur dans le choix du joueur qui commence.\n");
            printf("Qui doit commencer :\n");
            printf("1. Joueur 1\n");
            printf("2. Joueur 2\n");
            printf("Votre choix (1 ou 2): ");
            choixUtilisateur = LireEntier();
        }

        int choixUtilisateurNom;
        printf("\nVoulez-vous nommez les joueurs ?\n1. Oui\n2. Non\nVotre choix (1 ou 2): ");
        choixUtilisateurNom = LireEntier();

        while (choixUtilisateurNom != 1 && choixUtilisateurNom != 2)
        {
            printf("\nChoix invalide. Veuillez taper 1 ou 2 :\n");
            choixUtilisateurNom = LireEntier();
        }

        if (choixUtilisateurNom == 1)
        {

            printf("Entrez le nom du Joueur 1 : ");
            scanf(" %49[^\n]", nomJoueur1);
            while ((c = getchar()) != '\n' && c != EOF)
                ;

            printf("Entrez le nom du Joueur 2 : ");
            scanf(" %49[^\n]", nomJoueur2);
            while ((c = getchar()) != '\n' && c != EOF)
                ;

            printf("Bienvenue, %s et %s !\n", nomJoueur1, nomJoueur2);
        }

        return choixUtilisateur;

    default:
        return 1;
        break;
    }
}

/**
 * Fonction qui détermine le type de joueur en fonction du mode choisi
 * @param numJoueur Le numéro du joueur (1 ou 2)
 * @param mode Le mode de jeu choisi par l'utilisateur
 * @return Le type de joueur (0: Naif, 1: Intelligent, 2: Humain)
 */
int getTypeDeJoueur(int numJoueur, int mode)
{

    int Naif = 0;
    int Intelligent = 1;
    int Humain = 2;

    if (numJoueur == 1)
    {
        if (mode == 1 || mode == 2 || mode == 3)
        {
            return Naif;
        }
        else if (mode == 4 || mode == 5)
        {
            return Intelligent;
        }
        else
        {
            return Humain;
        }
    }
    else
    {
        if (mode == 1)
        {
            return Naif;
        }
        else if (mode == 2 || mode == 4)
        {
            return Intelligent;
        }
        else
        {
            return Humain;
        }
    }
}

/**
 * Fonction qui gère le déroulement de la partie
 * @param mode Le mode de jeu choisi par l'utilisateur
 * @param quiCommence Le numéro du joueur qui commence la partie (1 ou 2)
 * @param nomJoueur1 Pointeur vers la chaîne de caractères pour le nom du joueur 1
 * @param nomJoueur2 Pointeur vers la chaîne de caractères pour le nom du joueur 2
 */
void deroulementPartie(int mode, int quiCommence, char *nomJoueur1, char *nomJoueur2)
{

    int typeJoueur1 = getTypeDeJoueur(1, mode);
    int typeJoueur2 = getTypeDeJoueur(2, mode);

    int joueurActuel = quiCommence;
    int typeDuJoueurActuel;
    int nbBatonsPris;

    while (NbBatons > 0)
    {

        if (joueurActuel == 1)
        {
            typeDuJoueurActuel = typeJoueur1;
        }
        else
        {
            typeDuJoueurActuel = typeJoueur2;
        }

        if (joueurActuel == 1)
        {
            printf("\n--- Tour de %s (Il reste %d bâtons) ---\n", nomJoueur1, NbBatons);
        }
        else
        {
            printf("\n--- Tour de %s (Il reste %d bâtons) ---\n", nomJoueur2, NbBatons);
        }

        if (typeDuJoueurActuel == 0)
        {
            nbBatonsPris = RobotNaif();
            printf("Le Robot Naif prend %d bâtons.\n", nbBatonsPris);
        }
        else if (typeDuJoueurActuel == 1)
        {
            nbBatonsPris = RobotIntelligent(NbBatons, regleVictoire);
            printf("Le Robot Intelligent prend %d bâtons.\n", nbBatonsPris);
        }
        else
        {
            nbBatonsPris = TourHumain(NbBatons);
        }

        NbBatons = NbBatons - nbBatonsPris;

        if (NbBatons <= 0)
        {
            annoncerVainqueur(joueurActuel, regleVictoire, nomJoueur1, nomJoueur2);
            break;
        }

        if (joueurActuel == 1)
        {
            joueurActuel = 2;
        }
        else
        {
            joueurActuel = 1;
        }
    }
}

/**
 * Fonction qui annonce le vainqueur de la partie
 * @param joueurQuiVientDeJouer Le numéro du joueur qui vient de jouer (1 ou 2)
 * @param regle La règle de victoire (1: dernier bâton gagne, 2: dernier bâton perd)
 * @param nomJoueur1 Pointeur vers la chaîne de caractères pour le nom du joueur 1
 * @param nomJoueur2 Pointeur vers la chaîne de caractères pour le nom du joueur 2
 */
void annoncerVainqueur(int joueurQuiVientDeJouer, int regle, char *nomJ1, char *nomJ2)
{

    if (regle == 1)
    {
        if (joueurQuiVientDeJouer == 1)
        {
            printf("\n%s a pris le dernier bâton et GAGNE !!\n", nomJ1);
        }
        else
        {
            printf("\n%s a pris le dernier bâton et GAGNE !!\n", nomJ2);
        }
    }
    else
    {
        if (joueurQuiVientDeJouer == 1)
        {
            printf("\n%s a pris le dernier bâton et PERD ! %s a donc GAGNÉ !!\n", nomJ1, nomJ2);
        }
        else
        {
            printf("\n%s a pris le dernier bâton et PERD ! %s a donc GAGNÉ !!\n", nomJ2, nomJ1);
        }
    }
}

/**
 * Fonction qui lit un entier depuis l'entrée standard avec gestion des erreurs
 * @return L'entier lu
 */
int LireEntier()
{
    int valeur;
    int nbLus = 0;

    while (nbLus != 1)
    {

        nbLus = scanf("%d", &valeur);
        if (nbLus != 1)
        {
            printf("Entrée invalide. Veuillez entrer un entier : ");

            int c;
            while ((c = getchar()) != '\n' && c != EOF)
            {
            }
        }
    }
    return valeur;
}

/*------Main------*/

int main(int argc, char **argv)
{

    // --- Variables de configuration ---
    int modeDeJeu = -1;
    int joueurDeDepart = 0;

    char nomJoueur1[50];
    char nomJoueur2[50];

    // --- Initialisation de l'aléatoire ---
    srand(time(NULL));

    // --- Boucle de jeu principale ---
    while (modeDeJeu != 0)
    {

        printf("--- Bienvenue au Jeu de Nim ---\n");
        printf("Veuillez choisir votre mode de jeu :\n");
        printf("1. Robot Naif vs Robot Naif\n");
        printf("2. Robot Naif vs Robot Intelligent\n");
        printf("3. Robot Naif vs Joueur\n");
        printf("4. Robot Intelligent vs Robot Intelligent\n");
        printf("5. Robot Intelligent vs Joueur\n");
        printf("6. Joueur vs Joueur\n");
        printf("---------------------------------\n");
        printf("0. Quitter le programme.\n");

        modeDeJeu = -1;

        while (modeDeJeu < 0 || modeDeJeu > 6)
        {
            printf("Votre choix (0-6) : ");
            modeDeJeu = LireEntier();

            if (modeDeJeu < 0 || modeDeJeu > 6)
            {
                printf("Choix invalide.\n");
            }
        }

        if (modeDeJeu != 0)
        {

            // --- Paramétrage de la partie ---
            joueurDeDepart = parametragePartie(modeDeJeu, nomJoueur1, nomJoueur2);

            // --- Lancement de la partie ---
            printf("\n--- La partie commence ! ---\n");
            deroulementPartie(modeDeJeu, joueurDeDepart, nomJoueur1, nomJoueur2);

            // --- Fin de cette partie ---
            printf("\n--- Partie terminee. Retour au menu principal... ---\n\n");
        }
    }

    // --- Fin du programme ---
    printf("\n--- Au revoir ! ---\n");
    return 0;
}