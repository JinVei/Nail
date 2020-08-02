#include "Context.h"
#include "SceneManager.h"
#include "EntityFactory.h"
#include "driver/mesh_loader/ObjMeshLoader.h"

using namespace nail;

void Context::setup() {
    g_scene_manager = new SceneManager();
    ref<EntityFactory> entity_factory = ref<EntityFactory>(new EntityFactory());
    ref<MeshLoader> mesh_loader = ref<MeshLoader>(new ObjMeshLoader());
    entity_factory->setMeshLoader(mesh_loader);
    
    g_scene_manager->addSceneObjectFactoty(SceneObjectType::ENTITY,entity_factory);
}