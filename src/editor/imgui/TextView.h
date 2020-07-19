#pragma once
#include "View.h"
#include <string>
namespace nail::editor::imgui {
    class TextView: virtual public View {
        std::string text_ = " ";
    public:
        TextView(long id, std::string text);
        TextView* setText(std::string);
        void draw() override;
    };
}