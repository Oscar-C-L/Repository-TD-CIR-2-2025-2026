#include "Point3D.hpp"
constexpr size_t numberOfPoints = 10;
class Trajectory {
private:
	Point3D points[numberOfPoints];
public:
	void print(); // print the coordinates of all points
	Point3D& getPoint(const int& n); // returns the reference of point n
	float getTotalDistance();
};