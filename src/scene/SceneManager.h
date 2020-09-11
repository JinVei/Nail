#pragma once
#include "Entity.h"
#include "SceneObjectFactory.h"
#include "SceneObjectType.h"
#include "Light.h"
#include "SceneNode.h"
#include "Camera.h"
#include "common/GUID.h"
#include "IRenderable.h"
#include "PointLight.h"

#include <map>
#include <list>

namespace nail {
    class SceneManager {
    public:
        using SceneObjectFactoryTable = std::map<SceneObjectType, ref<SceneObjectFactory>>;
    private:
        ref<SceneNode> _root;
        SceneObjectFactoryTable _scene_object_factotys;
        std::list<ref<Light>> _lights;
        std::map<GUID, ref<Camera>> _cameras;
        wref<SceneManager> _self;
    public:
        SceneManager();
        virtual ~SceneManager();
        void setSelf(wref<SceneManager>);
        void addSceneObjectFactoty(SceneObjectType type, ref<SceneObjectFactory> factory);
        ref<EntityNode> createEntity(std::string entity_name, std::string resource_path);
        ref<SceneObjectFactory> getSceneObjectFactoty(SceneObjectType type);
        ref<SceneNode> createSceneNode();
        ref<SceneNode> createSceneNode(ref<SceneObject> scene_obj);

        ref<Light> getLight(GUID);
        std::list<ref<Light>> getLights();
        //ref<Light> createLight();
        void deleteLight(GUID);
        ref<PointLight> createPointLight(vec3 position, Color color);


        ref<Camera> getCamera(GUID);
        //ref<Camera> createCamera();
        ref<Camera> createCamera(vec3 direction, float fovy, float near, float far);
        void deleteCamera(GUID);


        std::vector<ref<IRenderable>> getAllRenderableSceneObjects();

        ref<SceneNode> getRootNode();

        virtual void render();
    };
}