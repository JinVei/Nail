#pragma once
#include "GraphicAPIHelper.h"
namespace nail {
    class Editor {
    public:
        virtual ~Editor() = default;
        virtual int initialize(GraphicAPIHelper*) = 0;
        virtual void drawUI() = 0;
        virtual int destroy() = 0;
    };
}