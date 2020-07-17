#pragma once
#include "Window.h"
//#include <GLFW/glfw3.h>
#include "GLFWHeader.h"
#include <string>
namespace nail {
    class GLFWwindowWrapper: public Window {
        GLFWwindow* window_;
        std::string name_;
        std::string title_;
        int wide_ = 0;
        int high_ = 0;
    public:
        GLFWwindowWrapper(GLFWwindow* window, int w, int h);
        virtual ~GLFWwindowWrapper();
        GLFWwindow* getWindow();
        virtual std::string getName();
        virtual std::string getTitle();
        virtual int setTitle(std::string name);
        virtual int setSize(int wide, int high);
        virtual std::pair<int,int> getSize();
        virtual bool isClosed();
    };

}