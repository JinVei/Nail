#include "editor/ImguiEditor.h"
#include "renderer/graphic_api/GLFWGraphicAPIHelper.h"
#include "renderer/graphic_api/GraphicAPIHelper.h"
#include "renderer/graphic_api/GLFWImguiGraphicAPIHelper.h"

using namespace nail;
int main(int, char**)
{
    auto glfwGraphicAPIHelper = new GLFWGraphicAPIHelper();
    GraphicAPIHelper* gapi_helper = glfwGraphicAPIHelper;
    gapi_helper->initGraphicApi();

    auto  glfwImguiGraphicAPIHelper = new GLFWImguiGraphicAPIHelper(glfwGraphicAPIHelper);
    glfwImguiGraphicAPIHelper->initialize();

    nail::Editor* editor = new ImguiEditor(glfwImguiGraphicAPIHelper);
    editor->initialize();

    // Main loop
    while (!gapi_helper->isCurrtentWindowClosed())
    {
        // Poll and handle events (inputs, window resize, etc.)
        // You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
        // - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application.
        // - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application.
        // Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
        glfwPollEvents();

        editor->drawUI();
        gapi_helper->Update();
    }

    editor->destroy();

    gapi_helper->destroy();

    return 0;
}
