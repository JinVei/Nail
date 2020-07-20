cmake_minimum_required(VERSION 3.0) 

set(PROJECT_NAME Nail)
project(${PROJECT_NAME})

set(PROJECT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(THIRD_DIR ${CMAKE_CURRENT_SOURCE_DIR}/3rd)

if(UNIX AND NOT APPLE)
    set(LINUX TRUE)
endif()


if(LINUX) 
    include_directories(/usr/include/c++)
    include_directories(/usr/include)
elseif(APPLE)
    include_directories(/usr/local/include/c++)
    include_directories(/usr/local/include)
else()
    message(FATAL_ERROR "Not Linux or APPLE")
endif()

include_directories(${THIRD_DIR})
include_directories(${THIRD_DIR}/include)

include_directories(${THIRD_DIR}/imgui)
#include_directories(${THIRD_DIR}/imgui/examples)

link_directories(${THIRD_DIR}/lib)

include_directories(${SRC_DIR})


set(CMAKE_CXX_STANDARD 17)

if(UNIX)
    SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -g")
endif()

set(imgui_lib_name 3rdimgui)
set(glad_lib_name 3rdglad)

add_subdirectory(${THIRD_DIR})

add_subdirectory(${SRC_DIR})

#get_directory_property(${THIRD_DIR} DIRECTORY ${SRC_DIR} VARIABLES THIRD_DIR)
#add_subdirectory(./test/)
