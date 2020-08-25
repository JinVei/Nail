// RenderTarget
#pragma once
//#include "scene/Camera.h"
#include "SceneObject.h"

namespace nail {
    class Camera : public SceneObject {
    public:
        Camera(wref<SceneManager> owner): SceneObject(owner) {}
        virtual ~Camera() {}
    };
}