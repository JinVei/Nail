#pragma once
#include "scene/Mesh.h"
#include "Shader.h"

#include "common/ref.h"
namespace nail {
    class Rasterizer {
    public:
        virtual void draw(ref<Mesh> mesh, ref<Shader> shader) = 0;
    };
}