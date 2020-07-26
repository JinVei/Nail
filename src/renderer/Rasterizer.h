#pragma once
#include "Mesh.h"
#include "Shader.h"
namespace Nail {
    class Rasterizer {
    public:
        void draw(Mesh mesh, Shader shader);
    };
}