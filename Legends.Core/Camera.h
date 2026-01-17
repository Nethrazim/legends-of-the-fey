#pragma once
#include <glm/glm.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/matrix_clip_space.hpp>

using namespace glm;

class Camera
{
private:
    Camera();
    Camera(vec3 eye, vec3 center, vec3 up, float degrees, float aspect, float near, float far);
    static Camera* instance;

public:
    static vec4 backgroundColor;

    static Camera* getInstance();
    static Camera* getParameterizedInstance(vec3 eye, vec3 center, vec3 up, float degrees, float aspect, float near, float far);

    vec3 eye;
    vec3 center;
    vec3 up;

    glm::mat4 view;
    glm::mat4 projection;
};

