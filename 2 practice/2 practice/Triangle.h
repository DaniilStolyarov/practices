#pragma once
class Triangle
{
private:
	double a, b, c;

public:
	// указывает, может ли существовать данный треугольник
	bool exst_tr();
	// обновляет значения сторон треугольника
	void set(double _a, double _b, double _c);
	// выводит параметры треугольника на экран
	void show();
	// возвращает периметр треугольника
	double perimetr();
	// возвращает площадь треугольника
	double square();
};

