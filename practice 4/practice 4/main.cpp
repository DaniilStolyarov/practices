#include <iostream>
#include "Cone.h"
#include <Windows.h>
#include <string>
#include <sstream>
using namespace std;

void showCone(Cone* cone)
{
	cout << "cone 1:" << endl;
	cout << "\tarea: " << cone->area();
	cout << "\tvolume: " << cone->volume();
	cout << endl;
}
void showDynamicCone(Cone* cone)
{



	float mashtab = 10.0f;
	float radius = (float)cone->getRadius() / mashtab;
	float height = (float)cone->getHeight() / mashtab;
	float x, y, z;
	x = (float)cone->getX() / mashtab;
	y = (float)cone->getY() / mashtab;
	z = (float)cone->getZ() / mashtab;

	std::ostringstream ssX, ssY, ssZ, ssR, ssH;
	ssX << x;
	ssY << y;
	ssZ << z;
	ssR << radius;
	ssH << height;
	string command = ".\\build\\openGL.exe " + ssX.str() + " " + ssY.str() + " " + ssZ.str()+
		" " + ssR.str() + " " + ssH.str();
	system(command.c_str());
	std::cout << "\x1b[H\x1b[J" << std::flush;

	cout << "previous cone: " << endl;
	cout << "\tarea: " << cone->area();
	cout << "\tvolume: " << cone->volume();
	cout << endl;
}

int main()
{
	
	Cone cone;
	setlocale(LC_ALL, "Russian");
	
	Cone cone1(3, 7);
	Cone cone2(1, 2, 3, 5, 10);
	
	showCone(&cone1);
	showCone(&cone2);

	cout << endl;
	Cone* cone_dynamic = new Cone();
	cout << "enter x, y, z, radius and height for cone_dynamic: ";
	cout << endl << "example: (0 -7.5 -10 10 20)" << endl;
	cout << "(tip: use WASD, CTRL, SHIFT to navigate and mouse to look. TO EXIT PRESS ESC)" << endl;
	cout << "you can also press right/left arrow to rotate the Cone" << endl;
	double x, y, z;
	double height, radius;
	cin >> x >> y >> z >> radius >> height;
	cone_dynamic->initCone(x, y, z, radius, height);
	showDynamicCone(cone_dynamic);
	

	cout << endl;
	Cone** arr = new Cone * [2] {nullptr};

	for (int i = 0; i < 2; i++)
	{
		cout << "enter x, y, z, radius and height for cone[" << i << "]: ";
		cout << endl << "example: (0 -7.5 -10 10 20)" << endl;
		cout << "(tip: use WASD to navigate and mouse to look. TO EXIT PRESS ESC)" << endl;
		cout << "you can also press right/left arrow to rotate the Cone" << endl;
		arr[i] = new Cone();
		double x, y, z;
		double height, radius;
		cin >> x >> y >> z >> radius >> height;
		arr[i]->initCone(x, y, z, radius, height);
		cout << "watch the results" << endl;
		showDynamicCone(arr[i]);
	}
	return 0;
}