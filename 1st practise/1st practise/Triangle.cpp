#include "Triangle.h"
using namespace std;
bool Triangle::exst_tr()
{
	return ((a + b > c) && (b + c > a) && (a + c > b));
}

void Triangle::set(double _a, double _b, double _c)
{
	a = _a;
	b = _b;
	c = _c;
}

void Triangle::show() {
	cout << "1 �������: " << a << endl;
	cout << "2 �������: " << b << endl;
	cout << "3 �������: " << c << endl;
}

double Triangle::permetr() {
	return a + b + c;
}
