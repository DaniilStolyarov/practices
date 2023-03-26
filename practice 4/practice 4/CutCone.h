#pragma once
#include "Cone.h"
#include "iostream"
#include <sstream>
#include <string>
class CutCone :
    public Cone
{
public:
    // height - высота усечённого конуса (расстояние между окружностями оснований)
    double height;

    // constructor
    CutCone(double _x, double _y, double _z, double _radius, double _height, double _heightCutted);
    CutCone();
    CutCone(Cone* cone, double _heightCutted);
    double area();
    double volume();

    friend std::ostream& operator<< (std::ostream& a, CutCone& cone);
   
    bool operator==(CutCone& ccone);
};

std::ostream& operator<< (std::ostream &a, CutCone& cone);