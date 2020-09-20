#pragma once
#include "SceneObject.h"
#include "Mesh.h"
#include "common/ref.h"
#include "IRenderable.h"
#include "IRotatable.h"
#include "SceneNode.h"
#include "IScalable.h"
#include "IMovable.h"

namespace nail {
    class EntityNode;
    using EntityNodePtr = ref<EntityNode>;

    class Entity: public SceneObject, public IRenderable, public IRotatable, public IScalable, public IMovable {
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
        void scale(vec3 v) override;
        void move(vec3 v) override;
        void setPosition(vec3 v) override;
        Position getPosition() override;
    };
    using EntityPtr = ref<Entity>;

    class EntityNode : public SceneNode {
    private:
    public:
        EntityNode(wref<SceneManager> manager);

        void addSubEntity(EntityNodePtr sub_entity);
        std::vector<EntityNodePtr> getSubEntitys();
        void setEntity(EntityPtr);
        EntityPtr getEntity();

        void scale(vec3 v) override;
        void rotate(float angle, Axis axis) override;
        void setPosition(Position pos) override;
        void move(vec3 v) override;
    };
}