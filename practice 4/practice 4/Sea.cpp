#include "Sea.h"

Sea::Sea() : Ocean()
{
}

Sea::Sea(string _name, double _square, double _depth, Coords _coordinates, Ocean* ocean) : Ocean(_name, _square, _depth, _coordinates)
{
	this->ocean = ocean;
}

ostream& operator<<(ostream& stream, Sea& o)
{
	stream << "name: " << o.name << "Sea" << "\tsquare: "
		<< o.square << "\tdepth: " << o.depth << "\tx: " << o.coordinates.latitude << "\ty: " <<
		o.coordinates.longtitude << "\tOcean: " <<((o.ocean == nullptr) ? "none" : o.ocean->name);
	return stream;
}

istream& operator>>(istream& stream, Sea& o)
{
	stream >> o.name >> o.square >> o.depth >> o.coordinates.latitude >> o.coordinates.longtitude;
	return stream;
}
