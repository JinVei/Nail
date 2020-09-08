#pragma once
#include "common/vec.h"
#include "Light.h"
#include "Directional.h"

namespace nail {
    class DirectionalLight: public Light, public Directional {
    public:
        DirectionalLight(wref<SceneManager> manager, vec3 direction): Light(manager),Directional(direction) {
        }
        virtual LightType getLightType() override{
            return LightType::DIRECTIONAL_LIGHT;
        }
    };

}