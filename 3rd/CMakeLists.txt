 
cmake_minimum_required(VERSION 3.0) 

file(GLOB GLAD_SRC  ./glad/*.c*)
file(GLOB GLAD_HDR ./glad/*.h*)
#source_group("3rd/glad" FILES ${GLAD_SRC} ${GLAD_HDR})

#file(GLOB IMGUI_SRC  ./imgui/*.c* ./imgui/examples/imgui_impl_glfw*.c* imgui/examples/imgui_impl_opengl3*.c* )
#file(GLOB IMGUI_HRD ./imgui/*.h* ./imgui/examples/imgui_impl_glfw*.h* imgui/examples/imgui_impl_opengl3*.h*)
file(GLOB IMGUI_SRC  ./imgui/*.c* )
file(GLOB IMGUI_HRD ./imgui/*.h* )
source_group("3rd/imgui" FILES ${IMGUI_SRC} ${IMGUI_HRD})

file(GLOB STB_IMAGE_SRC  ./stb_image/*.c*)
file(GLOB STB_IMAGE_HRD ./stb_image/*.h*)

ADD_LIBRARY(${imgui_lib_name}   STATIC   ${IMGUI_SRC} ${IMGUI_HRD})
ADD_LIBRARY(${glad_lib_name}   STATIC   ${GLAD_SRC} ${GLAD_HDR})
ADD_LIBRARY(${stb_image_lib_name}   STATIC   ${STB_IMAGE_SRC} ${STB_IMAGE_HRD})

target_include_directories(${imgui_lib_name} PRIVATE ./imgui)

set_target_properties(  ${imgui_lib_name}
                        PROPERTIES PUBLIC_HEADER 
                        "imgui/imgui.h;imgui/imconfig.h;imgui/examples/imgui_impl_opengl3.h;imgui/examples/imgui_impl_glfw.h")

INSTALL(TARGETS ${imgui_lib_name} 
        LIBRARY DESTINATION ./lib
        PUBLIC_HEADER DESTINATION include/imgui
)

set_target_properties(${glad_lib_name} PROPERTIES PUBLIC_HEADER "glad/glad.h")
INSTALL(TARGETS ${glad_lib_name} 
        LIBRARY DESTINATION ./lib
        PUBLIC_HEADER DESTINATION include/glad
)

set_target_properties(${stb_image_lib_name} PROPERTIES PUBLIC_HEADER "stb_image/stb_image.h")
INSTALL(TARGETS ${stb_image_lib_name} 
        LIBRARY DESTINATION ./lib
        PUBLIC_HEADER DESTINATION include/stb_image
)