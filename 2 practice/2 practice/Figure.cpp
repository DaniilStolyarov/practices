#include "Figure.h"

struct vec2
{
	float x;
	float y;
};

Figure::Figure(float _x1, float _x2, float _x3, float _x4, float _y1, float _y2, float _y3, float _y4)
{
	x1 = _x1; x2 = _x2; x3 = _x3; x4 = _x4;
	y1 = _y1; y2 = _y2; y3 = _y3; y4 = _y4;
	S = 0.5f * ((x1 * y2 + x2 * y3 + x3 * y4 + x4 * y1) -
		(x1 * y4 + x2 * y1 + x3 * y2 + x4 * y3));
	a = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	b = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
	c = sqrt(pow(x4 - x3, 2) + pow(y4 - y3, 2));
	d = sqrt(pow(x1 - x4, 2) + pow(y1 - y4, 2));

	P = a + b + c + d;
}

void Figure::show()
{
	cout << "x1: " << x1 << " y1: " << y1 << endl;
	cout << "x2: " << x2 << " y2: " << y2 << endl;
	cout << "x3: " << x3 << " y3: " << y3 << endl;
	cout << "x4: " << x4 << " y4: " << y4 << endl;
	cout << "P: " << P << endl;
	cout << "S: " << S << endl;
}

bool Figure::is_prug()
{
	float d13 = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2)); // диагональ точек 1 и 3
	float d24 = sqrt(pow(x4 - x2, 2) + pow(y4 - y2, 2)); // диагональ точек 2 и 4

	// теперь будем проверять треугольники 4хугольника на соответствие критерию Пифагора
	if ((a * a + b * b) != d13 * d13) return false;
	if ((b * b + c * c) != d24 * d24) return false;
	if ((c * c + d * d) != d13 * d13) return false;
	// если три угла 90, четвёртый 360-270 = 90
	return true;
}

bool Figure::is_square()
{
	// прямоугольник, у которого две смежные стороны равны
	return is_prug() && (a == b);
}

bool Figure::is_romb()
{
	// 4 стороны равны
	return (a == b) && (a == c) && (a == d);
}

bool Figure::is_in_circle()
{
	// найдём векторы 21 и 23 и косинус угла между ними
	vec2 vec21 = { x1 - x2, y1 - y2 };
	vec2 vec23 = { x3 - x2, y3 - y2 };
	float cos123 = (vec21.x * vec23.x + vec21.y * vec23.y) / (a * b);
	// найдём векторы 43 и 41 и косинус угла между ними
	vec2 vec43 = { x3 - x4, y3 - y4 };
	vec2 vec41 = { x1 - x4, y1 - y4 };
	float cos345 = (vec43.x * vec41.x + vec43.y * vec41.y) / (c * d);
	// т.к. сумма углов 180, то косинусы должны быть противоположны
	return cos123 = -cos345;
}

bool Figure::is_out_circle()
{
	return (a + c) == (b + d);
}
