
#include "Shader.h"
#include "GameObject.h"
#include "Engine.h"
#include "Texture.h"
#include "Camera.h"
#include "Model.h"
#include "Vertex.h"
#include "Circle.h"

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <SOIL/SOIL.h>
#include <irrKlang/irrKlang.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "assimp_Imp.h"
#include <fstream>

using namespace glm;

using namespace irrklang;

Engine* myEngine;

ISoundEngine* SoundEngine;
GLfloat speed = 2.0f;
GLfloat fi = 0.0f;
void uniformCallback(GameObject* pThis);

// создаем тестовый игровой объект и помещаем его на сцену

float conusX, conusY, conusZ;
float conusX2, conusY2, conusZ2;

void uniformCallback(GameObject* pThis)
{
	mat4 rotation{ 1.0f };
	rotation = glm::translate(rotation, vec3{ conusX, conusY, conusZ });
	rotation = glm::rotate(rotation, glm::radians(fi), vec3{ 0.0f, 1.0f, 0.0f });
	GLint changeLoc = glGetUniformLocation(pThis->shaderProgram, "rotation");
	fi += speed*0.01f;
	glUniformMatrix4fv(changeLoc, 1, GL_FALSE, glm::value_ptr(rotation));
	Engine::camera->update(pThis);
}
void uniformCallback2(GameObject* pThis)
{
	mat4 rotation{ 1.0f };
	rotation = glm::translate(rotation, vec3{ conusX2, conusY2, conusZ2 });
	rotation = glm::rotate(rotation, glm::radians(fi), vec3{ 0.0f, 1.0f, 0.0f });
	GLint changeLoc = glGetUniformLocation(pThis->shaderProgram, "rotation");
	fi += speed * 0.01f;
	glUniformMatrix4fv(changeLoc, 1, GL_FALSE, glm::value_ptr(rotation));
	Engine::camera->update(pThis);
}
void linkInputRight()
{
	speed += 1.0f;
}
void linkInputLeft()
{
	speed -= 1.0f;
}
void linkKeys()
{
	myEngine->mapKeyCallback[GLFW_KEY_RIGHT] = &linkInputRight;
	myEngine->mapKeyCallback[GLFW_KEY_LEFT] = &linkInputLeft;
}
int main(int argc, char* argv[])
{

	for (int i = 0; i < argc; i++)
	{
		ofstream out("./res.txt");
		if (out.is_open())
		{
			out << argv[i] << endl;
		}
	}
	setlocale(LC_ALL, "Russia");
	

	myEngine = new Engine();
	Engine::camera = new Camera(vec3{ 0.0f, 1.6f, 2.0f }, vec3(25.0f, 0.0f, 0.0f)); // вращение по оси z не сработает
	// todo: rotation пока не работает
	SoundEngine = createIrrKlangDevice();

	linkKeys();
	if (argv[1][0] == 's')
	{
		Shader* vertexShader = new Shader(GL_VERTEX_SHADER, "./Shaders/vert.glsl");
		Shader* fragmentShader = new Shader(GL_FRAGMENT_SHADER, "./Shaders/frag.glsl");
		float x, y, z, radius, height;
		// !!!!!!!!!!!!!!!!!!!!!!!!!! 
		x = atof(argv[2]);
		y = atof(argv[3]);
		z = atof(argv[4]);
		radius = atof(argv[5]);
		height = atof(argv[6]);
		// !!!!!!!!!!!!!!!!!!!!!!!

		/*x = 0.0f, y = -0.9f, z = 0.0f, height = 2.0f, radius = 1.0f;*/
		conusX = x;
		conusY = y;
		conusZ = z;

		Circle* circle = new Circle(radius, 0, 0, 0, vec3{ x, y, z });
		Texture* tex = new Texture("./Textures/cat.jpg");
		GameObject* gameCircle = new GameObject((circle->getVertices()), (circle->getIndices()), vertexShader, fragmentShader, tex);
		myEngine->scene.push_back(gameCircle);
		gameCircle->setUniformCallback(&uniformCallback);


		Circle* cone = new Circle(radius, 0, height, 0, vec3{ x, y, z });
		GameObject* gameCone = new GameObject((cone->getVertices()), (cone->getIndices()), vertexShader, fragmentShader, tex);
		myEngine->scene.push_back(gameCone);
		gameCone->setUniformCallback(&uniformCallback);
	}
	else if (argv[1][0] == 'c')
	{
		float x, y, z, radius1, radius2, height1, height2;

		/*x = 0.0f, y = -0.f, z = 0.0f, height1 = 2.0f, radius1 = 1.0f, height2 = 1.2f;*/
		x = atof(argv[2]);
		y = atof(argv[3]);
		z = atof(argv[4]);
		radius1 = atof(argv[5]);
		height1 = atof(argv[6]);
		height2 = atof(argv[7]);
		conusX = x;
		conusY = y;
		conusZ = z;

		conusX2 = x;
		conusY2 = y + height2;
		conusZ2 = z;
		radius2 = radius1 * (height1 - height2) / height1;

		Shader* vertexShader = new Shader(GL_VERTEX_SHADER, "./Shaders/vert.glsl");
		Shader* fragmentShader = new Shader(GL_FRAGMENT_SHADER, "./Shaders/frag.glsl");

		Circle* circle1 = new Circle(radius1, 0, 0, 0, vec3{ 0, 0, 0 });
		Texture* tex1 = new Texture("./Textures/cat.jpg");
		GameObject* gameCircle1 = new GameObject((circle1->getVertices()), (circle1->getIndices()), vertexShader, fragmentShader, tex1);
		myEngine->scene.push_back(gameCircle1);
		gameCircle1->setUniformCallback(&uniformCallback);

		Circle* circle2 = new Circle(radius2, 0, 0, 0, vec3{ x, y , z });
		Texture* tex2 = new Texture("./Textures/cat.jpg");
		GameObject* gameCircle2 = new GameObject((circle2->getVertices()), (circle2->getIndices()), vertexShader, fragmentShader, tex2);
		myEngine->scene.push_back(gameCircle2);
		gameCircle2->setUniformCallback(&uniformCallback2);


		CutConicFace conicface = Circle::getCutConicVertices(circle1, circle2, height2);
		Texture* tex3 = new Texture("./Textures/cat.jpg");
		GameObject* gameConicFace = new GameObject(conicface.vertices, conicface.indices, vertexShader, fragmentShader, tex3);
		myEngine->scene.push_back(gameConicFace);
		gameConicFace->setUniformCallback(&uniformCallback);
	}
	


	ISound* sound = SoundEngine->play2D("./audio/rat.mp3", true);
	
	SoundEngine->setSoundVolume(0.0f);

	if (myEngine->mainLoop()) return 0;


	return 0;
}


