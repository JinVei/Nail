 
cmake_minimum_required(VERSION 3.0) 

file(GLOB GLAD_SRC  ./glad/*.c*)
file(GLOB GLAD_HDR ./glad/*.h*)
source_group("3rd/glad" FILES ${GLAD_SRC} ${GLAD_HDR})

file(GLOB IMGUI_SRC  ./imgui/*.c* ./imgui/examples/imgui_impl_glfw*.c* imgui/examples/imgui_impl_opengl3*.c* )
file(GLOB IMGUI_HRD ./imgui/*.h* ./imgui/examples/imgui_impl_glfw*.h* imgui/examples/imgui_impl_opengl3*.h*)
source_group("3rd/imgui" FILES ${IMGUI_SRC} ${IMGUI_HRD})


ADD_LIBRARY(lib3rdimgui   STATIC   ${IMGUI_SRC} ${IMGUI_HRD})
ADD_LIBRARY(lib3rdglad   STATIC   ${GLAD_SRC} ${GLAD_HDR})
