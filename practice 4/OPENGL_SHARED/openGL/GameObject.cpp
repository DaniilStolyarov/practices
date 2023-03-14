#include "GameObject.h"




GameObject::GameObject() {
	shaderProgram = 0;
	VAO = 0, VBO = 0, EBO = 0;
	vertices = nullptr;
	indices = nullptr;
	fragmentShader = nullptr;
	vertexShader = nullptr;
	shaderUniformCallback = nullptr;
	texture = 0;
}
GameObject::GameObject(vector<GLfloat>* vertices, vector<GLuint>* indices, Shader *vertexShader, Shader *fragmentShader, Texture* texture) {
	this->vertices = vertices;
	this->indices = indices;
	this->vertexShader = vertexShader;
	this->fragmentShader = fragmentShader;
	this->texture = texture;
	initGameObject();
}

GameObject::GameObject(string pModel, string pTexture, Shader* vertexShader, Shader* fragmentShader)
{
	Model* model = new Model(pModel, pTexture);
	this->vertices = model->vertices;
	this->indices = model->indices;
	this->vertexShader = vertexShader;
	this->fragmentShader = fragmentShader;
	this->texture = model->texture;


	initGameObject();
}

void GameObject::initGameObject()
{
	// �������� ��������� ���������
	this->shaderProgram = glCreateProgram();
	glAttachShader(this->shaderProgram, this->vertexShader->glShader);
	glAttachShader(this->shaderProgram, this->fragmentShader->glShader);
	glLinkProgram(this->shaderProgram);
	glUseProgram(this->shaderProgram);
	glDeleteShader(this->fragmentShader->glShader);
	glDeleteShader(this->vertexShader->glShader);

	// �������� ������ ��� VAO, VBO, EBO
	glGenVertexArrays(1, &this->VAO);
	glGenBuffers(1, &this->VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(this->VAO);
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
	glBufferData(GL_ARRAY_BUFFER, this->vertices->size() * sizeof(GLfloat), this->vertices->data(), GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->indices->size() * sizeof(GLuint), this->indices->data(), GL_STATIC_DRAW);

	/*
		1 - ������ ������������������. ��������, ������� - 0, ����� - 1, �������� - 2
		2 - ������� ��������� ������������������ ������ �����
		3, 4 - ...
		5 - stride (������ � ������ ����� ����������������������� ��������� ���������)
		6 - ������ �� ������ ������������������
	*/
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void GameObject::update()
{
	glUseProgram(this->shaderProgram);

	// ���� ���� �������� glUniform

	this->standardTransform();

	if (shaderUniformCallback != nullptr)
	shaderUniformCallback(this);

	if (this->texture != nullptr)
	{
		glBindTexture(GL_TEXTURE_2D, this->texture->glTexture);
	}

	glBindVertexArray(this->VAO);

	if (this->indices == nullptr) {
		glDrawArrays(GL_TRIANGLES, 0, vertices->size() / 3);
	} 
	else {
		glDrawElements(GL_TRIANGLES, indices->size() * sizeof(GLuint)/*36*/, GL_UNSIGNED_INT, 0);	
	}

	glBindVertexArray(0);
}

void GameObject::setUniformCallback(void (*callback)(GameObject* pThis))
{
	this->shaderUniformCallback = callback;
}

void GameObject::standardTransform()
{
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::rotate(model, glm::radians(-0.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	GLint modelLoc = glGetUniformLocation(this->shaderProgram, "model");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));


	glm::mat4 projection = glm::mat4(1.0f);
	projection = glm::perspective(glm::radians(50.0f), (GLfloat)1920/1080,
		0.1f, 100.0f);
	GLint projectionLoc = glGetUniformLocation(this->shaderProgram,
		"projection");
	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));
}