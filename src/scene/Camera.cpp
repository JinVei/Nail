#include "Camera.h"
#include "common/assert.h"
#include "SceneManager.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace nail;

Camera::Camera(wref<SceneManager> manager, vec3 dir): SceneObject(manager), Directional(dir) {
    vec3 _up_direction    = vec3(0.0f, 1.0f,  0.0f);
}

vec3 Camera::getUpDirection() {
    return _up_direction;
}

void Camera::updateViewMatrix() {
    _view = glm::lookAt(getPosition(), getPosition() + getDirection(), getUpDirection());
}

std::vector<ref<Renderable>> Camera::findVisiableSceneObject() {
    // TODO:
    std::vector<Renderable> renderable_objs;
    auto manager_weakptr = getManager();
    auto manager = manager_weakptr.lock();
    NAIL_ASSERT(manager != nullptr);
    return manager->getAllRenderableSceneObjects();
}

void Camera::rotateDirection(float angle, Axis axis) {
    switch (axis)
    {
    case Axis::x :
        vec3 axis_val = vec3(1.0f, 0.0f, 0.0f);
        rotate(angle, axis_val);
        break;
    case Axis::y :
        vec3 axis_val = vec3(0.0f, 1.0f, 0.0f);
        rotate(angle, axis_val);
        break;
    case Axis::z :
        vec3 axis_val = vec3(0.0f, 0.0f, 1.0f);
        rotate(angle, axis_val);
    default:
        NAIL_ASSERT(false && "Fall into default");
        break;
    }
}

void Camera::rotate(float angle, vec3 axis) {
    mat4 rotate_mat = mat4(1.0f);
    glm::vec4 camare_dir(getDirection(), 1);
    rotate_mat = glm::rotate(rotate_mat, glm::radians(angle), axis);
    setDirection(rotate_mat * camare_dir);
}

void Camera::render() {

}
