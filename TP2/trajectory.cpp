#include "Trajectory.hpp"
#include <iostream>
#include <stdexcept>
using namespace std;

Trajectory::Trajectory(size_t n) {
    numberOfPoints = n;
    points = new Point3D[n]; // allocation dynamique
}

Trajectory::~Trajectory() {
    delete[] points;  // libération mémoire
}

void Trajectory::print() {
    for (size_t i = 0; i < numberOfPoints; i++) {
        cout << "Point " << i << " : ";
        points[i].print();
    }
}

Point3D& Trajectory::getPoint(const int& n) {
    if (n >= 0 && n < (int)numberOfPoints)
        return points[n];
    else
        throw out_of_range("Index hors limites");
}

float Trajectory::getTotalDistance() {
    float distance = 0.0;
    for (size_t i = 0; i < numberOfPoints - 1; i++) {
        distance += points[i].distance(points[i + 1]);
    }
    return distance;
}




#include <iostream>
#include "Trajectory.hpp"
#include "Point3D.hpp"
using namespace std;

int main() {
    size_t n;
    cout << "Entrer le nombre de points : ";
    cin >> n;

    Trajectory traj(n);

    // Exemple de remplissage manuel
    for (size_t i = 0; i < n; i++) {
        traj.getPoint(i) = Point3D(i, i * 2, i * 3);
    }

    cout << "Affichage des points :" << endl;
    traj.print();

    cout << "Distance totale : " << traj.getTotalDistance() << endl;

    return 0;
}
