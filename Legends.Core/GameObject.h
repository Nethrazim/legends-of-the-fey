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
	
	public:

		std::string layer = "default";
		
		GameObject();
		virtual ~GameObject();

		Transform transform;
		Rotation rotation;
		Scale scale;
		Sprite sprite;
		MeshRenderer* meshRenderer;

		virtual void update();

		glm::mat4 model = glm::mat4(1.0f);
		glm::mat4 uMVP = glm::mat4(1.0f);
		virtual void updateMVP();
	};
}