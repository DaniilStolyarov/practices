#pragma once
#include <iostream>
#include <cmath>
class Triangle
{
private:
	double a, b, c; // ����� ������

public:
	// ���������, ����� �� ������������ ������ �����������
	bool exst_tr();
	
	//��������� �������� ������ ������������
	void set(double a, double b, double c);

	// ������� ��������� ������������ �� �����
	void show();

	// ���������� �������� ������������
	double permetr();

	// ���������� ������� ������������
	double square();

};