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
        float _pitch; // x
        float _yaw; // y
        float _roll; //z 
    protected:
        std::vector<ref<Renderable>> findVisiableSceneObject();
        void updateViewMatrix();
        vec3 getUpDirection();
        void rotate(float angle, vec3 axis);
    public:
        Camera(wref<SceneManager> manager, vec3 dir);
        virtual ~Camera() {}
        virtual void render();
        void rotateX(float angle);
        void rotateY(float angle);
        void rotateZ(float angle);
        void rotateDirection(float angle, Axis axis);

    };
}