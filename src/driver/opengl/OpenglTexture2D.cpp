#include "OpenglTexture2D.h"
#include "stb_image/stb_image.h"
#include  "common/assert.h"

#include <fstream>
#include <sstream>
#include <iostream>

using namespace nail;

OpenglTexture2D::OpenglTexture2D() {
    glGenTextures(1, &_gl_handle);
}

OpenglTexture2D::~OpenglTexture2D() {
    if (_gl_handle != 0) {
        glDeleteTextures(1, &_gl_handle);
    }
}

void OpenglTexture2D::setTexParameter(GLenum name, GLenum value) {
    glTexParameteri(GL_TEXTURE_2D, name, value);
}

void OpenglTexture2D::setTexParameter(GLenum name, GLfloat* value) {
    glTexParameterfv(GL_TEXTURE_2D, name, value);
}

GLuint OpenglTexture2D::getGLID() {
    return _gl_handle;
}

void OpenglTexture2D::attachToLocaction(GLuint location) {
    glActiveTexture(GL_TEXTURE0 + location);
    glBindTexture(GL_TEXTURE_2D, _gl_handle);
}

bool OpenglTexture2D::load(ref<ImageData> image_data) {
    NAIL_ASSERT(image_data != nullptr);

    glBindTexture(GL_TEXTURE_2D, _gl_handle);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    int width = image_data->getWidth();
    int height = image_data->getHeight();
    int channels = image_data->getChannel();

    GLenum format;
    if (channels == 1) {
        format = GL_RED;
    } else if (channels == 3) {
        format = GL_RGB;
    } else if (channels == 4) {
        format = GL_RGBA;
    } else {
        std::cout << "Unknow format:" << format << std::endl;
        NAIL_ASSERT(false && "Unknow format");
        return false;
    }

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, format, GL_UNSIGNED_BYTE, image_data->getData());
    glGenerateMipmap(GL_TEXTURE_2D);
    
    setWidth(width);
    setHeight(height);
    setChannel(channels);
    setType(Texture::TextureType::TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, 0);

    _is_load = true;
    return true;
}

bool OpenglTexture2D::isLoad() {
    return _is_load;
}
