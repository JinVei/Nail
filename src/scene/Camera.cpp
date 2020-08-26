#include "Camera.h"
#include "common/assert.h"
#include "SceneManager.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace nail;

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

void Camera::render() {

}