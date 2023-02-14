#pragma once
#include <iostream>
#include <cmath>
class Triangle
{
private:
	double a, b, c; // длины сторон

public:
	// указывает, может ли существовать данный треугольник
	bool exst_tr();
	
	//обновляет значения сторон треугольника
	void set(double a, double b, double c);

	// выводит параметры треугольника на экран
	void show();

	// возвращает периметр треугольника
	double permetr();

	// возвращает площадь треугольника
	double square();

};