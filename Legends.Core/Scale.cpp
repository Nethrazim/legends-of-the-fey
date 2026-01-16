#include "Scale.h"

namespace GameObjects {

	Scale::Scale() : Scale(1.0f,1.0f,1.0f) {
 	}

	Scale::Scale(float x, float y, float z) : x(scale.x), y(scale.y), z(scale.z) {
		scale.x = x;
		scale.y = y;
		scale.z = z;
	}

	void Scale::set(float xScale, float yScale, float zScale) {
		this->scale.x = xScale;
		this->scale.y = yScale;
		this->scale.z = zScale;
	}

	void Scale::set(glm::vec3 newScale) {
		this->scale.x = newScale.x;
		this->scale.y = newScale.y;
		this->scale.z = newScale.z;
	}

	void Scale::setX(float xScale) {
		this->scale.x = xScale;
	}

	void Scale::setY(float yScale) {
		this->scale.y = yScale;
	}

	void Scale::setZ(float zScale) {
		this->scale.z = zScale;
	}

}