#include "Triangle.h"
#include "iostream"

bool Triangle::exst_tr()
{
	return ((a + b) > c) && (b + c > a) && (a + c > b);
}

void Triangle::set(double _a, double _b, double _c)
{
	this->a = _a;
	this->b = _b;
	this->c = _c;
}
void Triangle::show()
{
	std::cout << "1 сторона: " << a << std::endl;
	std::cout << "2 сторона: " << b << std::endl;
	std::cout << "3 сторона: " << c << std::endl;
}
double Triangle::perimetr()
{
	return a + b + c;
}

double Triangle::square()
{
	double p = perimetr() / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}