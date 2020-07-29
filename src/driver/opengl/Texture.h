#pragma once 

#include "glad/glad.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

namespace nail{
    class Texture
    {
    public:
        enum class TextureType {

        };
        Texture();
        ~Texture();
    protected:
        int width;
        int height;
        int channel;
        std::string path;
        TextureType type;
    };
}
