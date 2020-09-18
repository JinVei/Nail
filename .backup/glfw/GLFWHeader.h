#pragma once

#if __has_include("glad/glad.h")
#include "glad/glad.h"          // Initialize with gladLoadGL()
#else
#error "Cannot detect OpenGL loader!"
#endif

// Include glfw3.h after our OpenGL definitions
#include <GLFW/glfw3.h>
