#pragma once

#include "glad/glad.h"
#include "common/vec.h"
#include "common/ref.h"

#include <string>

namespace nail {
    class OpenglShader {
    private:
        GLuint _glid = 0;
        String _vertex_program_path;
        String _fragment_program_path;
    public:
        OpenglShader(String vertex_program_path, String fragment_program_path);
        virtual ~OpenglShader();
        int getID();
        void apply();
        void unapply();
        
        bool load();

        // Uniform
        void setUniform(const std::string &name, bool value) const;  
        void setUniform(const std::string &name, int value) const;   
        void setUniform(const std::string &name, float value) const;
        void setUniform(const std::string &name, mat4& value) const;
        void setUniform(const std::string &name, const vec3 &value) const;
        void setUniform(const std::string &name, const vec4 &value) const;
    };

}