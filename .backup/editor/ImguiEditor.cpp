#include "ImguiEditor.h"
#include "imgui/imgui.h"
#include <stdio.h>
#include "common/assert.h"

#define ASSERT JV_ASSERT
using namespace nail::editor;

ImguiEditor::ImguiEditor(ImguiGraphicAPIHelper* gapi_helper) {
    ASSERT(gapi_helper != nullptr);
    gapi_helper_ = gapi_helper;
}

int ImguiEditor::initialize() {
    if (is_init_) {
        return 0;
    }

    is_init_ = true;

    return 0;
}

int ImguiEditor::destroy() {
    if (!is_init_) {
        return 1;
    }

    if (is_destroy_) {
        return 0;
    }
    is_destroy_ = true;
    return 0;
}

ImguiEditor::~ImguiEditor() {
    destroy();
}
static void ImguiDemo();
void ImguiEditor::drawUI() {
    startFrame();
    ImguiDemo();
    endFrame();
}

void ImguiEditor::startFrame() {
    // Start the Dear ImGui frame
    gapi_helper_->beginFrame();
    ImGui::NewFrame();
}

void ImguiEditor::endFrame() {
    ImGui::Render();
    gapi_helper_->endFrame();
}

static void ImguiDemo() {
    bool show_demo_window = true;
    bool show_another_window = false;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    // 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear ImGui!).
    if (show_demo_window)
        ImGui::ShowDemoWindow(&show_demo_window);

    // 2. Show a simple window that we create ourselves. We use a Begin/End pair to created a named window.
    {
        static float f = 0.0f;
        static int counter = 0;

        ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

        ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
        ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
        ImGui::Checkbox("Another Window", &show_another_window);

        ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
        ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

        if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
            counter++;
        ImGui::SameLine();
        ImGui::Text("counter = %d", counter);

        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
        ImGui::End();
    }

    // 3. Show another simple window.
    if (show_another_window)
    {
        ImGui::Begin("Another Window", &show_another_window);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
        ImGui::Text("Hello from another window!");
        if (ImGui::Button("Close Me"))
            show_another_window = false;
        ImGui::End();
    }
}