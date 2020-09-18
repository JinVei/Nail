#include "MeshManager.h"
#include "common/assert.h"
using namespace nail;


MeshManager::MeshManager() {
}

void MeshManager::setSelf(wref<MeshManager> self) {
    _self = self;
}

ref<MeshTree> MeshManager::retrieveOrCreate(ConstString path) {
    auto rs = getResource(String(path));
    ref<MeshTreeRs> mesh_tree_rs  = ref_cast<MeshTreeRs>(rs);
    if (mesh_tree_rs != nullptr) {
        return mesh_tree_rs->get();
    }

    size_t dot_pos = path.find_last_of(".");
    String extend_name = String(path).substr(dot_pos + 1);
    ref<MeshLoader> loader = _mesh_loaders[extend_name];
    NAIL_ASSERT(loader != nullptr);

    ref<MeshTree> mesh_tree = loader->load(path);
    NAIL_ASSERT(mesh_tree != nullptr);

    ref<MeshTreeRs> new_rs = ref<MeshTreeRs>(new MeshTreeRs(mesh_tree));
    saveResource(String(path), new_rs);
    return mesh_tree;
}

bool MeshManager::registerMeshLoader(ExtensionName extend_name, ref<MeshLoader> loader) {
    _mesh_loaders[extend_name] = loader;
    return true;
}