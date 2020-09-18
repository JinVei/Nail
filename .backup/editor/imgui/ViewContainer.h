#pragma once
#include "View.h"
#include <string>
namespace nail::editor::imgui {
    class ViewContainer: virtual public View {
        std::string title_ = " ";
    public:
        ViewContainer(long id, std::string title);
        ViewContainer* setTitle(std::string);
        void draw() override;
    };
}