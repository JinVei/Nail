SRCS ?= $(shell find ./src/*.c*)
HRD  ?= $(shell find ./src/*.h*)

INCLUDE ?= -I ./include 
#LIBS    ?= -lglfw -lassimp
LIBS    ?= 

all: $(SRCS) $(HRD)
	clang++ -std=c++17 -stdlib=libc++ $(LIBS)  $(SRCS) $(INCLUDE) -o nail
