#pragma once

#include "glad/glad.h"
#include "common/vec.h"
#include "common/ref.h"
#include "common/def.h"

#include <string>

namespace nail {
    class OpenglShader {
    protected:
        CLASS_NON_COPYABLE(OpenglShader);
        GLuint _glid = 0;
    protected:
        bool compile(const char* vertex_program_source, const char* fragment_program_source);
    public:
        OpenglShader();
        virtual ~OpenglShader();
        int getGLID();
        virtual void apply() const;
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