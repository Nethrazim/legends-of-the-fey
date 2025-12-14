#pragma once
#include <glm/glm.hpp>

namespace GameObjects
{
	class Transform
	{
	public:
		glm::vec3 position;
		
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