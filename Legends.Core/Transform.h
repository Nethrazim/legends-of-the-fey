#pragma once

namespace GameObjects
{
	class Transform
	{
	public:
		float x;
		float y;

		void setX(float x);
		void setY(float y);
			
		float getX();
		float getY();
	};
}