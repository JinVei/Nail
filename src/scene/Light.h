#pragma once
#include <vector>
#include <glm/glm.hpp>
namespace nail {
    class Light {
    private:
        glm::vec3 _direction;
    public:
        Light(glm::vec3  dir) {
            _direction = dir;
        }
        
        glm::vec3 getDirection() {
            return _direction;
        }
        void setDirection(glm::vec3 dir) {
            _direction = glm::normalize(dir);
        }
    };
}