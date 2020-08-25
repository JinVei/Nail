#pragma once
#include <vector>
#include <glm/glm.hpp>
#include "SceneObject.h"

namespace nail {
    class Light : public SceneObject {
    private:
        glm::vec3 _direction;
    public:
        Light(std::weak_ptr<SceneManager> owner): SceneObject(owner) {

        }
        // Light(glm::vec3  dir) {
        //     _direction = dir;
        // }
        
        glm::vec3 getDirection() {
            return _direction;
        }
        void setDirection(glm::vec3 dir) {
            _direction = glm::normalize(dir);
        }
    };
}