#pragma once
class Triangle
{
private:
	double a, b, c;

public:
	// ���������, ����� �� ������������ ������ �����������
	bool exst_tr();
	// ��������� �������� ������ ������������
	void set(double _a, double _b, double _c);
	// ������� ��������� ������������ �� �����
	void show();
	// ���������� �������� ������������
	double perimetr();
	// ���������� ������� ������������
	double square();
};

