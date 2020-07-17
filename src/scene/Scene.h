#pragma once
#include <list>

namespace nail {

class SceneData;
class SceneObject;

class Scene {
    Tree<SceneObject> _render_tree;
    std::list<SceneObject> _scene_light;
    std::map<std::string, Value> _attribute;
};

} // nail