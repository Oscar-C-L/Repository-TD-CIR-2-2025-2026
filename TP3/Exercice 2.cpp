#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Classe de base
class Shape {
public:
    virtual void display() const = 0; // méthode virtuelle pure
    virtual ~Shape() {}
};

// Classe Point2D
class Point2D { 
protected:
    double x, y;
public:
    Point2D(double px = 0, double py = 0) : x(px), y(py) {}

    double getX() const { return x; }
    double getY() const { return y; }

    void display() const {
        cout << "(" << x << "," << y << ")";
    }
};

// Cercle : un point + un rayon
class Circle : public Shape {
    Point2D center;
    double radius;
public:
    Circle(const Point2D& c, double r) : center(c), radius(r) {}

    void display() const override {
        cout << "Cercle : centre = ";
        center.display();
        cout << ", rayon = " << radius << endl;
    }
};

// Rectangle : deux points
class Rectangle : public Shape {
    Point2D p1, p2;
public:
    Rectangle(const Point2D& a, const Point2D& b) : p1(a), p2(b) {}

    void display() const override {
        cout << "Rectangle : coin1 = ";
        p1.display();
        cout << ", coin2 = ";
        p2.display();
        cout << endl;
    }
};

// Triangle : trois points
class Triangle : public Shape {
    Point2D p1, p2, p3;
public:
    Triangle(const Point2D& a, const Point2D& b, const Point2D& c)
        : p1(a), p2(b), p3(c) {}

    void display() const override {
        cout << "Triangle : ";
        p1.display(); cout << " ";
        p2.display(); cout << " ";
        p3.display(); cout << endl;
    }
};

int main() {
    Circle c(Point2D(0, 0), 5);
    Rectangle r(Point2D(0, 0), Point2D(4, 3));
    Triangle t(Point2D(0, 0), Point2D(1, 2), Point2D(2, 0));

    c.display();
    r.display();
    t.display();

    return 0;
}