#include "Context.h"
#include "SceneManager.h"
#include "EntityFactory.h"
#include "driver/mesh_loader/ObjMeshLoader.h"
#include "MeshManager.h"

using namespace nail;

void Context::setup() {
    //g_scene_manager = new SceneManager();
    SceneManager::set(ref<SceneManager>(new SceneManager()));
    MeshManager::set(ref<MeshManager>(new MeshManager()));

    ref<EntityFactory> entity_factory = ref<EntityFactory>(new EntityFactory());
    SceneManager::singleton().addSceneObjectFactoty(SceneObjectType::ENTITY,entity_factory);

    ref<MeshLoader> mesh_loader = ref<MeshLoader>(new ObjMeshLoader());
    MeshManager::singleton().registerMeshLoader(mesh_loader->getExtensionName(), mesh_loader);
    
}