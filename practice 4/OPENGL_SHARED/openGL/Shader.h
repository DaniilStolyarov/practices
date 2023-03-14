#pragma once
#include <string>
#include <fstream>
#include <iostream>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
using namespace std;
// ����� ��� ������� ���������� �������� �� ������. 
// ���������� ������� ��� ������� � ���� � ��� ��������� ����.
class Shader
{
public:
	string path; // ���� � �������
	string source; // �������� ��� �������
	GLuint glShader; // �������������� ������ OpenGL

	// �������� �������� ��� �� �����
	void getSourceFromFile(); 

	// ����������� �����������
	Shader(int ShaderType, string path);

	// ����������� �� ���������
	Shader(); 
};