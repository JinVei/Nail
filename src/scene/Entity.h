#pragma once
#include "SceneObject.h"
#include "Mesh.h"
#include "common/ref.h"
#include "IRenderable.h"
#include "IRotatable.h"
#include "SceneNode.h"

namespace nail {
    class EntityNode;
    using EntityNodePtr = ref<EntityNode>;

    class Entity: public SceneObject, public IRenderable, public IRotatable {
    private:
        MeshList _meshs;
        mat4 _model_matrix;
    public:
        Entity(wref<SceneManager> manager);
        Entity(wref<SceneManager> manager, MeshList);
        MeshList getMeshs() override;
        void setModelMatrix(mat4 model_matrix) override;
        mat4 getModelMatrix() override;
        void setMeshs(MeshList meshs);
        void rotate(float angle, Axis axis) override;
    };
    using EntityPtr = ref<Entity>;

    class EntityNode : public SceneNode {
    private:
    public:
        EntityNode(wref<SceneManager> manager);

        void addSubEntity(EntityNodePtr sub_entity);
        std::vector<EntityNodePtr> getSubEntitys();

        void rotate(float angle, Axis axis) override;

        void setEntity(EntityPtr);
        EntityPtr getEntity();
    };
}