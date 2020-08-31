#include "OpenglShader.h"
#include "common/assert.h"

#include <fstream>
#include <sstream>
#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace nail;

OpenglShader::OpenglShader(String vertex_program_path, String fragment_program_path) {
    _vertex_program_path = vertex_program_path;
    _fragment_program_path = fragment_program_path;
}

OpenglShader::~OpenglShader() {
    if(_glid) {
        glDeleteProgram(_glid);
    }
}

void OpenglShader::apply() { 
    glUseProgram(_glid);
}

void unapply() {
    glUseProgram(0);
}

int OpenglShader::getID() {
    return _glid;
}

void OpenglShader::setUniform(const std::string &name, bool value) const {
    glUniform1i(glGetUniformLocation(_glid, name.c_str()), (int)value); 
}

void OpenglShader::setUniform(const std::string &name, int value) const { 
    glUniform1i(glGetUniformLocation(_glid, name.c_str()), value); 
}

void OpenglShader::setUniform(const std::string &name, float value) const { 
    glUniform1f(glGetUniformLocation(_glid, name.c_str()), value); 
}

void OpenglShader::setUniform(const std::string &name, mat4& value) const {
    glUniformMatrix4fv(glGetUniformLocation(_glid, name.c_str()),1, GL_FALSE, glm::value_ptr(value)); 
}

void OpenglShader::setUniform(const std::string &name, const vec3 &value) const { 
    glUniform3fv(glGetUniformLocation(_glid, name.c_str()), 1, &value[0]); 
}

void OpenglShader::setUniform(const std::string &name, const vec4 &value) const {
    glUniform4fv(glGetUniformLocation(_glid, name.c_str()), 1, &value[0]); 
}

bool OpenglShader::load() {
    std::string vertex_program_source;
    std::string fragment_program_source;
    std::ifstream vertex_program_fstream;
    std::ifstream fragment_program_fstream;

    // throwable
    vertex_program_fstream.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    fragment_program_fstream.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    try {
        vertex_program_fstream.open(_vertex_program_path);
        fragment_program_fstream.open(_fragment_program_path);
        std::stringstream vShaderStream, fShaderStream;

        vShaderStream << vertex_program_fstream.rdbuf();
        fShaderStream << fragment_program_fstream.rdbuf();       

        vertex_program_fstream.close();
        fragment_program_fstream.close();

        vertex_program_source   = vShaderStream.str();
        fragment_program_source = fShaderStream.str();     

    } catch(std::ifstream::failure e) {
        NAIL_ASSERT(false && "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ");
        return false;
    }
    const char* vshader_source = vertex_program_source.c_str();
    const char* fshader_source = fragment_program_source.c_str();

    GLuint vertex, fragment;
    int success;
    char infoLog[512];

    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vshader_source, NULL);
    glCompileShader(vertex);
    glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(vertex, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
        NAIL_ASSERT(false && "ERROR::SHADER::VERTEX::COMPILATION_FAILED");
        return false;
    }


    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fshader_source, NULL);
    glCompileShader(fragment);
    glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(fragment, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
        NAIL_ASSERT(false && "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED");
        return false;
    }

    _glid = glCreateProgram();
    glAttachShader(_glid, vertex);
    glAttachShader(_glid, fragment);
    glLinkProgram(_glid);

    glGetProgramiv(_glid, GL_LINK_STATUS, &success);
    if(!success)
    {
        glGetProgramInfoLog(_glid, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
        NAIL_ASSERT(false && "ERROR::SHADER::LINKING_FAILED");
        return false;
    }

    glDeleteShader(vertex);
    glDeleteShader(fragment);
    return true;
}
