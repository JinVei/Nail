#pragma once 
#include "Light.h"
#include "Movable.h"

namespace nail {
    class PointLight: public Light, Movable{
    private:
        float _constant_factor;
        float _linear_factor;
        float _quadratic_factor;
    public:
        PointLight(wref<SceneManager> owner): Light(owner) {};
        void setConstantFactor(float factor) {
            _constant_factor = factor;
        }
        void setLinearFactor(float factor) {
            _linear_factor = factor;
        }
        void setQuadraticFactor(float factor) {
            _quadratic_factor = factor;
        }
    };
}