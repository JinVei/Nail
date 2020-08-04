#pragma once 

#include "glad/glad.h"
#include "scene/Texture.h"
#include "scene/ImageLoader.h"

#include <string>

namespace nail {
    class OpenglTexture2D : public Texture {
    private:
        GLuint _gl_handle = 0;
        bool _is_load = false;
    public:
        OpenglTexture2D();
        ~OpenglTexture2D();
        OpenglTexture2D& operator= (const OpenglTexture2D& right) = delete;
        OpenglTexture2D(const OpenglTexture2D& right) = delete;

        void setTexParameter(GLenum name, GLenum value);
        void setTexParameter(GLenum name, GLfloat* value);

        GLuint getGLHandle();

        void attachToLocaction(GLuint);
        void bind();

        bool isLoad() override;
        bool load(ref<ImageData> data) override;
    protected:
    };
}
