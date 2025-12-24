#pragma once
#include "glm/glm.hpp"
#include "dimension_proxy.h"

namespace GameObjects
{
	class Rotation
	{
	public:
		glm::vec3 rotation;

		Rotation();

		DimensionProxy x;
		DimensionProxy y;
		DimensionProxy z;

		void setX(float x);
		void setY(float y);
		void setZ(float z);

		void set(float x, float y, float z);
		void set(glm::vec3 rotation);
		
	};
}


