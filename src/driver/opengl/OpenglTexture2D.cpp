#include "OpenglTexture2D.h"
#include "stb_image/stb_image.h"
#include  "common/assert.h"

#include <fstream>
#include <sstream>
#include <iostream>

using namespace nail;

OpenglTexture::OpenglTexture() {
    glGenTextures(1, &_gl_handle);
}

OpenglTexture::~OpenglTexture() {
    if (_gl_handle != 0) {
        glDeleteTextures(1, &_gl_handle);
    }
}

void OpenglTexture::setTexParameter(GLenum name, GLenum value) {
    glTexParameteri(GL_TEXTURE_2D, name, value);
}

void OpenglTexture::setTexParameter(GLenum name, GLfloat* value) {
    glTexParameterfv(GL_TEXTURE_2D, name, value);
}

GLuint OpenglTexture::getGLHandle() {
    return _gl_handle;
}

void OpenglTexture::attachToLocaction(GLuint location) {
    glActiveTexture(GL_TEXTURE0 + location);
}

void OpenglTexture::bind() {
    glBindTexture(GL_TEXTURE_2D, _gl_handle);
}

bool OpenglTexture::load(String path) {
    glBindTexture(GL_TEXTURE_2D, _gl_handle);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    int width, height, channels;
    stbi_set_flip_vertically_on_load(true);
    unsigned char *image_data = stbi_load(path.c_str(), &width, &height, &channels, 0);

    if (!image_data) {
        NAIL_ASSERT(false && "Failed to load texture");
        return false;
    }

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

    glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, image_data);
    glGenerateMipmap(GL_TEXTURE_2D);
    
    setWith(width);
    setHeight(height);
    setChannel(channels);

    stbi_image_free(image_data);
    glBindTexture(GL_TEXTURE_2D, 0);

    _is_load = true;
}

bool OpenglTexture::isLoad() {
    return _is_load;
}