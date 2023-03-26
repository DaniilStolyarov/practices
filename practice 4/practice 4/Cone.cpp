#include "Cone.h"

void Cone::initCone(double _x, double _y, double _z, double _radius, double _height)
{
	x = _x; y = _y; z = _z;
	radius = _radius;
	height = _height;
}

double Cone::getX()
{
	return x;
}

double Cone::getY()
{
	return y;
}

double Cone::getZ()
{
	return z;
}

Cone::Cone()
{
	initCone(0, 0, 0, 0, 0);
}

Cone::Cone(double _radius, double _height)
{
	initCone(0, 0, 0, _radius, _height);
}

Cone::Cone(double _x, double _y, double _z, double _radius, double _height)
{
	initCone(_x, _y, _z, _radius, _height);
}

void Cone::setCoordinate(double _x, double _y, double _z)
{
	x = _x; y = _y; z = _z;
}

void Cone::setRadius(double r)
{
	radius = r;
}

void Cone::setHeight(double h)
{
	height = h;
}

double Cone::getRadius()
{
	return radius;
}

double Cone::getHeight()
{
	return height;
}

double Cone::area()
{
	return PI * radius * (radius + std::sqrt(height * height + radius * radius));
}

double Cone::volume()
{
	return PI * radius * radius * height / 3;
}

bool Cone::operator>(Cone& cone)
{
	return this->volume() > cone.volume();
}

bool Cone::operator<(Cone& cone)
{
	return this->volume() < cone.volume();
}

bool Cone::operator==(Cone& cone)
{
	return (this->height == cone.height) && (this->radius == cone.radius);
}
