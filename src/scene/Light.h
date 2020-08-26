#pragma once
#include <vector>
#include "SceneObject.h"
#include "common/vec.h"

namespace nail {
    enum class LightType {
        POINT_LIGHT,
        DIRECTIONAL_LIGHT,
        SPOT_LIGHT,
        UNKNOW,
    };
    class Light : public SceneObject {
    private:
        Color _color;
    public:
        virtual ~Light(){}
        Light(wref<SceneManager> manager): SceneObject(manager) {

        }

        Color getColor() {
            return _color;
        }
        void setColor(Color color) {
            _color = color;
        }
        virtual LightType getLightType() = 0;
    };
}