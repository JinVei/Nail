#pragma once 

#include "glad/glad.h"
#include "scene/Texture.h"
#include "scene/ImageLoader.h"
#include "common/def.h"

#include <string>

namespace nail {
    class OpenglTexture2D : public Texture {
    private:
        CLASS_NON_COPYABLE(OpenglTexture2D);
        GLuint _gl_handle = 0;
        bool _is_load = false;
    public:
        OpenglTexture2D();
        ~OpenglTexture2D();

        void setTexParameter(GLenum name, GLenum value);
        void setTexParameter(GLenum name, GLfloat* value);

        GLuint getGLID();

        void attachToLocaction(GLuint);
        //void bind();

        bool isLoad() override;
        bool load(ref<ImageData> data) override;
    protected:
    };
}
