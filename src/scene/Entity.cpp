#include "common/assert.h"
#include "Entity.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace nail;

Entity::Entity(wref<SceneManager> manager): SceneObject(manager, SceneObjectType::ENTITY) {
    _model_matrix = mat4(1.0f);
}
void Entity::setMeshs(MeshList meshs) {
    _meshs = meshs;
}

MeshList Entity::getMeshs() {
    return _meshs;
}

void Entity::addSubEntity(EntityPtr sub_entity) {
    _sub_entity.push_back(sub_entity);
}

void Entity::setSubEntity(std::vector<EntityPtr> sub_entitys) {
    _sub_entity = sub_entitys;
}

std::vector<EntityPtr> Entity::getSubEntity() {
    return _sub_entity;
}

void Entity::setModelMatrix(mat4 model_matrix) {
    _model_matrix = model_matrix;
}

mat4 Entity::getModelMatrix() {
    return _model_matrix;
}

void Entity::rotate(float angle, Axis axis) {
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
    _model_matrix = glm::rotate(_model_matrix, glm::radians(angle), axis_vec);
}
