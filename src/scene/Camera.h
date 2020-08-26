// RenderTarget
#pragma once
#include "SceneObject.h"
#include "Renderable.h"
#include "Movable.h"
#include "Directional.h"

namespace nail {
    class Camera : public SceneObject, Movable, Directional {
    private:
        vec3 _up_direction;
        mat4 _view;
    protected:
        std::vector<ref<Renderable>> findVisiableSceneObject();
        void updateViewMatrix();
        vec3 getUpDirection();
    public:
        Camera(wref<SceneManager> manager, vec3 dir): SceneObject(manager), Directional(dir) {
            vec3 _up_direction    = vec3(0.0f, 1.0f,  0.0f);
        }
        virtual ~Camera() {}
        virtual void render();
    };
}