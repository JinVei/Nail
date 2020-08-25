#include "EntityFactory.h"
#include "common/assert.h"
#include "Entity.h"
#include "MeshManager.h"

using namespace nail;

ConstString EntityFactoryParamName::ENTITY_NAME = "entity_name";
ConstString EntityFactoryParamName::RESOURCE_PATH = "resource_path";

ref<SceneObject> EntityFactory::createImpl(ParamList param_list) {
    auto resource_it =  param_list.find(EntityFactoryParamName::RESOURCE_PATH);
    NAIL_ASSERT(resource_it != param_list.end());

    ConstString resource_path = resource_it->second;
    ref<MeshTree> mesh_tree = MeshManager::singleton()->retrieveOrCreate(resource_path);
    NAIL_ASSERT(mesh_tree != nullptr);

    return _createEntityRecursive(mesh_tree);
}

ref<Entity> EntityFactory::_createEntityRecursive(ref<MeshTree> mesh_tree) {
    EntityPtr root = EntityPtr(new Entity(getManager()));
    root->setMeshs(std::move(*(mesh_tree->_data)));
    for(auto& sub_mesh_tree : mesh_tree->_childs) {
        EntityPtr sub_entity =  _createEntityRecursive(sub_mesh_tree);
        root->addSubEntity(sub_entity);
    }
    return root;
}

EntityFactory::EntityFactory(wref<SceneManager> owner): SceneObjectFactory(owner) {
}