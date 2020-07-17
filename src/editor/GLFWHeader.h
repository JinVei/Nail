#pragma once

#if __has_include(<GL/gl3w.h>)
#include <GL/gl3w.h>            // Initialize with gl3wInit()
//#elif defined(IMGUI_IMPL_OPENGL_LOADER_GLEW)
#elif __has_include(<GL/glew.h>)
#include <GL/glew.h>            // Initialize with glewInit()
#elif __has_include(<glad/glad.h>)
#include <glad/glad.h>          // Initialize with gladLoadGL()
#elif __has_include(<glad/gl.h>)
#include <glad/gl.h>            // Initialize with gladLoadGL(...) or gladLoaderLoadGL()
#elif __has_include(<glbinding/Binding.h>)
#define GLFW_INCLUDE_NONE       // GLFW including OpenGL headers causes ambiguity or multiple definition errors.
#include <glbinding/Binding.h>  // Initialize with glbinding::Binding::initialize()
#include <glbinding/gl/gl.h>
using namespace gl;
#elif __has_include(<glbinding/glbinding.h>)
#define GLFW_INCLUDE_NONE       // GLFW including OpenGL headers causes ambiguity or multiple definition errors.
#include <glbinding/glbinding.h>// Initialize with glbinding::initialize()
#include <glbinding/gl/gl.h>
using namespace gl;
#else
#error "Cannot detect OpenGL loader!"
#endif

// Include glfw3.h after our OpenGL definitions
#include <GLFW/glfw3.h>
