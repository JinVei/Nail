#include "EntityFactory.h"
#include "common/assert.h"
#include "Entity.h"
#include "MeshManager.h"
#include "SceneManager.h"
#include "scene/Context.h"

using namespace nail;

ConstString EntityFactoryParamName::ENTITY_NAME = "entity_name";
ConstString EntityFactoryParamName::RESOURCE_PATH = "resource_path";

ref<SceneObject> EntityFactory::createImpl(ParamList param_list) {
    auto resource_it =  param_list.find(EntityFactoryParamName::RESOURCE_PATH);
    NAIL_ASSERT(resource_it != param_list.end());

    ConstString resource_path = resource_it->second;
    auto mesh_mgr = Context::instance().getActiveMeshManager();
    NAIL_ASSERT(mesh_mgr != nullptr);

    ref<MeshTree> mesh_tree = mesh_mgr->retrieveOrCreate(resource_path);
    NAIL_ASSERT(mesh_tree != nullptr);

    return _createEntityRecursive(mesh_tree);
}

ref<EntityNode> EntityFactory::_createEntityRecursive(ref<MeshTree> mesh_tree) {
    auto entity = EntityPtr(new Entity(getManager(), std::move(*(mesh_tree->_data))));

    EntityNodePtr root = EntityNodePtr(new EntityNode(getManager()));
    root->setEntity(entity);

    for(auto& sub_mesh_tree : mesh_tree->_childs) {
        EntityNodePtr sub_entity =  _createEntityRecursive(sub_mesh_tree);
        root->addSubEntity(sub_entity);
    }
    return root;
}

EntityFactory::EntityFactory(wref<SceneManager> manager): SceneObjectFactory(manager) {
}