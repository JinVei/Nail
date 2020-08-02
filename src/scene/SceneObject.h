#pragma once
#include <map>
#include <string>

class SceneObject {
public:
    class Position {
        int x,y,z;
    };
    virtual ~SceneObject(){};
protected:
    std::string name;
    Position pos;
};