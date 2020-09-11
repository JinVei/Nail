#pragma once

#include "glad/glad.h"
#include "common/vec.h"
#include "common/ref.h"

#include <string>

namespace nail {
    class OpenglShader {
    protected:
        GLuint _glid = 0;
    protected:
        bool compile(const char* vertex_program_source, const char* fragment_program_source);
    public:
        OpenglShader();
        virtual ~OpenglShader();
        OpenglShader& operator= (const OpenglShader& right) = delete;
        OpenglShader(const OpenglShader& right) = delete;

        int getGLID();
        virtual void apply();
        virtual void unapply();
        
        bool compile(String vertex_program_path, String fragment_program_path);

        // Uniform
        void setUniform(const std::string &name, bool value) const;  
        void setUniform(const std::string &name, int value) const;   
        void setUniform(const std::string &name, float value) const;
        void setUniform(const std::string &name, mat4& value) const;
        void setUniform(const std::string &name, const vec3 &value) const;
        void setUniform(const std::string &name, const vec4 &value) const;
    };

}