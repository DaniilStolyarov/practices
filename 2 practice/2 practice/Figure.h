#pragma once
#include <cmath>
#include <iostream>
using namespace std;
// класс для работы с 4-угольниками
class Figure
{
private:
	// координаты x и y вершин
	float	x1, y1,
			x2, y2,
			x3, y3,
			x4, y4;
	float a, b, c, d; // длины сторон для облегчения расчётов
	// площадь четырёхугольника
	float S;

	// периметр четырёхугольника
	float P;
public:
	// конструктор экземпляров класса Figure
	Figure(float _x1, float _x2,
		float _x3, float _x4,
		float _y1, float _y2,
		float _y3, float _y4);

	// выводит параметры на экран
	void show();

	// является ли четырёхугольник прямоугольником
	bool is_prug();

	// является ли черырёхугольник квадратом
	bool is_square();

	// является ли четырёхугольник ромбом
	bool is_romb();

	// можно ли четырёхугольник вписать в окружность
	bool is_in_circle();

	// может ли четырёхугольник быть описан около окружности
	bool is_out_circle();
};

