#include "camera.h"

Camera* Camera::instance = nullptr;

Camera::Camera() : view(1.0f), projection(1.0f) {

    eye = vec3(0.0f, 0.0f, 50.0f);
    center = vec3(0.0f, 0.0f, 0.0f);
    up = vec3(0.0f, 1.0f, 0.0f);

    view = glm::lookAt(
        eye,
        center,
        up
    );


   projection = glm::perspective(
        glm::radians(60.0f),
        800.0f / 600.0f,
        0.1f,
        100.0f
    );
}

Camera* Camera::getInstance()
{
    if(instance)
    {
        return instance;
	}
    else
    {
        instance = new Camera();
        return instance;
    }
}


Camera* Camera::getParameterizedInstance(vec3 eye, vec3 center, vec3 up, float degrees, float aspect, float near, float far)
{
    if(instance)
    {
        return instance;
    }
    else
    {
        instance = new Camera(eye, center, up, degrees, aspect, near, far);
        return instance;
    }
}


Camera::Camera(vec3 eye, vec3 center, vec3 up, float degrees, float aspect, float near, float far) {
    
    this->eye = eye;
    this->center = center;
    this->up = up;

    view = glm::lookAt(
        eye,
        center,
        up
    );

    projection = glm::perspective(
       glm::radians(degrees),
       800.0f / 600.0f,
       0.1f,
       100.0f
   );

}