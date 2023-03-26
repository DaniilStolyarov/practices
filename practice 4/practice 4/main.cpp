#include <iostream>
#include "Cone.h"
#include "CutCone.h"
#include "Ocean.h"
#include "Sea.h"
#include "Gulf.h"
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
	string command = ".\\build\\openGL.exe s " + ssX.str() + " " + ssY.str() + " " + ssZ.str()+
		" " + ssR.str() + " " + ssH.str();
	system(command.c_str());
	std::cout << "\x1b[H\x1b[J" << std::flush;

	cout << "previous cone: " << endl;
	cout << "\tarea: " << cone->area();
	cout << "\tvolume: " << cone->volume();
	cout << endl;
}
void task1()
{
	Cone cone;

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
}


void task2()
{
	cout << "(tip: use WASD to navigate and mouse to look. TO EXIT PRESS ESC)" << endl;
	cout << "you can also press right/left arrow to rotate the Cone, shift/space to control alt" << endl;
	cout << "press ENTER to continue" << endl;
	cin.ignore();
	cout << "loading..." << endl;
	CutCone CC(0, 0, 0, 10, 10, 9);
	CutCone CC2(0, 0, 0, 10, 40, 10);
	cout << CC;
	system("pause");
	cout << CC2;
	system("pause");
	Cone base(0, 0, 0, 10, 10);
	CutCone derived1(&base, 2);
	CutCone derived2(&base, 5);
	cout << derived1; 
	system("pause");
	cout << derived2;
}

void task3()
{
	Ocean pacific = Ocean("Pacific", 178684000000, 4000, { -8.783195, -124.508522 });
	cout << pacific << endl;

	Sea Ohotsk = Sea("Ohotskoye", 1603000000, 821, { 53.715418, 148.960572 }, &pacific);

	Gulf* pGulf = new Gulf();
	cout << "Enter name, square, depth and coords x and y of some gulf in the Pacific Ocean" << endl;
	cin >> (*pGulf);
	pGulf->ocean = &pacific;
	cout << (*pGulf) << endl;
	delete pGulf;

	pGulf = new Gulf();
	cout << "Enter name, square, depth and coords x and y of some gulf in the Ohotskoye Sea" << endl;
	cin >> (*pGulf);
	pGulf->sea = &Ohotsk;
	cout << (*pGulf) << endl;
	delete pGulf;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	task1();
	return 0;
}