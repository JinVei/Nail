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
    SceneManager::set(ref<SceneManager>(new SceneManager()));
    MeshManager::set(ref<MeshManager>(new MeshManager()));
    RenderSystem::setSingleton(ref<RenderSystem>( new OpenglRenderSystem()));
    TextureManager::setSingleton(ref<TextureManager>(new TextureManager));

    RenderSystem::getSingleton()->setup();

    ref<EntityFactory> entity_factory = ref<EntityFactory>(new EntityFactory());
    SceneManager::singleton()->addSceneObjectFactoty(SceneObjectType::ENTITY,entity_factory);

    ref<MeshLoader> mesh_loader = ref<MeshLoader>(new ObjMeshLoader());
    MeshManager::singleton()->registerMeshLoader(mesh_loader->getExtensionName(), mesh_loader);

    auto vertex_buffer_factory = ref<OpenglVertexBufferFactory>(new OpenglVertexBufferFactory());
    RenderSystem::getSingleton()->setRenderVertexBufferFactory(vertex_buffer_factory);

    auto texture_factory = ref<OpenglTextureFactory>(new OpenglTextureFactory());
    auto image_loader = ref<ImageLoaderImpl>(new ImageLoaderImpl());
    TextureManager::getSingleton()->setImageLoader(image_loader);
    TextureManager::getSingleton()->setTextureFactory(texture_factory);

}