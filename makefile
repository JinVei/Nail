SRCS ?= $(shell find ./src/*.c* \
                     ./src/*/*.c* \
                     ./3rd/imgui/*.c* \
                     ./3rd/imgui/examples/imgui_impl_glfw*.c* \
                     ./3rd/imgui/examples/imgui_impl_opengl3*.c* \
                     ./3rd/glad/*.c* \
                     )

HRD  ?= $(shell find ./src/*.h* \
                     ./src/*/*.h* \
                     ./3rd/imgui/*.h* \
                     ./3rd/imgui/examples/imgui_impl_glfw*.h* \
                     ./3rd/imgui/examples/imgui_impl_opengl3*.h* \
                     ./3rd/glad/*.h* \
                     ./3rd/KHR/*.h*)

INCLUDE ?=   -I /usr/local/include/c++ \
             -I /usr/local/include \
             -I ./include \
             -I ./src \
             -I ./3rd/imgui \
             -I ./3rd 

LIB_DIR ?= -L/usr/local/lib -L/usr/local/opt/glew/lib
LIBS    ?= -lglfw -lassimp -framework OpenGL -lglew
FLAGS   ?= -std=c++17 -stdlib=libc++ -g

all: $(SRCS) $(HRD)
	clang++  $(FLAGS) $(LIBS)  $(SRCS) $(INCLUDE) $(LIB_DIR) -o nail
