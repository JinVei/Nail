#pragma once 
#include "Light.h"
#include "Movable.h"
#include "Attenuatable.h"
namespace nail {
    class PointLight: public Light, public Movable, public Attenuatable {
    private:
        float _constant_factor;
        float _linear_factor;
        float _quadratic_factor;
    public:
        PointLight(wref<SceneManager> manager): Light(manager) {};
        void setConstantFactor(float factor) {
            _constant_factor = factor;
        }
        void setLinearFactor(float factor) {
            _linear_factor = factor;
        }
        void setQuadraticFactor(float factor) {
            _quadratic_factor = factor;
        }
        virtual LightType getLightType() override{
            return LightType::POINT_LIGHT;
        }
    };
}