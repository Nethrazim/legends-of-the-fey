#pragma once
#include <glm/glm.hpp>
#include "dimension_proxy.h"

namespace GameObjects
{
	class Transform
	{
	public:
		Transform();

		glm::vec3 position;
		
		DimensionProxy x;
		DimensionProxy y;
		DimensionProxy z;

		void set(float x, float y, float z);
		void set(glm::vec3 newPosition);

		void setX(float x);
		void setY(float y);
		void setZ(float z);
		
		 
		float getX();
		float getY();
		float getZ();
	};
}