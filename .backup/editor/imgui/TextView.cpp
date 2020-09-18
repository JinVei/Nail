#include "TextView.h"
#include "imgui/imgui.h"
#include "common/assert.h"

using namespace nail::editor::imgui;

TextView::TextView(long id, std::string text): View(id) {
    JV_ASSERT(text != "" && id != 0);
    text_ = text;
}

TextView* TextView::setText(std::string text) {
    text_ = text;
    return this;
}

void TextView::draw() {
    ImGui::Text("%s", text_.c_str());
}