#include "CutCone.h"

CutCone::CutCone(double _x, double _y, double _z, double _radius, double _height, double _heightCutted) : Cone(_x, _y, _z, _radius, _height)
{
	this->height = _heightCutted;
}

CutCone::CutCone() : Cone()
{

}

CutCone::CutCone(Cone* cone, double _heightCutted) : Cone(*cone)
{
	this->height = _heightCutted;
}

double CutCone::area()
{
	double _rad2 = Cone::getRadius() * (Cone::getHeight() - height) / Cone::getHeight();

	return PI * (Cone::getRadius() + _rad2) * sqrt(pow(height, 2) + pow((Cone::getRadius() - _rad2), 2)) + PI * _rad2 * _rad2 + PI * pow(Cone::getRadius(), 2);
}

double CutCone::volume()
{
	double _rad2 = Cone::getRadius() * (Cone::getHeight() - height) / Cone::getHeight();
	Cone temp(0, 0, 0, _rad2, Cone::getHeight() - height);
	return Cone::volume() - temp.volume();	
}

bool CutCone::operator==(CutCone& ccone)
{
	return (this->height == ccone.height) && (this->getRadius() == ccone.getRadius()) && (this->getHeight() == this->getHeight());
}



std::ostream& operator<<(std::ostream &a, CutCone& cone)
{
	float mashtab = 10.0f;
	float radius = (float)cone.getRadius() / mashtab;
	float heightCC = (float)cone.height / mashtab;
	float height = (cone).getHeight() / mashtab;
	float x, y, z;
	x = (float)cone.getX() / mashtab;
	y = (float)cone.getY() / mashtab;
	z = (float)cone.getZ() / mashtab;


	std::ostringstream ssX, ssY, ssZ, ssR, ssH, ssHCC;
	ssX << x;
	ssY << y;
	ssZ << z;
	ssR << radius;
	ssH << height;
	ssHCC << heightCC;
	std::string command = ".\\build\\openGL.exe c " + ssX.str() + " " + ssY.str() + " " + ssZ.str() +
		" " + ssR.str() + " " + ssH.str() + " " + ssHCC.str();

	system(command.c_str());
	a << "\x1b[H\x1b[J" << std::flush;
	
	a << "previous cone: " << std::endl;
	a << "\tarea: " << cone.area();
	a << "\tvolume: " << cone.volume();
	a << std::endl;
	
}
