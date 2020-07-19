#include "ViewContainer.h"
#include "imgui/imgui.h"
#include "common/assert.h"

using namespace nail::editor::imgui;

ViewContainer::ViewContainer(long id, std::string title): View(id) {
    JV_ASSERT(title != "" && id != 0);
    title_ = title;
}

ViewContainer* ViewContainer::setTitle(std::string title) {
    title_ = title;
    return this;
}

void ViewContainer::draw() {
    ImGui::Begin(title_.c_str());
    drawChilds();
    ImGui::End();
}