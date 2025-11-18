#pragma once

#include <vector>
#include <string>

#include "Transform.h"
#include "Rotation.h"
#include "Scale.h"
#include "Sprite.h"
#include "MeshRenderer.h"
#include "glm/glm.hpp"

namespace GameObjects
{
	class GameObject
	{
	private:
		std::vector<GameObject*> children;
	
	public:
		std::string layer = "default";

		GameObject* parent = nullptr;
		GameObject();
		virtual ~GameObject();

		Transform transform;
		Rotation rotation;
		Scale scale;
		Sprite sprite;
		MeshRenderer* meshRenderer;		

		void addChild(GameObject* child);
		void removeChild(GameObject* child);
		
		std::vector<GameObject*>* getChildren() {
			return &children;
		}

		virtual void update();
		virtual void script();
		glm::mat4 model = glm::mat4(1.0f);
		glm::mat4 getWorldModelMatrix();

		glm::mat4 mvpMatrix;
		void calculateMVP(const glm::mat4& view, const glm::mat4& projection);
	};
}