#pragma once
#include "renderer/Rasterizer.h"
namespace nail {
    class OGLRasterizer: public Rasterizer {
        void  draw(ref<Mesh> mesh, ref<Shader> shader) override;
    };
}