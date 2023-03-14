#pragma once
#include <assimp/Importer.hpp>      // C++ importer interface
#include <assimp/scene.h>           // Output data structure
#include <assimp/postprocess.h>     // Post processing flags

// ����� ��� ����� ������� Assimp`a
class Assimp_Implementation
{
public:
	// ���������� ��������� �� assimp-scene ��� nullptr
	static const aiScene* loadModel(const std::string& pFile);
};
