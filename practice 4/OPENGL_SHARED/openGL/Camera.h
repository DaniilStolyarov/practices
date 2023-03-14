#pragma once
#include "GameObject.h"
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
// ����� ������
using namespace glm;
class Camera 
{
public:
	// ���������� ��������� ��������������� ����������
	vec3 position;
	vec3 rotation;

	// ����� ������
	vec3 cameraTarget;
	// ������ ����������� ������
	vec3 cameraDirection;
	// ������ ��� y ������
	vec3 cameraUp;
	// ������ ��� x ������
	vec3 cameraRight;
	// ������ ������� ������ ������� ������
	vec3 up;
	// ������ ��� ������� lookAt()
	vec3 cameraView;
	
	GLfloat yaw, pitch;

	vec3 cameraFront;

	// ����������� �����������
	Camera(vec3 _position, vec3 _rotation);


	// ��������� ������ ������
	// ����� update() ���������� � mainloop
	void update(GameObject* object);
};