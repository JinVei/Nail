#pragma once
#include "SceneObject.h"
#include "Mesh.h"
#include "common/ref.h"
#include "IRenderable.h"
#include "IRotatable.h"

namespace nail {
    class Entity;
    using EntityPtr = ref<Entity>;

    class Entity : public SceneObject, public IRenderable, public IRotatable {
    private:
        MeshList _meshs;
        std::vector<EntityPtr> _sub_entity;
        mat4 _model_matrix;
    public:
        Entity(wref<SceneManager> manager);

        void setMeshs(MeshList meshs);
        MeshList getMeshs() override;

        void addSubEntity(EntityPtr sub_entity);
        void setSubEntity(std::vector<EntityPtr> sub_entitys);
        std::vector<EntityPtr> getSubEntity();

        void setModelMatrix(mat4 model_matrix) override;
        mat4 getModelMatrix() override;

        void rotate(float angle, Axis axis) override;

    };
}