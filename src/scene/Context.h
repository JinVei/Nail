#pragma once
#include "common/ref.h"
#include "SceneManager.h"
#include "TextureManager.h"
#include "renderer/RenderSystem.h"
#include "MeshManager.h"

namespace nail {
    class ActiveContext;
    class Context {
    private:
        Context(){}
        virtual ~Context(){}
        ref<SceneManager> _active_scene_manager;
        ref<TextureManager> _active_texture_manager;
        ref<MeshManager> _active_mesh_manager;
        ref<RenderSystem> _active_render_system;
    public:
        void setup();
        static Context& instance() {
            static Context instance;
            return instance;
        }
        ref<SceneManager> getActiveSceneManager();
        ref<TextureManager> getActiveTextureManager();
        ref<MeshManager> getActiveMeshManager();
        ref<RenderSystem> getActiveRenderSystem();
    };
}