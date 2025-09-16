/ Exercice 1 :

#include <iostream.h>
#define consteval multiplier(x,y)(x*y)
int main(void) {
    int a;
    int b;
    cout << "Entrez une valeur:" << endl;
    cin << a;
    cout << "Entrez une autre valeur:" < endl;
    cin << b;

    cout << constexpr multiplier(a + 1, b + 1) << endl;
}





//Exercie 2 : 
#include <iostream>
using namespace std;

int main() {
    int nombre;

    cout << "Entrez un chiffre entre 1 et 9 : ";
    cin >> nombre;

    if (nombre < 1 || nombre > 9) {
        cout << "Erreur : Le chiffre doit être entre 1 et 9." << endl;
        return 1;
    }

    // Afficher la table de multiplication
    cout << "\nTable de multiplication de " << nombre << " :" << endl;
    cout << "---------------------------" << endl;

    for (int i = 1; i <= 10; i++) {
        cout << nombre << " x " << i << " = " << (nombre * i) << endl;
    }

    return 0;
}


#include <iostream>
#include <iomanip> // pour setw

using namespace std;

int main() {
    const int N = 10; // taille de la table

    // En-tête
    cout << setw(4) << " ";
    for (int j = 1; j <= N; j++) {
        cout << setw(4) << j;
    }
    cout << endl;

    // Ligne de séparation
    cout << setw(4) << "----";
    for (int j = 1; j <= N; j++) {
        cout << "----";
    }
    cout << endl;


    for (int i = 1; i <= N; i++) {
        cout << setw(4) << i << "|";  // afficher le multiplicateur
        for (int j = 1; j <= N; j++) {
            cout << setw(4) << i * j;
        }
        cout << endl;
    }

    return 0;
}

//Exercice 3 : 

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype> // pour isalpha

using namespace std;

int main() {
    string nomFichier;
    cout << "Entrez le nom du fichier à analyser : ";
    cin >> nomFichier;

    ifstream fichier(nomFichier);
    if (!fichier) {
        cerr << "Erreur : impossible d'ouvrir le fichier " << nomFichier << endl;
        return 1;
    }

    int nbLignes = 0;
    int nbMots = 0;
    int nbLettres = 0;
    string ligne;

    while (getline(fichier, ligne)) {
        nbLignes++;

        // Utilisation de stringstream pour découper la ligne en mots
        stringstream ss(ligne);
        string mot;
        while (ss >> mot) {
            nbMots++;

            // Compter uniquement les lettres alphabétiques
            for (char c : mot) {
                if (isalpha(static_cast<unsigned char>(c))) {
                    nbLettres++;
                }
            }
        }
    }

    fichier.close();

    cout << "Analyse du fichier : " << nomFichier << endl;
    cout << "Nombre de lignes  : " << nbLignes << endl;
    cout << "Nombre de mots    : " << nbMots << endl;
    cout << "Nombre de lettres : " << nbLettres << endl;

    return 0;
}


//Exercie 4 : 