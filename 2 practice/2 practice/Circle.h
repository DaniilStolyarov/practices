#pragma once
class Circle
{
private:
	// ������ ����������
	float radius;
	// ���������� x ������ ����������
	float x_center;
	// ���������� y ������ ����������
	float y_center;
public:

	Circle(float r, float x, float y);
	void set_circle(float r, float x, float y);

};

