```
MoveableObj <- Entity
MoveableObjFactory <- EntityFactory
scnMgr->createEntity -> createMovableObject -> MovableObjectFactory.createInstance -> EntityFactory.createInstanceImpl -> MeshManager.load -> MeshManager.createOrRetrieve/pMesh->load() -> ResourceManager::createOrRetrieve -> MeshManager::createImpl
-> Mesh->load()/resource->load() -> Mesh->loadImpl -> MeshSerializer->importMesh
```
接口impl的问题