#include "Rotation.h"

namespace GameObjects
{
	Rotation::Rotation() : Rotation(0.0f, 0.0f, 0.0f) {
	}

	Rotation::Rotation(int x, int y, int z) : x(rotation.x), y(rotation.y), z(rotation.z) {
		rotation.x = x;
		rotation.y = y;
		rotation.z = z;
	}

	void Rotation::set(float rotationX, float rotationY, float rotationZ)
	{
		this->rotation.x = rotationX;
		this->rotation.y = rotationY;
		this->rotation.z = rotationZ;
	}

	void Rotation::set(glm::vec3 rotation)
	{
		this->rotation = rotation;
	}

	void Rotation::setX(float rotationX)
	{
		this->rotation.x = rotationX;
	}

	void Rotation::setY(float rotationY)
	{
		this->rotation.y = rotationY;
	}

	void Rotation::setZ(float rotationZ)
	{
		this->rotation.z = rotationZ;
	}
}
