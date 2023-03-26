#pragma once
#include "Ocean.h"
#include <iostream>
using std::string;
using std::istream;
using std::ostream;
class Sea : public Ocean
{
public:
	Ocean* ocean = nullptr;
	Sea();
	Sea(string _name, double _square, double _depth, Coords _coordinates, Ocean* ocean = nullptr);

	friend ostream& operator<<(ostream& stream, Sea& o);
	friend istream& operator>>(istream& stream, Sea& o);
};

ostream& operator<<(ostream& stream, Sea& o);
istream& operator>>(istream& stream, Sea& o);