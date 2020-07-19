#pragma once
namespace nail::editor {
    class Editor {
    public:
        virtual ~Editor() = default;
        virtual int initialize() = 0;
        virtual void drawUI() = 0;
        virtual int destroy() = 0;
    };
}