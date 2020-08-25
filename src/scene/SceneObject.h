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
    protected:
        std::string _name;
        std::weak_ptr<SceneManager> _owner;
    };
}