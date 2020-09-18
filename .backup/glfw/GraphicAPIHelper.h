#pragma once
#include <string>
#include <functional>
namespace nail {
    class GraphicAPIHelper {
    public:
        virtual ~GraphicAPIHelper() {};
        //virtual int setWindowsEventHandler(std::string window_name, std::function<void()>) = 0;
        virtual int initGraphicApi() = 0;
        virtual int createWindow(std::string window_name, int w, int h) = 0;
        virtual int useWindow(std::string window_name) = 0;
        virtual bool isCurrtentWindowClosed() = 0;
        virtual int destroy() = 0;
        virtual int Update() = 0;
    };
    extern GraphicAPIHelper* g_graphicAPIHelper;
}