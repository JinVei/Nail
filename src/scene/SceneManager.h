#pragma once
#include "Entity.h"
#include "SceneObjectFactory.h"
#include "SceneObjectType.h"
#include "Context.h"
#include "Light.h"
#include "SceneNode.h"

#include <map>

namespace nail {
    class SceneManager {
        friend class  nail::Context;
    public:
        using SceneObjectFactoryTable = std::map<SceneObjectType, ref<SceneObjectFactory>>;
    private:
        ref<SceneNode> _root;
        SceneObjectFactoryTable _scene_object_factotys;
        static ref<SceneManager> _singleton;
        std::vector<ref<Light>> _lights;
        
        SceneManager();
        void addSceneObjectFactoty(SceneObjectType type, ref<SceneObjectFactory> factory);
        static void set(ref<SceneManager>);

    public:
        static ref<SceneManager> singleton();
        ref<Entity> createEntity(std::string entity_name, std::string resource_path);
        ref<SceneObjectFactory> getSceneObjectFactoty(SceneObjectType type);
        //ref<Light> createLight();
        //ref<Camera> createCamera();
        ref<SceneNode> createSceneNode();
    };
}