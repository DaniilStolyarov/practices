#include "Ocean.h"

Ocean::Ocean()
{
	this->name = "no name";
	this->square = 0;
	this->depth = 0;
	this->coordinates = {0, 0};
}

Ocean::Ocean(string _name, double _square, double _depth, Coords _coordinates)
{
	name = _name; square = _square; depth = _depth; coordinates = _coordinates;
}

ostream& operator<<( ostream& stream, Ocean& o)
{
	stream << "name: " << o.name << " Ocean" <<"\tsquare: "
		<< o.square << "\tdepth: " << o.depth << "\tx: " << o.coordinates.latitude << "\ty: " <<
		o.coordinates.longtitude;
	return stream;
}

istream& operator>>(istream& stream, Ocean& o)
{
	stream >> o.name >> o.square >> o.depth >> o.coordinates.latitude >> o.coordinates.longtitude;
	return stream;
}
