#pragma once
#include <list>

namespace nail {

class SceneData;
class SceneObject;

class Scene {
    Tree<SceneObject> _scene_node;
    std::list<SceneObject> _scene_light;
};

} // nail