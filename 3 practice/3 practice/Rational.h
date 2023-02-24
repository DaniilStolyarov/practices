#pragma once
#include <iostream>
using namespace std;
class Rational
{
public:
	// числитель и знаменатель дроби, натуральные числа
	// b != 0
	int a, b;

	// конструктор
	// включает проверку на b == 0
	// отбросить целую часть
	// сократить дробь
	Rational(int _a, int _b);
	Rational();
	// то же самое, что и конструктор
	// если не судьба, вернёт 0
	bool set(int _a, int _b);

	// вывод дроби через черту
	void show();

	bool isValid = false; // указывает, существует ли такая дробь

	Rational operator+ (Rational _rightRat);

	void operator++();

	friend Rational operator- (Rational leftRat, Rational rightRat);

	bool operator==(Rational rightRat);

	bool operator> (Rational rightRat);

	void operator= (Rational rightRat);
};

