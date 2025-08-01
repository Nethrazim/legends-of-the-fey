#pragma once
#include <vector>

namespace GameObjects {
	class GameObject;
};

using namespace GameObjects;

class SceneLayer
{
public:
	SceneLayer();
	~SceneLayer();

	void add(GameObject* gameObject);
	
	static int rows;
	static int cols;

	//GameObject** mapMatrix;

	size_t size() const;
	
	std::vector<GameObject*> layer;
};

