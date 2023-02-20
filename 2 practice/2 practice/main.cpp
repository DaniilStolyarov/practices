﻿#include <iostream>
#include "Triangle.h"

void task1();
void task2();
void task3();

int main()
{
	setlocale(LC_ALL, "Russian");
	task1();
	return 0;
}

void task1()
{
	Triangle mas[3]{Triangle()};
	double a, b, c;
	for (int i = 0; i < 3; i++)
	{
		std::cout << "Введите a, b и c для треугольника № " << i + 1 <<
			" через пробел" << std::endl;
		std::cin >> a >> b >> c;

		mas[i].set(a, b, c);

		if (!mas[i].exst_tr())
		{
			mas[i].show();
			std::cout << "Треугольника с такими сторонами не существует, попробуйте ещё раз"
				<< std::endl;
			i--;
		}
	}

	for (int i = 0; i < 3; i++) 
	{
		mas[i].show();
		std::cout << "Периметр треугольника: " << mas[i].perimetr() << std::endl;
		std::cout << "Площадь треугольника: " << mas[i].square() << std::endl;
	}
}