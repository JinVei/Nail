#pragma once
#include "common/ref.h"
#include "scene/Renderable.h"
#include "scene/Light.h"

#include <vector>

namespace nail {
    class RenderTarget {
    public:
        virtual ~RenderTarget() {}
        virtual void getViewPort();
        virtual void setViewPort();
        virtual void setPerspective(float fovy, float near, float far);

        virtual void render(std::vector<ref<Renderable>>, std::list<ref<Light>>, mat4 view_matrix);
    };
}
