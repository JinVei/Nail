#pragma once 

#include "glad/glad.h"

#include <string>
#include <fstream>s
#include <sstream>
#include <iostream>

namespace nail{
    class Texture
    {
    public:
        enum class TextureType {

        };
        Texture(const GLchar* texturePath);
        ~Texture();

        void apply(unsigned int location);

        void setTexParameter(GLenum name, GLenum value);
        void setTexParameter(GLenum name, GLfloat* value);
        int GetID();
        Texture& operator= (const Texture& right) = delete;
        Texture(const Texture& right) = delete;
    private:
        unsigned int ID = 0;
        bool isOK = true;
        int width;
        int height;
        int nrChannels;
        TextureType type;
    };
}
