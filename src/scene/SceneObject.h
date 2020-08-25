#pragma once
#include "common/ref.h"
#include "common/GUID.h"

#include <map>
#include <string>
#include <memory>
namespace nail {
    class SceneManager;
    class SceneObject {
    public:
        virtual ~SceneObject(){};
        SceneObject(wref<SceneManager> owner);

        wref<SceneManager> getManager();
        void setName(std::string name);
        ConstString getName();
        GUID getGUID();
    private:
        std::string _name;
        GUID _id;
        wref<SceneManager> _owner;
    };
}