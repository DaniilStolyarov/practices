#include "Circle.h"

void Circle::calcVertices()
{
	mat4 rotateMat(1.0f);

	vec4 radiusVec{ 0.0f, 0.0f, 1.0f , 0.0f};
	
	vertices = {center};
	for (int i = 0; i < quality; i++)
	{
		rotateMat = rotate(rotateMat, glm::radians(360.0f / quality), vec3{ 0.0f, 1.0f, 0.0f });
		
		radiusVec = { 0.0f, 0.0f, 1.0f , 0.0f };
		radiusVec =  rotateMat * radiusVec;
		vertices.push_back(vec3{radiusVec.x , radiusVec.y, radiusVec.z} * radius);
	}
	for (int i = 0; i < quality - 1; i++)
	{
		indices.push_back(0);
		indices.push_back(i + 1);
		indices.push_back(i + 2);
	}
	indices.push_back(0);
	indices.push_back(quality);
	indices.push_back(1);

	
	
}

Circle::Circle()
{
	
}

Circle::Circle(float _radius, float x, float y, float z, vec3 pos)
{
	this->center = vec3{ x, y, z };
	this->radius = _radius;
	this->position = pos;
	calcVertices();
}

vector<float>* Circle::getVertices()
{
	vector<float>* GLvertices = new vector<float>;
	for (int i = 0; i < vertices.size(); i++)
	{
		GLvertices->push_back(vertices[i].x);
		GLvertices->push_back(vertices[i].y);
		GLvertices->push_back(vertices[i].z);

		GLvertices->push_back(1.0f);
		GLvertices->push_back(1.0f);
		GLvertices->push_back(1.0f);

		GLvertices->push_back(vertices[i].x / 2 - 0.5f);
		GLvertices->push_back(-vertices[i].z / 2 + 0.5f);
	}
	return GLvertices;
}

vector<unsigned int>* Circle::getIndices()
{
	return new vector<unsigned int>(indices);
}

CutConicFace Circle::getCutConicVertices(Circle* c1, Circle* c2, float height)
{
	vector<unsigned int>* indices = new vector<unsigned int>();
	vector<float>* vertices = new vector<float>();
	auto c1_Vertices = c1->getVertices();
	for (unsigned int i = 8; i < c1_Vertices->size(); i++)
	{
		vertices->push_back(c1_Vertices->at(i));
	}

	auto c2_Vertices = c2->getVertices();

	for (unsigned int i = 8; i < c2_Vertices->size(); i++)
	{
		if (i % 8 == 1)
		{
			c2_Vertices->at(i) += height;
		}
		vertices->push_back(c2_Vertices->at(i));
	}

	for (unsigned int i = 0; i < c1->quality - 1; i++)
	{
		indices->push_back(i);
		indices->push_back(i + c1->quality);
		indices->push_back(i + c1->quality + 1);

		indices->push_back(i + c1->quality + 1);
		indices->push_back(i + 1);
		indices->push_back(i);
	}
	unsigned int i = c1->quality - 1;

	indices->push_back(i);
	indices->push_back(i + c1->quality);
	indices->push_back(c1->quality);

	indices->push_back(c1->quality);
	indices->push_back(0);
	indices->push_back(i);
	return CutConicFace{ vertices, indices };
 }
