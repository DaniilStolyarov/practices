#pragma once
#include <string>
#include <iostream>
using std::string;
using std::ostream;
using std::istream;
struct Coords
{
	double latitude; // широта
	double longtitude; // долгота
};
class Ocean
{
public:
	string name;
	double square;
	double depth;
	Coords coordinates;
	Ocean();
	Ocean(string _name, double _square, double _depth, Coords _coordinates);

	friend ostream& operator<<(ostream& stream, Ocean& o);
	friend istream& operator>>(istream& stream, Ocean& o);
};
ostream& operator<<(ostream& stream, Ocean& o);
istream& operator>>(istream& stream, Ocean& o);
