#pragma once
#include <map>
#include <string>

class Value;

class SceneObject {
    size_t _id;
    std::map<std::string, Value> _attribute;
};