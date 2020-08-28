#include "Context.h"
#include "SceneManager.h"
#include "EntityFactory.h"
#include "driver/mesh_loader/ObjMeshLoader.h"
#include "MeshManager.h"
#include "renderer/RenderSystem.h"
#include "driver/opengl/OpenglVertexBufferFactory.h"
#include "TextureManager.h"
#include "driver/opengl/OpenglTextureFactory.h"
#include "driver/image_loader/ImageLoaderImpl.h"
#include "driver/opengl/OpenglRenderSystem.h"

using namespace nail;

void Context::setup() {
    _active_scene_manager = ref<SceneManager>(new SceneManager());
    _active_scene_manager->setSelf(_active_scene_manager);
    
    _active_mesh_manager = ref<MeshManager>(new MeshManager());
    _active_texture_manager = ref<TextureManager>(new TextureManager());
    _active_render_system = ref<RenderSystem>( new OpenglRenderSystem());

   _active_render_system->setup();

    ref<EntityFactory> entity_factory = ref<EntityFactory>(new EntityFactory(_active_scene_manager));
    _active_scene_manager->addSceneObjectFactoty(SceneObjectType::ENTITY,entity_factory);

    ref<MeshLoader> mesh_loader = ref<MeshLoader>(new ObjMeshLoader());
    _active_mesh_manager->registerMeshLoader(mesh_loader->getExtensionName(), mesh_loader);

    auto vertex_buffer_factory = ref<OpenglVertexBufferFactory>(new OpenglVertexBufferFactory());
    _active_render_system->setRenderVertexBufferFactory(vertex_buffer_factory);

    auto texture_factory = ref<OpenglTextureFactory>(new OpenglTextureFactory(_active_texture_manager));
    auto image_loader = ref<ImageLoaderImpl>(new ImageLoaderImpl());
    _active_texture_manager->setImageLoader(image_loader);
    _active_texture_manager->setTextureFactory(texture_factory);
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
