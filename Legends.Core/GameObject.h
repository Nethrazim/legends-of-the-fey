#pragma once
#include "Transform.h"
#include "Rotation.h"
#include "Scale.h"

namespace GameObjects
{
	class GameObject
	{
	public:
		Transform* transform;
		Rotation* rotation;
		Scale* scale;
		~GameObject();
	};
}

