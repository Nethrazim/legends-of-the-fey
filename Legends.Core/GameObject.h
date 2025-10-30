#pragma once
#include <vector>
#include <string>
#include "Transform.h"
#include "Rotation.h"
#include "Scale.h"
#include "Sprite.h"

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

		void update();
	};
}

