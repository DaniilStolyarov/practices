#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
class Circle
{
private:
	// радиус окружности
	float radius;
	// координата x центра окружности
	float x_center;
	// координата y центра окружности
	float y_center;
public:
	// конструктор объектов класса Circle
	Circle();
	Circle(float r, float x, float y);
	// задать значения radius, x_center, y_center
	void set_circle(float r, float x, float y);

	// возвращает площадь окружности
	float square();

	/*
		возвращает true, если вокруг треугольника со сторонами
		a, b, и c можно описать данную окружность,
		и false - в противном случае.
	*/
	bool triangle_around(float a, float b, float c);
	
	/*
		возвращает true, если в треугольник со сторонами
		a, b, и c можно вписать данную окружность, 
		и false - в противном случае.
	*/
	bool triangle_in(float a, float b, float c);
	/*
		возвращает true, если окружность радиуса r
		с координатами центра x_cntr и y_cntr пересекается
		с данной окружностью, и false - в противном случае.
	*/
	bool check_circle(float r, float x_cntr, float y_cntr);
};

