#include <iostream>
#include "eq2.h";
#include "Rational.h"
void task1();
void task2();
void task3();

using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	task3();
	return 0;
}

void task1()
{

	double a, b, c;

	cout << "Введите коэффициенты уравнения" << endl;

	cin >> a >> b >> c;

	eq2 example(a, b, c);
	example.find_X();

	double x;
	cin >> x;
	cout << "Введите x" << endl;

	cout << example.find_Y(x);
	
}
void task2()
{
	int p, q, n; 
	cout << "Введите количество элементов массива:" << endl;
	cin >> n;
	Rational* rat = new Rational[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Введите p и q дроби" << endl;
		cin >> p >> q;
		rat[i].set(p, q);
		if (!(rat[i].isValid))
		{
			cout << "Дробь не существует, попробуйте другую" << endl;
			i--;
		}
	}
	cout << "Результат: " << endl;

	for (int i = 0; i < n; i++)
	{
		rat[i].show();
	}
}
Rational operator-(Rational leftRat, Rational rightRat) 
{
	Rational resRat(leftRat.a * rightRat.b - leftRat.b * rightRat.a, leftRat.b * rightRat.b);
	return resRat;
}
void task3()
{

	int n, p, q;
	cout << "Введите число элементов массива" << endl;
	while (1)
	{
		cin >> n;
		if (n > 1) break;
		cout << "Хотя бы 2" << endl;
	}
	Rational** arr = new Rational*[n];// массив указателей на объекты

	for (int i = 0; i < n; i++)
	{
		cout << "Введите p и q дроби" << endl;
		cin >> p >> q;
		arr[i] = new Rational(p, q);
		if (!(arr[i]->isValid))
		{
			cout << "Дробь не существует, попробуйте другую" << endl;
			i--;
		}
	}

	for (int i = 0; i < n - 1; i++)
	{
		Rational* a = arr[i];
		Rational* b = arr[i + 1];
		cout << "################################" << endl;
		cout << "a: arr[" << i << "] = " << a->a << "/" << a->b << "\tb: arr[" << i + 1 << "] = " << b->a << "/" << b->b << endl;
		cout << "--------------------------------" << endl;
		Rational c = *a + *b; // вернёт только дробную часть от суммы
		cout << "a + b: \t"; c.show();
		
		// опять же только дробная часть 
		// если получится отрицательное число, результат будет возможно странным
		c = *a - *b;
		cout << "a - b:\t"; c.show();

		cout << "a == b:\t" << (*a == *b) << endl;

		cout << "a > b:\t" << (*a > *b) << endl;
		
		++(*b); // увеличивает числитель на 1
		// заметка: a++ - бинарный оператор, нужен для работы с памятью (не сработает)
		// ++a - для работы со значением, не возвращает значения
		cout << "++b:\t"; b->show();
	}
}