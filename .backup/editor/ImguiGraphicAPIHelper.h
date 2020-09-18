#pragma once

namespace nail::editor {
    class ImguiGraphicAPIHelper {
    public:
        virtual int beginFrame() = 0;
        virtual int endFrame() = 0;
        virtual ~ImguiGraphicAPIHelper() = default;
    };
}