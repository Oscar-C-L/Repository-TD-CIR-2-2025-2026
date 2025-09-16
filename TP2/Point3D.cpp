#include "Point3D.hpp"
#include <iostream>
#include <cmath>
#include <cstdlib>  // pour rand()
#include <ctime>    // pour srand()

using namespace std;

// Constructeur par défaut : initialise x, y, z avec des valeurs aléatoires (0 à 100)
Point3D::Point3D() {
    srand(time(0));
    x = rand() % 101;
    y = rand() % 101;
    z = rand() % 101;
}

// Constructeur avec paramètres
Point3D::Point3D(const float& newx, const float& newy, const float& newz) {
    x = newx;
    y = newy;
    z = newz;
}

// Setters
void Point3D::setXYZ(const float& newx, const float& newy, const float& newz) {
    x = newx;
    y = newy;
    z = newz;
}

void Point3D::setX(const float& newx) { x = newx; }
void Point3D::setY(const float& newy) { y = newy; }
void Point3D::setZ(const float& newz) { z = newz; }

// Getters
float Point3D::getX() { return x; }
float Point3D::getY() { return y; }
float Point3D::getZ() { return z; }

// Autres méthodes
void Point3D::print() {
    cout << "(" << x << ", " << y << ", " << z << ")" << endl;
}

float Point3D::distanceTo(const Point3D& otherPoint3D) {
    float dx = x - otherPoint3D.x;
    float dy = y - otherPoint3D.y;
    float dz = z - otherPoint3D.z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}


#include "Point3D.hpp"
#include <iostream>
using namespace std;

int main() {
    // Test constructeur aléatoire
    Point3D p1;
    cout << "Point p1 (aleatoire): ";
    p1.print();

    // Test constructeur avec paramètres
    Point3D p2(10.5, 20.3, 30.7);
    cout << "Point p2 (initialise): ";
    p2.print();

    // Test setters
    p1.setXYZ(5, 15, 25);
    cout << "p1 apres setXYZ(5,15,25): ";
    p1.print();

    p2.setX(50);
    p2.setY(60);
    p2.setZ(70);
    cout << "p2 apres modification: ";
    p2.print();

    // Test getters
    cout << "Coordonnees de p2: x=" << p2.getX()
        << " y=" << p2.getY()
        << " z=" << p2.getZ() << endl;

    // Test distance
    float dist = p1.distanceTo(p2);
    cout << "Distance entre p1 et p2 = " << dist << endl;

    return 0;
}