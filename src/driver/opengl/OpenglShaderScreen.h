#pragma once

#include "OpenglShader.h"

namespace nail {
    class OpenglShaderScreen : public OpenglShader {
    private:
        const int _vertex_pos_location = 0;
        const int _vertex_texture_coord_location = 2;
        const int _tex_screen_loc = 0;

        String _uniform_name_tex_screen = "screenTexture";
    public:
        void setScreenTexture(GLuint tex_id);
        void apply(GLuint tex_id);
    };
}