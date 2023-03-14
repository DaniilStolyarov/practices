#pragma once
#include "GameObject.h"
#include "Camera.h"
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>


// ����� �������� ������
class Engine
{
private:
	// ������� ������� � ����� ����� ����� �������� ����������
	static void keyCallback(GLFWwindow* window, GLint key, GLint scancode,
		GLint action, GLint mode);

	void bindCameraKeys();



public:


	GLFWwindow* window; // ���� ����������
	GLint width = 1920, height = 1080; // ������� ���� � ��������
	
	vector<GameObject*> scene = {}; // �����, ������� ������� �� ���������� �� ������� �������
	
	// ������� ������ 
	static Camera* camera;
	static GLint keyBuffer[512]; // ����� �� ������ ������� ������� ���� �������� �� ������ ���������� �������
	void(*mapKeyCallback[512])() = {nullptr};
	static double lastCursorPosX, lastCursorPosY;
	// ��������� ���������� glfw
	void startGL(); 

	// ������ ���������� glew
	// ���� ������ ����������, ����� false
	bool startGlew();

	// ��������� viewPort`a ����
	void makeViewport();

	// ������ ���� � ��
	// ���� ������ ����������, ����� false
	bool startWindow();



	static void	cursorCallback(GLFWwindow* window, double xpos, double ypos);

	// ����������� ������ ������
	// ����� ��� ������
	int start();

	// ������� ���� ������. �������� ����� update() � ���� �������� �� �����
	// ����� 0, ���� ���� ���������� ��� ������
	bool mainLoop();

	// ����������� �� ���������. ������� ����� start() 
	Engine();

	// ������������ ������� ����� � ���������
	void bufferKeyCallback();


	
};