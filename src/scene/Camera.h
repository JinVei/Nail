// RenderTarget
#pragma once
#include "SceneObject.h"
#include "IRenderable.h"
#include "Movable.h"
#include "Directional.h"
#include "renderer/RenderTarget.h"
#include "IRotatable.h"

namespace nail {
    class Camera : public SceneObject, public Movable, public Directional, public IRotatable {
    private:
        vec3 _up_direction;
        mat4 _view_matrix;
        wref<RenderTarget> _render_target;
        float _fovy = 45;
        float _near = 0.1;
        float _far = 100;

    protected:
        std::vector<ref<IRenderable>> findVisiableSceneObject();
        void updateViewMatrix();
        vec3 getUpDirection();
    public:
        Camera(wref<SceneManager> manager, vec3 dir, Position pos);
        Camera(wref<SceneManager> manager, vec3 dir, Position pos, float fovy, float near, float far);
        void rotate(float angle, Axis axis) override;
        mat4 getViewMatrix();

        void setRenderTarget(wref<RenderTarget>);
        void removeRenderTarget();
        wref<RenderTarget> getRenderTarget();

        void setFovy(float fovy, float near, float far);

        virtual void update();
    };
}