#include "common/assert.h"
#include "Entity.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace nail;

Entity::Entity(wref<SceneManager> manager): SceneObject(manager, SceneObjectType::ENTITY){
    _model_matrix = mat4(1.0f);
}

Entity::Entity(wref<SceneManager> manager, MeshList meshs): Entity(manager) {
    _meshs = meshs;
}

void Entity::setMeshs(MeshList meshs) {
    _meshs = meshs;
}

MeshList Entity::getMeshs() {
    return _meshs;
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


void Entity::setModelMatrix(mat4 model_matrix) {
    _model_matrix = model_matrix;
}

void Entity::scale(vec3 v) {
    _model_matrix = glm::scale(_model_matrix, v);
}

void Entity::move(vec3 v) {
    _model_matrix = glm::translate(_model_matrix, v);
}

void Entity::setPosition(vec3 v) {
    _model_matrix = mat4(1.0f);
    move(v);
}

Position Entity::getPosition() {
    return vec3(0,0,0);
}

EntityNode::EntityNode(wref<SceneManager> manager): SceneNode(manager) {
}

void EntityNode::addSubEntity(EntityNodePtr sub_entity) {
    addChild(sub_entity);
}

std::vector<EntityNodePtr> EntityNode::getSubEntitys() {
    std::vector<EntityNodePtr> sub_entitys;
    auto childs = getChilds();
    for (auto& child : childs) {
        auto entity_node =  ref_cast<EntityNode>(child.second);
        NAIL_ASSERT(entity_node != nullptr);
        sub_entitys.push_back(entity_node);
    }
    return sub_entitys;
}


void EntityNode::setEntity(EntityPtr entity) {
    setElement(entity);
}

EntityPtr EntityNode::getEntity() {
    return ref_cast<Entity>(getElement());
}

void EntityNode::rotate(float angle, Axis axis) {
    auto rotatable = ref_cast<IRotatable>(getElement());
    if (rotatable != nullptr) {
        rotatable->rotate(angle, axis);
    }

    for(auto sub_entity : getSubEntitys()) {
        sub_entity->rotate(angle, axis);
    }

}

void EntityNode::scale(vec3 v) {
    auto scalable = ref_cast<IScalable>(getElement());
    if (scalable != nullptr) {
        scalable->scale(v);
    }

    for(auto sub_entity : getSubEntitys()) {
        sub_entity->scale(v);
    }
}

void EntityNode::move(vec3 v) {
    SceneNode::move(v);

    auto movable = ref_cast<IMovable>(getElement());
    if (movable != nullptr) {
        movable->move(v);
    }
    for(auto sub_entity : getSubEntitys()) {
        sub_entity->move(v);
    }
}

void EntityNode::setPosition(Position pos) {
    Position before_pos = SceneNode::getPosition();
    SceneNode::setPosition(pos);
    Position current_pos = SceneNode::getPosition();
    vec3 move_vec = current_pos - before_pos;

    auto movable = ref_cast<IMovable>(getElement());
    if (movable != nullptr) {
        movable->setPosition(pos);
    }

    for(auto sub_entity : getSubEntitys()) {
        sub_entity->move(move_vec);
    }

}
