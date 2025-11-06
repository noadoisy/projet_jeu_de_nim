/* ---------------------------------------------------------------------
 * Auteur : DOISY Noa BUT 1 Informatique 
 * Date de Création : 09 sept 2024
 ------------------------------------------------------------------------*/

#include <stdio.h>    // Inclus pour les opérations d'entrée/sortie (printf)
#include <stdlib.h>   // Inclus pour les fonctions utilitaires (rand, srand)
#include <stdbool.h>  // Inclus pour utiliser des types booléens (true, false)
#include <time.h>     // Inclus pour utiliser time() afin d'initialiser le générateur aléatoire

/*--------- Prototypes des fonctions ---------*/

int RobotNaif(void);
int RobotIntelligent(int reste, int regle);
int TourHumain(int reste);
int parametragePartie(int mode);
int getTypeDeJoueur(int numJoueur, int mode);
void deroulementPartie(int mode, int quiCommence);
void annoncerVainqueur(int joueurQuiVientDeJouer, int regle);


/*---------Lexique---------*/

int NbBatons;        // Nombre de bâtons sur le plateau de jeu
int regleVictoire;   // Stock l'entier represantant la regle de victoire

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
 * @param reste Le nombre de bâtons restants sur le plateau
 * @param regle La règle de victoire (1: dernier bâton gagne, 2: dernier bâton perd)
 * @return Le nombre de bâtons que le joueur intelligent décide de prendre
 */
int RobotIntelligent(int reste, int regle) {
    
    int a_pris;

    if (regle==1){
        a_pris = reste % 4;

        if (a_pris == 0){return 1;}
        else{return a_pris;}
    }
    else{
        if (reste == 1){
            return 1;
        }

        a_pris = (reste - 1) % 4;

        if (a_pris==0){return 1;}
        else{return a_pris;}
    }
    
}

/**
 * Fonction qui gère le tour d'un joueur humain
 * @param reste Le nombre de bâtons restants sur le plateau
 * @return Le nombre de bâtons que le joueur humain décide de prendre    
 */
int TourHumain(int reste){
    int nbBatonsPris = 0;
    printf("\nCombien de bâtons voulez-vous prendre (1, 2 ou 3) ? ");
    scanf("%d",&nbBatonsPris);
    
    while( nbBatonsPris < 1 || nbBatonsPris > 3 || nbBatonsPris > reste){
        printf("\nErreur dans le choix du nombre de batons.\n");
        printf("Il reste %d bâtons. Combien voulez-vous en prendre (1, 2 ou 3) ? ",reste);
        scanf("%d",&nbBatonsPris);
    }

    return nbBatonsPris;
}

/**
 * Fonction qui paramètre la partie en fonction du mode choisi
 * @param mode Le mode de jeu choisi par l'utilisateur
 * @return Le numéro du joueur qui commence la partie
 */
int parametragePartie(int mode){

    int choixUtilisateur;

    // Determine le nombre de bâtons
    printf("\nAvec combien de bâtons voulez-vous jouer au début ? ");
    scanf("%d", &NbBatons);

    while (NbBatons <= 0)
    {
        printf("\nLe nombre de bâtons doit être superieur à 0.\n");
        printf("Avec combien de bâtons voulez-vous jouer au début ? ");
        scanf("%d", &NbBatons);
    }

    //Determine la regle de victoire
    printf("\nAvec quel règle voulez-vous jouez :\n");
    printf("1. Celui qui prend le dernier baton gagne\n");
    printf("2. Celui qui prend le dernier baton perd\n");
    printf("Votre choix (1 ou 2) : ");
    scanf("%d",&regleVictoire);

    while(regleVictoire != 1 && regleVictoire != 2){
        printf("\nVous devez choisir uniquement entre 1 et 2.\n");
        printf("Avec quel règle voulez-vous jouez :\n");
        printf("1. Celui qui prend le dernier baton gagne\n");
        printf("2. Celui qui prend le dernier baton perd\n");
        printf("Votre choix (1 ou 2) : ");
        scanf("%d",&regleVictoire);

    }

    //Definir qui commence
    switch (mode)
    {
    case 1:
    case 4:
        printf("\nLa simulation va commencer. Le Joueur 1 débute.\n");
        return 1;
    case 2:
        printf("\nQui doit commencer :\n");
        printf("1. Robot Naif\n");
        printf("2. Robot Intelligent\n");
        printf("Votre choix (1 ou 2): ");
        scanf("%d",&choixUtilisateur);
        return choixUtilisateur;
    case 3:
    case 5:
        printf("\nVoulez-vous commencer ?\n1. Oui\n2. Non\nVotre choix (1 ou 2): ");
        scanf("%d",&choixUtilisateur);

        if (choixUtilisateur == 1) {return 2;} // Le joueur commence
        else{return 1;}; // Le robot commence
    
    case 6: 
        printf("\nQui doit commencer :\n");
        printf("1. Joueur 1\n");
        printf("2. Joueur 2\n");
        printf("Votre choix (1 ou 2): ");
        scanf("%d",&choixUtilisateur);
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
int getTypeDeJoueur(int numJoueur, int mode){
    
    int Naif = 0;
    int Intelligent = 1;
    int Humain = 2;

    if(numJoueur==1){
        if(mode == 1 || mode == 2 || mode==3){return Naif;}
        else if (mode==4 || mode==5){return Intelligent;}
        else{return Humain;}
    }
    else{
        if (mode==1){return Naif;}
        else if (mode == 2||mode==4){return Intelligent;}
        else{return Humain;}
    }
}

/**
 * Fonction qui gère le déroulement de la partie
 * @param mode Le mode de jeu choisi par l'utilisateur
 * @param quiCommence Le numéro du joueur qui commence la partie
 */
void deroulementPartie(int mode, int quiCommence){

    int typeJoueur1 = getTypeDeJoueur(1,mode);
    int typeJoueur2 = getTypeDeJoueur(2,mode);

    int joueurActuel = quiCommence;
    int typeDuJoueurActuel;
    int nbBatonsPris;

    while(NbBatons > 0){
        
        if (joueurActuel == 1){
            typeDuJoueurActuel = typeJoueur1;
        }else{
            typeDuJoueurActuel = typeJoueur2;
        }

        printf("\n--- Tour du Joueur %d (Il reste %d bâtons) ---\n",joueurActuel,NbBatons);

        if (typeDuJoueurActuel==0){
            nbBatonsPris = RobotNaif();
            printf("Le Robot Naif prend %d bâtons.\n",nbBatonsPris);
        }
        else if (typeDuJoueurActuel==1){
            nbBatonsPris = RobotIntelligent(NbBatons,regleVictoire);
            printf("Le Robot Intelligent prend %d bâtons.\n",nbBatonsPris);   
        }
        else{
            nbBatonsPris = TourHumain(NbBatons);
        }

        NbBatons = NbBatons - nbBatonsPris;

        if (NbBatons <= 0){
            annoncerVainqueur(joueurActuel, regleVictoire);
            break;
        }

        if (joueurActuel ==1){joueurActuel=2;}
        else{joueurActuel=1;}
    }
}

/**
 * Fonction qui annonce le vainqueur de la partie
 * @param joueurQuiVientDeJouer Le numéro du joueur qui vient de jouer
 * @param regle La règle de victoire (1: dernier bâton gagne, 2: dernier bâton perd)
 */
void annoncerVainqueur(int joueurQuiVientDeJouer, int regle){
    if (regle==1){
        printf("\nLe Joueur %d a pris le dernier bâton et GAGNE !!\n",joueurQuiVientDeJouer);
    }
    else{
        if (joueurQuiVientDeJouer ==1){
            printf("\nLe Joueur 1 a pris le dernier bâton et PERD ! Le Joueur 2 a donc GAGNÉ !!\n");
        }
        else{
            printf("\nLe Joueur 2 a pris le dernier bâton et PERD ! Le Joueur 1 a donc GAGNÉ !!\n");
        }
    }
}


/*------Main------*/

int main(int argc, char** argv) {

    // --- 1. Variables de configuration ---
    int modeDeJeu = -1; // Initialisé à -1 pour entrer dans la boucle
    int joueurDeDepart = 0;

    // --- 2. Initialisation de l'aléatoire (UNE SEULE FOIS) ---
    srand(time(NULL));

    // --- 3. Boucle de jeu principale ---
    while (modeDeJeu != 0) {
    
        // --- 3a. Choix du Mode de Jeu ---
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

        // --- 3b. Boucle de validation (Corrigée pour accepter 0) ---
        modeDeJeu = -1; // Réinitialise le choix pour la boucle de validation
        while (modeDeJeu < 0 || modeDeJeu > 6) { // BUG 1 CORRIGÉ
            printf("Votre choix (0-6) : ");
            scanf("%d", &modeDeJeu);
            if (modeDeJeu < 0 || modeDeJeu > 6) {
                printf("Choix invalide.\n");
            }
        }

        // --- 3c. Agir sur le choix (BUG 2 CORRIGÉ) ---
        if (modeDeJeu != 0) {
            // L'utilisateur veut jouer (1-6)
            
            // --- Paramétrage de la partie ---
            joueurDeDepart = parametragePartie(modeDeJeu);

            // --- Lancement de la partie ---
            printf("\n--- La partie commence ! ---\n");
            deroulementPartie(modeDeJeu, joueurDeDepart);

            // --- Fin de cette partie ---
            printf("\n--- Partie terminee. Retour au menu principal... ---\n\n");
        
        } 
        
    } // Fin de la boucle while (modeDeJeu != 0)


    // --- 6. Fin du programme ---
    printf("\n--- Au revoir ! ---\n");
    return 0;
}