#pragma once
#include <vector>
#include "SceneObject.h"
#include "common/vec.h"

namespace nail {
    enum class LightType {
        POINT_LIGHT,
        DIRECTIONAL_LIGHT,
        SPOTLIGHT,
    };
    class Light : public SceneObject {
    private:
        Color _color;
    public:
        Light(wref<SceneManager> owner): SceneObject(owner) {

        }

        Color getColor() {
            return _color;
        }
        void setColor(Color color) {
            _color = color;
        }
        // Light(glm::vec3  dir) {
        //     _direction = dir;
        // }
        

    };
}