#pragma once
#include "common/vec.h"

namespace nail {
    class Directional {
    private:
        vec3 _direction;
    public:
        Directional(vec3 direction) {
            _direction = glm::normalize(direction);
        }
        vec3 getDirection() {
            return _direction;
        }
        void setDirection(glm::vec3 direction) {
            _direction = glm::normalize(direction);
        }
    };
    
}