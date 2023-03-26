#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include <iostream>
using namespace std;
using namespace glm;

struct CutConicFace
{
	vector<float>* vertices;
	vector<unsigned int>* indices;
};

class Circle
{
private:
	unsigned int quality = 100; // vertices count
	vector<vec3> vertices;
	vector<unsigned int> indices;
	void calcVertices();
public:
	vec3 center{ 0, 0, 0 };
	float radius;
	vec3 position{ 0, 0, 0 };
	Circle();
	Circle(float _radius, float x = 0, float y = 0, float z = 0, vec3 pos = vec3{0, 0, 0});
	vector<float>* getVertices(); 
	vector<unsigned int>* getIndices();

	// делает коническую поверхность из двух кругов
	static CutConicFace getCutConicVertices(Circle* c1, Circle* c2, float height);
};

