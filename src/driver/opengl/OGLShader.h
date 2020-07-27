#pragma once
#include "renderer/Shader.h"
namespace nail {
    class OGLShader: public Shader {
        void use() override;
    };
}