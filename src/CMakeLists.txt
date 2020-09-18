 
cmake_minimum_required(VERSION 3.0) 

#file(GLOB_RECURSE EDITORE_SRC  ./editor/*.c*)
#file(GLOB_RECURSE EDITOR_HDR ./editor/*.h*)
#source_group("editor" FILES ${EDITORE_SRC} ${EDITOR_HDR})

file(GLOB_RECURSE COMMON_SRC  ./common/*.c*)
file(GLOB_RECURSE COMMON_HRD ./common/*.h*)
source_group("common" FILES ${COMMON_SRC} ${COMMON_HRD})

file(GLOB_RECURSE SCENE_SRC  ./scene/*.c*)
file(GLOB_RECURSE SCENE_HDR ./scene/*.h*)
source_group("scene" FILES ${SCENE_SRC} ${SCENE_HDR})

file(GLOB_RECURSE RENDERER_SRC  ./renderer/*.c*)
file(GLOB_RECURSE RENDERER_HDR ./renderer/*.h*)
source_group("renderer" FILES ${RENDERER_SRC} ${RENDERER_HDR})

file(GLOB_RECURSE DRIVER_SRC  ./driver/*.c*)
file(GLOB_RECURSE DRIVER_HDR ./driver/*.h*)
source_group("driver" FILES ${DRIVER_SRC} ${DRIVER_HDR})


#set(ALL_SRC ./main.cpp ${EDITORE_SRC} ${EDITOR_HDR} ${COMMON_SRC} ${COMMON_HRD} ${SCENE_SRC} ${SCENE_HDR} ${RENDERER_SRC} ${RENDERER_HDR})
set(ALL_SRC ./main.cpp ${COMMON_SRC} ${COMMON_HRD} ${SCENE_SRC} ${SCENE_HDR} ${RENDERER_SRC} ${RENDERER_HDR} ${DRIVER_SRC} ${DRIVER_HDR})

#add_definitions(-D_CRT_SECURE_NO_WARNINGS)
#ADD_LIBRARY(libNail   STATIC   ${M_SRC} )


set(TARGET_NAME Nail)
add_executable(${TARGET_NAME} ${ALL_SRC} )

ADD_DEPENDENCIES(${TARGET_NAME} ${imgui_lib_name} ${glad_lib_name} ${stb_image_lib_name})

if(APPLE)
    #link_directories(/usr/local/lib /usr/local/opt/glew/lib)
    SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -framework OpenGL")
    SET(CMAKE_FIND_LIBRARY_PREFIXES "")
    SET(CMAKE_FIND_LIBRARY_SUFFIXES ".dylib" ".a")
elseif(LINUX)
    #link_directories(/usr/lib/x86_64-linux-gnu)
    target_link_libraries(${TARGET_NAME} GL)
    SET(CMAKE_FIND_LIBRARY_PREFIXES "")
    SET(CMAKE_FIND_LIBRARY_SUFFIXES ".so" ".a")
endif()

find_package(Boost)

if(UNIX)
    set(lib_dir "/usr/local/lib"
                "/usr/lib"
                "/usr/local/opt/glew/lib"
                "/usr/lib/x86_64-linux-gnu"
                "${THIRD_DIR}/lib"
                ${Boost_LIBRARY_DIRS})
endif()


find_library(glfw_library NAMES libglfw HINTS ${lib_dir} )
find_library(assimp_library NAMES libassimp HINTS ${lib_dir} )
#find_library(glew_library NAMES libGLEW libglew  HINTS ${lib_dir})
find_library(lua_library NAMES liblua HINTS ${lib_dir})
find_library(boost_library NAMES libboost_filesystem HINTS ${lib_dir})

set(ALL_LINK_LIB ${glfw_library} 
                ${assimp_library}
                ${glew_library}
                ${glad_lib_name}
                #${imgui_lib_name}
                ${lua_library}
                ${boost_library}
                ${stb_image_lib_name})

if(UNIX AND NOT APPLE)
    set(ALL_LINK_LIB ${ALL_LINK_LIB} -lpthread -ldl -lGL)
endif()

target_link_libraries(${TARGET_NAME} ${ALL_LINK_LIB})
