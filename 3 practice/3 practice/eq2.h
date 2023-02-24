#pragma once
#include <iostream>
using namespace std;
class eq2
{
private:
	// коэффициенты уравнения
	double a, b, c;
	// дискриминант уравнения
	double D;
public:

	// конструктор экземпляра квадратного уравнения
	eq2(double _a, double _b, double _c);

	// занести значения коэффициентов в соответствующий объект
	void set(double _a, double _b, double _c);

	// возвращает наибольший корень квадратного уравнения,
	// если такой есть, либо 0
	double find_X();

	// возвращает значение квадратного многочлена с заданными
	// коэффициентами при заданном X
	double find_Y(double _x);
};

