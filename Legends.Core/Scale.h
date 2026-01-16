#pragma once

#include "glm/glm.hpp"
#include "dimension_proxy.h"

namespace GameObjects
{
	class Scale
	{
	public:
		Scale();
		Scale(float x, float y, float z);
		glm::vec3 scale;
		DimensionProxy x;
		DimensionProxy y;
		DimensionProxy z;

		void setX(float xScale);
		void setY(float yScale);
		void setZ(float zScale);

		void set(float xScale, float yScale, float zScale);
		void set(glm::vec3 newScale);
	};
}