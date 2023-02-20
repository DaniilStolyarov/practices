#include <iostream>
#include "Triangle.h"
#include "Circle.h"
#include "Figure.h"
void task1();
void task2();
void task3();

int main()
{
	setlocale(LC_ALL, "Russian");
	//task1();
	//task2();
	task3();
	return 0;
}

void task3()
{
	float x1, x2, x3, x4, y1, y2, y3, y4;
	for (int i = 0; i < 3; i++)
	{
		std::cout << "Введите координаты 4угольника в следующем порядке - x1, x2, x3, x4, y1, y2, y3, y4:" << std::endl;
		std::cin >> x1 >> x2 >> x3 >> x4 >> y1 >> y2 >> y3 >> y4;
		Figure fig(x1, x2, x3, x4, y1, y2, y3, y4);
		std::cout << "параметры: " << endl;
		fig.show();
		std::cout << "является ли прямоугольником: " << fig.is_prug() << endl;
		std::cout << "является ли квадратом: " << fig.is_square() << endl;
		std::cout << "является ли ромбом: " << fig.is_romb() << endl;
		std::cout << "можно ли вписать в окружность: " << fig.is_in_circle() << endl;
		std::cout << "можно ли описать около окружности: " << fig.is_out_circle() << endl;
	}
}

void task2()
{
	float r, x, y;
	for (int i = 0; i < 3; i++)
	{
		std::cout << "Введите радиус, координаты x и y окружности через пробел:" << std::endl;
		std::cin >> r >> x >> y;
		Circle c(r, x, y);
		std::cout << "площадь: " << c.square() << std::endl;
		std::cout << "можно ли описать треугольник: " << c.triangle_around(3, 4, 5) << std::endl;
		std::cout << "можно ли вписать треугольник: " << c.triangle_in(3, 4, 5) << std::endl;
		std::cout << "пересекается ли с окружностью: " << c.check_circle(10, 0, 0) << std::endl;
	}
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