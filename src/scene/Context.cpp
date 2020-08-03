#include "Context.h"
#include "SceneManager.h"
#include "EntityFactory.h"
#include "driver/mesh_loader/ObjMeshLoader.h"
#include "MeshManager.h"
#include "renderer/RenderSystem.h"
#include "driver/opengl/OpenglVertexBufferFactory.h"

using namespace nail;

void Context::setup() {
    SceneManager::set(ref<SceneManager>(new SceneManager()));
    MeshManager::set(ref<MeshManager>(new MeshManager()));
    RenderSystem::setSingleton(ref<RenderSystem>( new RenderSystem()));

    ref<EntityFactory> entity_factory = ref<EntityFactory>(new EntityFactory());
    SceneManager::singleton()->addSceneObjectFactoty(SceneObjectType::ENTITY,entity_factory);

    ref<MeshLoader> mesh_loader = ref<MeshLoader>(new ObjMeshLoader());
    MeshManager::singleton()->registerMeshLoader(mesh_loader->getExtensionName(), mesh_loader);

    auto vertex_buffer_factory= ref<OpenglVertexBufferFactory>(new OpenglVertexBufferFactory());
    RenderSystem::singleton()->setRenderVertexBufferFactory(vertex_buffer_factory);

}