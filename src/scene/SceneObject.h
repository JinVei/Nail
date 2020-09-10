#pragma once
#include "common/ref.h"
#include "common/GUID.h"

#include <map>
#include <string>
#include <memory>
#include "SceneObjectType.h"
namespace nail {
    class SceneManager;
    class SceneObject {
    public:
        virtual ~SceneObject(){};
        SceneObject(wref<SceneManager> manager, SceneObjectType type);

        wref<SceneManager> getManager();
        void setName(std::string name);
        ConstString getName();
        GUID getGUID();
        SceneObjectType getType();
    private:
        std::string _name;
        GUID _id;
        wref<SceneManager> _manager;
        SceneObjectType _type;
    };
}