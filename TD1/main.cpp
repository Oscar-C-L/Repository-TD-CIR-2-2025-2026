#Exercice1:

#include <stdlib.h>
#include <stdio.h>

int main(){
  printf("hello world\n");
  return EXIT_SUCCESS;
}




#Exercie2: 

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


#Exercice3: 

def minuscule(caractere: str) -> str:
    # Vérification : on s'assure que c'est bien un caractère unique
    if len(caractere) != 1:
        raise ValueError("Veuillez fournir un seul caractère.")

    # Si c'est une majuscule (A-Z), on la convertit en minuscule
    if 'A' <= caractere <= 'Z':
        return chr(ord(caractere) + 32)  # Décalage ASCII entre maj et min
    else:
        return caractere
