#pragma once
#include <cmath>
const double PI = 3.14159265;
class Cone
{
private:
	double x, y, z;
	double radius;
	double height;

	
public:
	Cone();
	Cone(double _radius, double _height);
	Cone(double _x, double _y, double _z, double _radius, double _height);

	void setCoordinate(double _x, double _y, double _z);
	void setRadius(double r);
	void setHeight(double h);

	double getRadius();
	double getHeight();

	double area();
	double volume();
	void initCone(double _x, double _y, double _z, double _radius, double _height);
	
	double getX();
	double getY();
	double getZ();

	bool operator> (Cone& cone);
	bool operator< (Cone& cone);
	bool operator==(Cone& cone);
};

