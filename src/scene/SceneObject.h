#pragma once
#include "common/ref.h"

#include <map>
#include <string>
#include "SceneManager.h"
#include <memory>
namespace nail {
    class SceneObject {
    public:
        virtual ~SceneObject(){};
        SceneObject(std::weak_ptr<SceneManager> owner);

        std::weak_ptr<SceneManager> getManager();
        void setName(std::string name);
        ConstString getName();
        GUID getGUID();
    private:
        std::string _name;
        GUID _id;
        std::weak_ptr<SceneManager> _owner;
    };
}