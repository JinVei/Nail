#pragma once
#include <map>
#include <string>

class SceneObject {
public:
    class Position {
        int x,y,z;
    };
protected:
    std::string name;
    Position pos;
};