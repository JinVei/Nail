#include "OGLTexture.h"
#include "stb_image/stb_image.h"
using namespace nail;

OGLTexture::~OGLTexture()
{
    if (ID != 0)
    {
        glDeleteTextures(1, &ID);
    }
}

OGLTexture::OGLTexture(const GLchar* texturePath)
{
    glGenTextures(1, &ID);
    glBindTexture(GL_TEXTURE_2D, ID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    stbi_set_flip_vertically_on_load(true);
    unsigned char *data = stbi_load(texturePath, &width, &height, &nrChannels, 0);

    if (!data)
    {
        std::cout << "Failed to load texture" << std::endl;
        isOK = false;
        return;
    }

    GLenum format;
    if (nrChannels == 1) {
        format = GL_RED;
    } else if (nrChannels == 3) {
        format = GL_RGB;
    } else if (nrChannels == 4) {
        format = GL_RGBA;
    } else {
        std::cout << "Unknow format:" << format << std::endl;
        isOK = false;
        return;
    } 

    glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    
    stbi_image_free(data);
}
void OGLTexture::apply(unsigned int location)
{
    glActiveTexture(GL_TEXTURE0 + location);
    glBindTexture(GL_TEXTURE_2D, ID);
}
int OGLTexture::GetID()
{
    return ID;
}

void OGLTexture::setTexParameter(GLenum name, GLenum value)
{
    glTexParameteri(GL_TEXTURE_2D, name, value);
}

void OGLTexture::setTexParameter(GLenum name, GLfloat* value)
{
    glTexParameterfv(GL_TEXTURE_2D, name, value);
}
