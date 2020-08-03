#include "OpenglVertexBuffer.h"
#include "glad/glad.h"

using namespace nail;

OpenglVertexBuffer::~OpenglVertexBuffer()
{
    if (_VAO){
        glDeleteVertexArrays(1, &_VAO);
    }
    if (_VBO) {
        glDeleteBuffers(1, &_VBO);
    }
    if (_EBO) {
        glDeleteBuffers(1, &_EBO);
    }
}

OpenglVertexBuffer::OpenglVertexBuffer(float* vertices, unsigned int size)
{
    glGenVertexArrays(1, &_VAO);
    glBindVertexArray(_VAO);
    glGenBuffers(1, &_VBO);
    glBindBuffer(GL_ARRAY_BUFFER, _VBO);
    glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

void OpenglVertexBuffer::setIndices(unsigned int* indices, unsigned int size)
{
    glBindVertexArray(_VAO);

    if (_EBO) {
        glDeleteBuffers(1, &_EBO);
    }
    
    glGenBuffers(1, &_EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
    glBindVertexArray(0);
    _hasEBO = true;
}

void OpenglVertexBuffer::setAttribPointer(GLuint loc, unsigned int size, unsigned int step, GLuint offset)
{
    glBindVertexArray(_VAO);
    glVertexAttribPointer(loc, size, GL_FLOAT, GL_FALSE, step, (void*)(offset*sizeof(float)));
    glEnableVertexAttribArray(loc);
    glBindVertexArray(0);
}

void OpenglVertexBuffer::apply(){
    glBindVertexArray(_VAO);
}

void OpenglVertexBuffer::unapply(){
    glBindVertexArray(0);
}

bool OpenglVertexBuffer::hasIndexBuffer() {
    return _hasEBO;
}