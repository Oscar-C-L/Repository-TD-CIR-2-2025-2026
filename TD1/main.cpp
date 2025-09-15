//Exercice1:

#include <stdlib.h>
#include <stdio.h>

int main(){
  printf("hello world\n");
  return EXIT_SUCCESS;
}




//Exercie2: 

#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;
    double delta, x1, x2, re, im;

    printf("Résolution de l'équation ax² + bx + c = 0\n");
    printf("Entrez les coefficients a, b et c : ");
    scanf("%lf %lf %lf", &a, &b, &c);

    if (a == 0) {
        if (b == 0) {
            if (c == 0)
                printf("Infinité de solutions (équation indéterminée).\n");
            else
                printf("Pas de solution (équation impossible).\n");
        } else {
            x1 = -c / b;
            printf("Équation du premier degré. Solution unique : x = %.2lf\n", x1);
        }
    } else {
        delta = b * b - 4 * a * c;

        if (delta > 0) {
            x1 = (-b + sqrt(delta)) / (2 * a);
            x2 = (-b - sqrt(delta)) / (2 * a);
            printf("Deux racines réelles distinctes : x1 = %.2lf et x2 = %.2lf\n", x1, x2);
        } else if (delta == 0) {
            x1 = -b / (2 * a);
            printf("Une racine réelle double : x = %.2lf\n", x1);
        } else {
            re = -b / (2 * a);
            im = sqrt(-delta) / (2 * a);
            printf("Deux racines complexes : x1 = %.2lf + %.2lfi et x2 = %.2lf - %.2lfi\n",
                   re, im, re, im);
        }
    }

    return 0;


//Exercice3: 

def minuscule(caractere: str) -> str:
    if len(caractere) != 1:
        raise ValueError("give one caractere or consequences.")

    if 'A' <= caractere <= 'Z':
        return chr(ord(caractere) + 32)  # Décalage ASCII entre maj et min
    else:
        return caractere


//Exercice4:

    // Factorielle avec une boucle for
def factorielle_for(n: int) -> int:
    resultat = 1
    for i in range(1, n + 1):
        resultat *= i
    return resultat

// Factorielle avec une boucle while
def factorielle_while(n: int) -> int:
    resultat = 1
    i = 1
    while i <= n:
        resultat *= i
        i += 1
    return resultat

// Factorielle en récursif
def factorielle_recursive(n: int) -> int:
    if n == 0 or n == 1:
        return 1
    else:
        return n * factorielle_recursive(n - 1)


//Exercice5:

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TENTATIVES 10
#define MAX_MOT 50

    int main() {
        char motSecret[MAX_MOT];
        char motAffiche[MAX_MOT];
        char lettre;
        int tentativesRestantes = MAX_TENTATIVES;
        int longueur, trouve = 0;

        // Saisie du mot secret
        printf("Entrez le mot secret (hihi) : ");
        scanf("%s", motSecret);

        longueur = strlen(motSecret);

        // Initialisation du mot affiché avec des '_'
        for (int i = 0; i < longueur; i++) {
            motAffiche[i] = '_';
        }
        motAffiche[longueur] = '\0';

        
        // system("cls");   

        printf("\n=== Jeu du Pendu ===\n");
        printf("Vous avez %d tentatives.\n", tentativesRestantes);

        // Boucle de jeu
        while (tentativesRestantes > 0 && !trouve) {
            printf("\nMot à deviner : %s\n", motAffiche);
            printf("Proposez une lettre : ");
            scanf(" %c", &lettre);
            lettre = toupper(lettre); // Normalisation en majuscule

            int bonneLettre = 0;
            for (int i = 0; i < longueur; i++) {
                if (toupper(motSecret[i]) == lettre && motAffiche[i] == '_') {
                    motAffiche[i] = motSecret[i];
                    bonneLettre = 1;
                }
            }

            if (!bonneLettre) {
                tentativesRestantes--;
                printf("Mauvaise lettre ! Il vous reste %d tentatives.\n", tentativesRestantes);
            }

            // Vérifier si le mot est trouvé
            if (strcmp(motSecret, motAffiche) == 0) {
                trouve = 1;
            }
        }

        // Fin du jeu
        if (trouve) {
            printf("\nBravo ! Vous avez trouvé le mot : %s\n", motSecret);
        }
        else {
            printf("\nPerdu ! Le mot était : %s\n", motSecret);
        }

        return 0;
    }


    //Exercice6:
//Le premier programme imprime 4     
//Le second programme imprime 4
//L'instruction "x+=1" est exécutée 0 fois 


//Exercice 7 : 

import random

n = int(input("Entrez le nombre d'éléments du tableau : "))

//Remplissage aléatoire du tableau avec des entiers entre 0 et 100
tableau = [random.randint(0, 100) for _ in range(n)]

print("\nTableau généré aléatoirement :")
print(tableau)

tableau_trie = sorted(tableau)

print("\nTableau trié en ordre croissant :")
print(tableau_trie)


//Exercie8:
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Fonction pour allouer un tableau 2D
int** allouer_tableau_2d(int n, int m) {
    int** tableau = (int**)malloc(n * sizeof(int*));
    if (tableau == NULL) {
        printf("Erreur d'allocation mémoire\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        tableau[i] = (int*)malloc(m * sizeof(int));
        if (tableau[i] == NULL) {
            printf("Erreur d'allocation mémoire\n");
            exit(1);
        }
    }

    return tableau;
}

// Fonction pour libérer la mémoire
void liberer_tableau_2d(int** tableau, int n) {
    for (int i = 0; i < n; i++) {
        free(tableau[i]);
    }
    free(tableau);
}

// Fonction pour initialiser avec des valeurs aléatoires
void initialiser_aleatoire(int** tableau, int n, int m) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            tableau[i][j] = rand() % 100; // Valeurs entre 0 et 99
        }
    }
}

// Fonction pour afficher le tableau
void afficher_tableau(int** tableau, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%3d ", tableau[i][j]);
        }
        printf("\n");
    }
}

// Fonction de tri par insertion pour une colonne
void trier_colonne(int** tableau, int n, int colonne) {
    for (int i = 1; i < n; i++) {
        int cle = tableau[i][colonne];
        int j = i - 1;

        // Déplacer les éléments plus grands que la clé vers le bas
        while (j >= 0 && tableau[j][colonne] > cle) {
            tableau[j + 1][colonne] = tableau[j][colonne];
            j--;
        }
        tableau[j + 1][colonne] = cle;
    }
}

// Fonction pour trier toutes les colonnes
void trier_colonnes(int** tableau, int n, int m) {
    for (int j = 0; j < m; j++) {
        trier_colonne(tableau, n, j);
    }
}

int main() {
    int n, m;

    printf("Entrez le nombre de lignes (n): ");
    scanf("%d", &n);
    printf("Entrez le nombre de colonnes (m): ");
    scanf("%d", &m);

    // Allocation du tableau
    int** tableau = allouer_tableau_2d(n, m);

    // Initialisation avec des valeurs aléatoires
    initialiser_aleatoire(tableau, n, m);

    printf("\nTableau avant le tri:\n");
    afficher_tableau(tableau, n, m);

    // Tri colonne par colonne
    trier_colonnes(tableau, n, m);

    printf("\nTableau après le tri (colonne par colonne):\n");
    afficher_tableau(tableau, n, m);

    // Libération de la mémoire
    liberer_tableau_2d(tableau, n);

    return 0;
}