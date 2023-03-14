#pragma once

#include "Shader.h"
#include "Texture.h"
#include "Model.h"

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <vector>

// ����� ������� �������� �� �����

class GameObject 
{
private:

	// ������������� ��������� �� ���������
	void standardTransform();
public:
	GLuint shaderProgram; // ��� �������, ������� ������� ������
	GLuint VAO, VBO, EBO; // ������ ������ �� GPU
	vector<GLfloat>* vertices; // ������� ������� (� �.�. ����� � ���������� ����������)
	vector<GLuint>* indices; // ������� ������ � ����
	Shader* fragmentShader, *vertexShader; // �������
	Texture* texture;
	// ����������� �� ���������
	GameObject();

	// ����������� �����������
	GameObject( vector<GLfloat>* vertices, vector<GLuint>* indices, Shader *vertexShader, Shader *fragmentShader, Texture* texture);

	GameObject(string pModel, string pTexture, Shader* vertexShader, Shader* fragmentShader);

	// ����� ������ �� ��� ����������, ������� ��� ���� �� ���� ������ (������� � �������)
	void initGameObject();

	// ��������� ��������� ������� � mainloop
	void update(); 

	// ��������� �� �������-�������, ������� ����� ������� � update
	// �������� �� �������� uniform �������� � ������
	void (*shaderUniformCallback)(GameObject* pThis); 

	void setUniformCallback(void (*callback)(GameObject* pThis));

	
};

