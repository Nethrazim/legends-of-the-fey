#pragma once
#include <glm/glm.hpp>

namespace GameObjects
{
	class Transform
	{
	public:

		float x;
		float y;
		float z;

		void setX(float x);
		void setY(float y);
		void setZ(float z);

		float getX();
		float getY();
		float getZ();
	};
}