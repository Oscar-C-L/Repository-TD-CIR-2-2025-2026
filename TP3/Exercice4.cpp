
#include <iostream>
#include <vector>

        // Classe Point
        class Point {
        public:
            double x;
            double y;

            Point(double x = 0, double y = 0) : x(x), y(y) {}
        };

        // Classe Polygon
        class Polygon {
        private:
            std::vector<Point> points;

        public:
            Polygon(const std::vector<Point>& points) : points(points) {}

            // M�thode pour ajouter un point
            void addPoint(const Point& point) {
                points.push_back(point);
            }

            // M�thode pour calculer l'aire du polygone
            double area() const {
                double sum1 = 0;
                double sum2 = 0;
                int n = points.size();

                for (int i = 0; i < n; ++i) {
                    int j = (i + 1) % n;
                    sum1 += points[i].x * points[j].y;
                    sum2 += points[j].x * points[i].y;
                }

                return 0.5 * abs(sum1 - sum2);
            }
        };

        int main() {
            // Test avec un triangle
            Polygon triangle({ Point(0, 0), Point(1, 0), Point(0, 1) });
            std::cout << "Aire du triangle : " << triangle.area() << std::endl;

            // Test avec un carr�
            Polygon square({ Point(0, 0), Point(1, 0), Point(1, 1), Point(0, 1) });
            std::cout << "Aire du carr� : " << square.area() << std::endl;

            // Test avec un rectangle
            Polygon rectangle({ Point(0, 0), Point(2, 0), Point(2, 1), Point(0, 1) });
            std::cout << "Aire du rectangle : " << rectangle.area() << std::endl;

            return 0;
        }
};