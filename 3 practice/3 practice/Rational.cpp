#include "Rational.h"

// сокращает числитель и знаменатель

void sokr(int& a, int& b)
{
	bool _continue = false;
	do
	{
		_continue = false;
		for (int i = a; i > 1; i--)
		{
			if ((a % i == 0) && (b % i == 0))
			{
				a = a / i;
				b = b / i;
				_continue = true;
				break;
			}
		}
	} while (_continue);

}

Rational::Rational(int _a, int _b)
{
	if (!set(_a, _b))
	{
		cout << "b = 0" << endl;
		return;
	}
	
}

Rational::Rational()
{
	isValid = false;
}

bool Rational::set(int _a, int _b)
{
	if (_b == 0)
		return false;
	a = _a % _b;
	b = _b;

	sokr(a, b);
	isValid = true;
	return true;
}

void Rational::show()
{
	std::cout << a << "/" << b << endl;
}

Rational Rational::operator+(Rational _rightRat)
{
	Rational rat(this->a * (_rightRat.b) + this->b * (_rightRat.a), this->b * (_rightRat.b));
	return rat;
}

void Rational::operator++()
{
	this->set(this->a + 1, this->b);
}

bool Rational::operator==(Rational rightRat)
{
	if (this->a != rightRat.a || this->b != rightRat.b) return false;
	if (!this->isValid || !rightRat.isValid) return false;
	return true;
}

bool Rational::operator>(Rational rightRat)
{
	int _p = this->a * rightRat.b - this->b * rightRat.a;
	if (_p > 0) return true;
	else return false;
}

void Rational::operator=(Rational rightRat)
{
	set(rightRat.a, rightRat.b);
}
