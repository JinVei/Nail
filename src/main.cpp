#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include "driver/opengl/OpenglShader.h"
#include "scene/Context.h"
#include "renderer/RenderTarget.h"
#include "common/ref.h"
#include "common/vec.h"

#include <chrono>
#include <thread>
#include <iostream>

int main(int, char**)
{
    nail::Context::instance().setup();
    auto scene_mgr = nail::Context::instance().getActiveSceneManager(); 
    auto render_sys = nail::Context::instance().getActiveRenderSystem();
    // create entity
    // create camera
    // create render taget
    // create light
    // create scene node 
    nail::EntityNodePtr nanosuit = scene_mgr->createEntity("nanosuit", "../resource/objs/nanosuit/nanosuit.obj");
    nail::ref<nail::Camera> camera = scene_mgr->createCamera(nail::vec3(0,0,-1), nail::Position(0,3,0), 45, 0.1, 100);
    nail::ref<nail::RenderTarget> render_target = render_sys->createRenderTarget(1280,1024);
    camera->setRenderTarget(render_target);

    //scene_mgr->createPointLight(nail::vec3(0,0,1), nail::Color(1, 1, 1, 1));
    scene_mgr->createDirectionalLight(nail::vec3(0,0,-1), nail::Color(1, 0.5, 1, 1));

    nanosuit->move(nail::Position(0,0,-3));
    nanosuit->scale(nail::vec3(0.3f, 0.3f, 0.3f));
    scene_mgr->getRootNode()->addChild(nanosuit);

    while (!render_sys->windowShouldClose()) {
        scene_mgr->render();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return 0;
}
