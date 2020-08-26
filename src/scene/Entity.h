#pragma once
#include "SceneObject.h"
#include "Mesh.h"
#include "common/ref.h"
#include "Renderable.h"

namespace nail {
    class Entity;
    using EntityPtr = ref<Entity>;

    class Entity : public SceneObject, Renderable {
    private:
        MeshList _meshs;
        std::vector<EntityPtr> _sub_entity;
    public:
        Entity(wref<SceneManager> manager): SceneObject(manager) {}
        void setMeshs(MeshList meshs) {
            _meshs = meshs;
        }

        MeshList getMeshs() override {
            return _meshs;
        }

        void addSubEntity(EntityPtr sub_entity) {
            _sub_entity.push_back(sub_entity);
        }

        void setSubEntity(std::vector<EntityPtr> sub_entitys) {
            _sub_entity = sub_entitys;
        }

        std::vector<EntityPtr> getSubEntity() {
            return _sub_entity;
        }

    };
}