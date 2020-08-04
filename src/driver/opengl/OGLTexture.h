// #pragma once 

// #include "glad/glad.h"

// #include <string>
// #include <fstream>
// #include <sstream>
// #include <iostream>

// namespace nail{
//     class OGLTexture
//     {
//     public:
//         enum class TextureType {

//         };
//         OGLTexture(const GLchar* texturePath);
//         ~OGLTexture();

//         void apply(unsigned int location);

//         void setTexParameter(GLenum name, GLenum value);
//         void setTexParameter(GLenum name, GLfloat* value);
//         int GetID();
//         OGLTexture& operator= (const OGLTexture& right) = delete;
//         OGLTexture(const OGLTexture& right) = delete;
//     private:
//         unsigned int ID = 0;
//         bool isOK = true;
//         int width;
//         int height;
//         int nrChannels;
//         TextureType type;
//     };
// }
