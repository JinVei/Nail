```
MoveableObj <- Entity
MoveableObjFactory <- EntityFactory
scnMgr->createEntity -> createMovableObject -> MovableObjectFactory.createInstance -> EntityFactory.createInstanceImpl -> MeshManager.load -> MeshManager.createOrRetrieve/pMesh->load() -> ResourceManager::createOrRetrieve -> MeshManager::createImpl
-> Mesh->load()/resource->load() -> Mesh->loadImpl -> MeshSerializer->importMesh
```
接口impl的问题

/*
Shared geometry:

Create your Mesh object
Create the vertex declaration
Create your different vertex buffers (separate [position+normals] from the rest if you're animating your mesh)
Link them to your Mesh
Create your index buffer
Create your SubMeshes and link them to the index buffer
Call Mesh::load()

Non-shared geometry:

Create your Mesh object
For each SubMesh:
Create the vertex declaration
Create your different vertex buffers (separate [position+normals] from the rest if you're animating your mesh)
Link them to your SubMesh
Create your index buffer
Link it to your SubMesh
Call Mesh::load()
*/