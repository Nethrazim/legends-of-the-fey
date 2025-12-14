#include "Scale.h"

namespace GameObjects {

	Scale::Scale() : x(scale.x), y(scale.y), z(scale.z) {
		// Constructor body (if needed)
	}

	void Scale::set(float xScale, float yScale, float zScale)
	{
		this->scale.x = xScale;
		this->scale.y = yScale;
		this->scale.z = zScale;
	}

	void Scale::set(glm::vec3 newScale)
	{
		this->scale.x = newScale.x;
		this->scale.y = newScale.y;
		this->scale.z = newScale.z;
	}

	void Scale::setX(float xScale)
	{
		this->scale.x = xScale;
	}

	void Scale::setY(float yScale)
	{
		this->scale.y = yScale;
	}

	void Scale::setZ(float zScale)
	{
		this->scale.z = zScale;
	}

} // namespace GameObjects