#pragma once
#include "common/ref.h"

#include <map>
#include <string>
#include "SceneManager.h"
#include <memory>
namespace nail {
    class SceneObject {
    public:
        struct Position {
            int x,y,z;
        };
        virtual ~SceneObject(){};
        SceneObject(std::weak_ptr<SceneManager> owner);

        std::weak_ptr<SceneManager> getManager();
        void setName(std::string name);
        ConstString getName();
        void setPosition(Position pos);
        Position getPosition();
    protected:
        std::string _name;
        Position _pos;
        std::weak_ptr<SceneManager> _owner;
    };
}