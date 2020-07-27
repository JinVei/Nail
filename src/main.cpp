// #include "editor/ImguiEditor.h"
// #include "renderer/glfw/GLFWGraphicAPIHelper.h"
// #include "renderer/glfw/GraphicAPIHelper.h"
// #include "renderer/glfw/GLFWImguiGraphicAPIHelper.h"
// #include "editor/imgui/View.h"
// #include "editor/imgui/TextView.h"
// #include "editor/imgui/ViewContainer.h"
// #include "editor/LuaUIPlugin.h"
// #include "editor/LuaUIPluginManager.h"

// using namespace nail;
// using namespace nail::editor;
// using namespace nail::renderer::glfw;
int main(int, char**)
{
//     auto glfwGraphicAPIHelper = new GLFWGraphicAPIHelper();
//     GraphicAPIHelper* gapi_helper = glfwGraphicAPIHelper;
//     gapi_helper->initGraphicApi();

//     ref<GLFWImguiGraphicAPIHelper>  glfwImguiGraphicAPIHelper(new GLFWImguiGraphicAPIHelper(glfwGraphicAPIHelper));
//     glfwImguiGraphicAPIHelper->initialize();

//     Editor* editor = new ImguiEditor(glfwImguiGraphicAPIHelper.get());
//     editor->initialize();

//     auto container = ref<nail::editor::imgui::ViewContainer>(new nail::editor::imgui::ViewContainer(1, "new window"));
//     auto text_view1 = ref<nail::editor::imgui::TextView>(new nail::editor::imgui::TextView(2, "new Text"));
//     container->add(text_view1);

//     ref<nail::editor::imgui::View> root = container;

//     LuaUIPlugin ui_plugin("./demo.lua");
//     if(ui_plugin.load() != 0){
//         return 1;
//     }
    
//  //   LuaUIPluginManager luaui_mgr;
//  //   auto s = luaui_mgr.listPluginPath("./");
 
//     // Main loop
//     while (!gapi_helper->isCurrtentWindowClosed())
//     {
//         // Poll and handle events (inputs, window resize, etc.)
//         // You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
//         // - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application.
//         // - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application.
//         // Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
//         glfwPollEvents();

//         // editor->drawUI();
//         glfwImguiGraphicAPIHelper->beginFrame();
//         // root->draw();
//         ui_plugin.drawUI();
        
//         glfwImguiGraphicAPIHelper->endFrame();
//         gapi_helper->Update();
//     }

//     editor->destroy();

//     gapi_helper->destroy();

    return 0;
}
