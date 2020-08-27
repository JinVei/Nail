// RenderTarget
#pragma once
#include "SceneObject.h"
#include "IRenderable.h"
#include "Movable.h"
#include "Directional.h"
#include "renderer/RenderTarget.h"
#include "IRotatable.h"

namespace nail {
    class Camera : public SceneObject, Movable, Directional, IRotatable {
    private:
        vec3 _up_direction;
        mat4 _view_matrix;
        wref<RenderTarget> _render_target;
        float _fovy;
        float _near;
        float _far;

    protected:
        std::vector<ref<IRenderable>> findVisiableSceneObject();
        void updateViewMatrix();
        vec3 getUpDirection();
    public:
        Camera(wref<SceneManager> manager, vec3 dir);
        virtual ~Camera() {}
        void rotate(float angle, Axis axis) override;
        mat4 getViewMatrix();

        void setRenderTarget(wref<RenderTarget>);
        void removeRenderTarget();
        wref<RenderTarget> getRenderTarget();

        virtual void render();
    };
}