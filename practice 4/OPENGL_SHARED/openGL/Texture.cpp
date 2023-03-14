#include "Texture.h"

Texture::Texture(std::string path)
{
	glGenTextures(1, &glTexture); // ������������� �������� openGL
	glBindTexture(GL_TEXTURE_2D, glTexture); // ���������, ��� ������ ����� ������������ ������ ��������

	// ��������� �������� �� ��� x
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);

	// ��������� �������� �� ��� y
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// ��������� ���������� �������
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// �������� ����������� 
	image = SOIL_load_image(path.c_str(), &width, &height, 0, SOIL_LOAD_AUTO);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	
	// �������� Mipmap`��
	glGenerateMipmap(GL_TEXTURE_2D);

	// ������������ ������ �����������
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);

}