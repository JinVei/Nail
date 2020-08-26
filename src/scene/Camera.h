// RenderTarget
#pragma once
#include "SceneObject.h"
#include "Renderable.h"
#include "Movable.h"
#include "Directional.h"
#include "renderer/RenderTarget.h"

namespace nail {
    class Camera : public SceneObject, Movable, Directional {
    private:
        vec3 _up_direction;
        mat4 _view_matrix;
        wref<RenderTarget> _render_target;

    protected:
        std::vector<ref<Renderable>> findVisiableSceneObject();
        void updateViewMatrix();
        vec3 getUpDirection();
        void rotate(float angle, vec3 axis);
    public:
        Camera(wref<SceneManager> manager, vec3 dir);
        virtual ~Camera() {}
        void rotateX(float angle);
        void rotateY(float angle);
        void rotateZ(float angle);
        void rotateDirection(float angle, Axis axis);
        mat4 getViewMatrix();

        void setRenderTarget(wref<RenderTarget>);
        void removeRenderTarget();
        wref<RenderTarget> getRenderTarget();

        virtual void render();
    };
}