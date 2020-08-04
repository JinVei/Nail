#pragma once 

#include "glad/glad.h"
#include "scene/Texture.h"

#include <string>


namespace nail {
    class OpenglTexture : public Texture {
    private:
        GLuint _gl_handle = 0;
        bool _is_load = false;
    public:
        OpenglTexture();
        ~OpenglTexture();
        OpenglTexture& operator= (const OpenglTexture& right) = delete;
        OpenglTexture(const OpenglTexture& right) = delete;

        void setTexParameter(GLenum name, GLenum value);
        void setTexParameter(GLenum name, GLfloat* value);

        GLuint getGLHandle();

        void attachToLocaction(GLuint);
        void bind();

        bool load(String path) override;
        bool isLoad() override;
    protected:
    };
}
