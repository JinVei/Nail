#pragma once
#include "scene/Camera.h"
namespace nail {
    class RenderTarget {
    public:
        virtual ~RenderTarget() {}
        void getViewPort();
        void setViewPort();
        Camera getCamera();
        void setCamera(Camera);
        void render();
    };
}
