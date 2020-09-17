#pragma once
#include "common/ref.h"
#include "scene/IRenderable.h"
#include "scene/Light.h"

#include <vector>

namespace nail {
    class RenderTarget {
    protected:
        using ViewPort = Rectangle;
    public:
        virtual ~RenderTarget() {}
        virtual ViewPort getViewPort() = 0;
        virtual void setViewPort(ViewPort) = 0;
        virtual void setupPerspective(float fovy, float near, float far) = 0;
        virtual void setClearColor(Color) = 0;
        virtual void render(std::vector<ref<IRenderable>>, std::list<ref<Light>>, mat4 view_matrix, vec3 view_pos) = 0;
        virtual void enableDepthTest(bool) = 0;
    };
}
