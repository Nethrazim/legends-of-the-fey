#pragma once
#include <glm/glm.hpp>

namespace GameObjects
{
	class Transform
	{
	public:

		float x = 0;
		float y = 0;
		float z = 0;

		void setX(float x);
		void setY(float y);
		void setZ(float z);

		float getX();
		float getY();
		float getZ();
	};
}