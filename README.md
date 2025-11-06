# Projet : Jeu de Nim en C

Ce dépôt contient deux implémentations en C du classique Jeu de Nim, réalisées dans le cadre de ma première année de BUT Informatique.

- **`jeu_de_nim_sae.c`** : version originale du projet, répondant au cahier des charges initial de la SAÉ.  
- **`jeu_de_nim_avance.c`** : version personnelle, largement améliorée, pour pratiquer la structuration du code, la gestion de la complexité et l’ajout de fonctionnalités complètes.

---

## Comparaison des fonctionnalités

| Fonctionnalité              | Version de Base (SAÉ)                     | Version Avancée                                       |
|-----------------------------|-------------------------------------------|-------------------------------------------------------|
| **Modes de jeu**            | 1 seul (Robot Naïf vs Robot Intelligent)  | 6 modes (HvsH, HvsIA, IAvsIA)                         |
| **Nombre de bâtons**        | Fixe (ex : 16)                            | Choisi par l’utilisateur                              |
| **Règle de victoire**       | Fixe (le dernier gagne)                   | Choix : le dernier gagne ou perd                      |
| **Choix du 1er joueur**     | Non                                       | Oui (logique adaptée au mode)                         |
| **Rejouer**                 | Non (une seule partie)                    | Oui (boucle de jeu principale)                        |
| **Structure du code**       | Un seul bloc `main`                       | Modulaire (`main`, `deroulementPartie`, `parametragePartie`, etc.) |

---

## Structure du dépôt



├── jeu_de_nim_sae.c     # Version scolaire originale  
├── jeu_de_nim_avance.c   # Version complète et améliorée  
└── Makefile              # Fichier de compilation  

---

## Compilation et utilisation

Un **Makefile** est inclus pour compiler les deux versions facilement.

### 1. Compilation

Pour compiler les deux versions (crée les exécutables `jeu_de_nim_sae` et `jeu_de_nim_avance`) :

    make all

Pour compiler uniquement la version avancée :

    make jeu_de_nim_avance

Pour compiler uniquement la version de base :

    make jeu_de_nim_sae

Pour nettoyer (supprimer les exécutables) :

    make clean

---

### 2. Lancement

Une fois compilé, vous pouvez lancer le jeu de votre choix :

    # Lancer la version avancée
    ./jeu_de_nim_avance

    # Lancer la version de base
    ./jeu_de_nim_base
