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
    _view_matrix = glm::lookAt(getPosition(), getPosition() + getDirection(), getUpDirection());
}

std::vector<ref<IRenderable>> Camera::findVisiableSceneObject() {
    // TODO:
    std::vector<IRenderable> renderable_objs;
    auto manager_weakptr = getManager();
    auto manager = manager_weakptr.lock();
    NAIL_ASSERT(manager != nullptr);
    return manager->getAllRenderableSceneObjects();
}

void Camera::rotate(float angle, Axis axis) {
    vec3 axis_vec;
    switch (axis)
    {
    case Axis::x :
        axis_vec = vec3(1.0f, 0.0f, 0.0f);
        break;
    case Axis::y :
        axis_vec = vec3(0.0f, 1.0f, 0.0f);
        break;
    case Axis::z :
        axis_vec = vec3(0.0f, 0.0f, 1.0f);
    default:
        NAIL_ASSERT(false && "Fall into default");
        break;
    }

    mat4 rotate_mat = mat4(1.0f);
    glm::vec4 camare_dir(getDirection(), 1);
    rotate_mat = glm::rotate(rotate_mat, glm::radians(angle), axis_vec);
    setDirection(rotate_mat * camare_dir);
    updateViewMatrix();
}

mat4 Camera::getViewMatrix() {
    return _view_matrix;
}

void Camera::setRenderTarget(wref<RenderTarget> render_target) {
    _render_target = render_target;
    auto render_target_ref = _render_target.lock();
    render_target_ref->setupPerspective(_fovy, _near, _far);
}

void Camera::removeRenderTarget() {
    _render_target.reset();
}

wref<RenderTarget> Camera::getRenderTarget() {
    return _render_target;
}

void Camera::render() {
    auto render_target = _render_target.lock();
    if (render_target == nullptr) {
        return;
    }
    auto manager = getManager().lock();
    NAIL_ASSERT(manager != nullptr);

    auto renderables =  findVisiableSceneObject();

    render_target->render(renderables, manager->getLights(), getViewMatrix(), getPosition());
}

void Camera::setFovy(float fovy, float near, float far) {
    _fovy = fovy;
    _near = near;
    _far = far;

    auto render_target = _render_target.lock();
    render_target->setupPerspective(_fovy, _near, _far);
}