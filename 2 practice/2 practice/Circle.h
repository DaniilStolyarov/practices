#pragma once
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

	Circle(float r, float x, float y);
	void set_circle(float r, float x, float y);

};

