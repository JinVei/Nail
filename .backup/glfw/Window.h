#pragma once
#include <string>
namespace nail {
    class Window {
    public:
        virtual ~Window() = default;
        virtual std::string getName() = 0;
        virtual std::string getTitle() = 0;
        virtual int setTitle(std::string) = 0;
        virtual int setSize(int wide, int heigh) = 0;
        virtual std::pair<int,int> getSize() = 0;
        virtual bool isClosed() = 0;
    };
}