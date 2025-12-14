#pragma once
#include "glm/glm.hpp"


namespace GameObjects
{
	class Rotation
	{
	public:
		glm::vec3 rotation;

		void set(float x, float y, float z);
		void set(glm::vec3 rotation);
		void setX(float x);
		void setY(float y);
		void setZ(float z);
	};
}


