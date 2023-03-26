#include "Gulf.h"

Gulf::Gulf() : Ocean()
{

}

Gulf::Gulf(string _name, double _square, double _depth, Coords _coordinates, Ocean* ocean) :
	Ocean(_name, _square, _depth, _coordinates)
{
	this->ocean = ocean;
	this->sea = nullptr;
}

Gulf::Gulf(string _name, double _square, double _depth, Coords _coordinates, Sea* sea) :
	Ocean(_name, _square, _depth, _coordinates)
{
	this->ocean = nullptr;
	this->sea = sea;
}

ostream& operator<<(ostream& stream, Gulf& o)
{
	stream << "name: " << o.name << " Gulf" << "\tsquare: "
		<< o.square << "\tdepth: " << o.depth << "\tx: " << o.coordinates.latitude << "\ty: " <<
		o.coordinates.longtitude;
	if (o.ocean != nullptr)
	{
		stream << "\tocean: " << o.ocean->name;
	}
	else if (o.sea != nullptr)
	{
		stream << "\tsea: " << o.sea->name;
	}
	return stream;
}

istream& operator>>(istream& stream, Gulf& o)
{
	stream >> o.name >> o.square >> o.depth >> o.coordinates.latitude >> o.coordinates.longtitude;
	return stream;
}
