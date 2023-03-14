#pragma once
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <SOIL/SOIL.h>
#include <string>
// �����-������ ��� �������

struct TextureStruct
{
	GLuint glTexture;
	std::string textureType;
};

class Texture
{
public:
	GLuint glTexture; // ������ � �������� openGL
	std::string path; // ���� � �����-���������
	GLint width, height; // ������� �������� ��������
	unsigned char* image; // ������ ���� �� ��������, ��������� ��� �������� ��������
	TextureStruct textureStruct; // ��������� ��� �������� openGL

	Texture(std::string path);
	
};