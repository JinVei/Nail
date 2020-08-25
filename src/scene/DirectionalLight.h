#pragma
#include "common/vec.h"

#include "Light.h"

namespace nail {
    class DirectionalLight: public Light {
    private:
        vec3 _direction;
    public:
        DirectionalLight(wref<SceneManager> owner, vec3 direction): Light(owner) {
            _direction = glm::normalize(direction);;
        }

        vec3 getDirection() {
            return _direction;
        }
        void setDirection(glm::vec3 direction) {
            _direction = glm::normalize(direction);
        }
    };

}