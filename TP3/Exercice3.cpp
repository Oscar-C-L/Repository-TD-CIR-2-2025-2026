class Vecteur {
private:
    double vx, vy, vz; // Composantes du vecteur
    bool is3D;         // Vrai si c'est un vecteur 3D, faux si 2D

public:
    // Constructeur par défaut (vecteur nul 2D)
    Vecteur() : vx(0.0), vy(0.0), vz(0.0), is3D(false) {}

    // Constructeur pour un vecteur 2D à partir de deux Point2D
    Vecteur(const Point2D& p1, const Point2D& p2) : is3D(false) {
        vx = p2.x - p1.x;
        vy = p2.y - p1.y;
        vz = 0.0; // Pour les vecteurs 2D, z est toujours 0
    }

    // Constructeur pour un vecteur 3D à partir de deux Point3D
    Vecteur(const Point3D& p1, const Point3D& p2) : is3D(true) {
        vx = p2.x - p1.x;
        vy = p2.y - p1.y;
        vz = p2.z - p1.z;
    }

    // Constructeur avec des composantes explicites (par défaut 2D)
    Vecteur(double x, double y) : vx(x), vy(y), vz(0.0), is3D(false) {}

    // Constructeur avec des composantes explicites 3D
    Vecteur(double x, double y, double z) : vx(x), vy(y), vz(z), is3D(true) {}

    // Méthode pour obtenir les composantes (utile pour l'affichage ou d'autres calculs)
    double getVx() const { return vx; }
    double getVy() const { return vy; }
    double getVz() const { return vz; }
    bool isVector3D() const { return is3D; }

    // Calculer la somme de deux vecteurs (surcharge de l'opérateur +)
    // On suppose que les vecteurs sont du même type (2D ou 3D) pour l'addition.
    // Si ce n'est pas le cas, vous pourriez vouloir lever une erreur ou adapter.
    Vecteur operator+(const Vecteur& autre) const {
        if (is3D != autre.is3D) {
            std::cerr << "Erreur: Tentative d'addition de vecteurs de dimensions différentes." << std::endl;
            // Retourne un vecteur nul du type du premier vecteur pour éviter un crash
            return is3D ? Vecteur(0, 0, 0) : Vecteur(0, 0);
        }
        if (is3D) {
            return Vecteur(vx + autre.vx, vy + autre.vy, vz + autre.vz);
        }
        else {
            return Vecteur(vx + autre.vx, vy + autre.vy);
        }
    }

    // Calculer le produit par un réel (surcharge de l'opérateur *)
    Vecteur operator*(double scalaire) const {
        if (is3D) {
            return Vecteur(vx * scalaire, vy * scalaire, vz * scalaire);
        }
        else {
            return Vecteur(vx * scalaire, vy * scalaire);
        }
    }

    // Vérifier l’égalité entre deux vecteurs (surcharge de l'opérateur ==)
    bool operator==(const Vecteur& autre) const {
        // Les vecteurs doivent être du même type (2D ou 3D) pour être égaux
        if (is3D != autre.is3D) {
            return false;
        }
        // Comparaison avec une tolérance pour les nombres flottants
        const double EPSILON = 1e-9;
        if (is3D) {
            return (std::abs(vx - autre.vx) < EPSILON &&
                std::abs(vy - autre.vy) < EPSILON &&
                std::abs(vz - autre.vz) < EPSILON);
        }
        else {
            return (std::abs(vx - autre.vx) < EPSILON &&
                std::abs(vy - autre.vy) < EPSILON);
        }
    }

    // Opérateur d'inégalité (déduit de l'égalité)
    bool operator!=(const Vecteur& autre) const {
        return !(*this == autre);
    }

    // Méthode pour afficher le vecteur
    void afficher() const {
        if (is3D) {
            std::cout << "<" << vx << ", " << vy << ", " << vz << "> (3D)";
        }
        else {
            std::cout << "<" << vx << ", " << vy << "> (2D)";
        }
    }

    // Calcul de la norme (longueur) du vecteur
    double norme() const {
        if (is3D) {
            return std::sqrt(vx * vx + vy * vy + vz * vz);
        }
        else {
            return std::sqrt(vx * vx + vy * vy);
        }
    }
};