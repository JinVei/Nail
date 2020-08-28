#include "Context.h"
#include "SceneManager.h"
#include "EntityFactory.h"
#include "driver/mesh_loader/ObjMeshLoader.h"
#include "MeshManager.h"
#include "renderer/RenderSystem.h"
#include "driver/opengl/OpenglVertexBufferFactory.h"
#include "TextureManager.h"
#include "driver/image_loader/ImageLoaderImpl.h"
#include "driver/opengl/OpenglRenderSystem.h"
#include "driver/opengl/OpenglTextureManager.h"

using namespace nail;

void Context::setup() {
    _active_scene_manager = ref<SceneManager>(new SceneManager());
    _active_scene_manager->setSelf(_active_scene_manager);
    
    _active_mesh_manager = ref<MeshManager>(new MeshManager());
    _active_mesh_manager->setSelf(_active_mesh_manager);

    _active_texture_manager = ref<TextureManager>(new OpenglTextureManager());
    _active_texture_manager->setSelf(_active_texture_manager);

    _active_render_system = ref<OpenglRenderSystem>(new OpenglRenderSystem());
    _active_render_system->setSelf(_active_render_system);


   _active_render_system->setup();

    ref<EntityFactory> entity_factory = ref<EntityFactory>(new EntityFactory(_active_scene_manager));
    _active_scene_manager->addSceneObjectFactoty(SceneObjectType::ENTITY,entity_factory);

    ref<MeshLoader> mesh_loader = ref<MeshLoader>(new ObjMeshLoader());
    _active_mesh_manager->registerMeshLoader(mesh_loader->getExtensionName(), mesh_loader);

    auto vertex_buffer_factory = ref<OpenglVertexBufferFactory>(new OpenglVertexBufferFactory());
    _active_render_system->setRenderVertexBufferFactory(vertex_buffer_factory);

    auto image_loader = ref<ImageLoaderImpl>(new ImageLoaderImpl());
    _active_texture_manager->setImageLoader(image_loader);
}


ref<SceneManager> Context::getActiveSceneManager() {
    return _active_scene_manager;
}

ref<TextureManager> Context::getActiveTextureManager() {
    return _active_texture_manager;
}

ref<MeshManager> Context::getActiveMeshManager() {
    return _active_mesh_manager;
}

ref<RenderSystem> Context::getActiveRenderSystem() {
    return _active_render_system;
}
