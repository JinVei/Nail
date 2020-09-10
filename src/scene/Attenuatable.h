#pragma once

namespace nail {
    class Attenuatable {
    protected:
        float _constant = 1;
        float _linear = 0.07;
        float _quadratic = 0.017;
    public:
        float getConstant() {
            return _constant;
        }
        float getLinear() {
            return _linear;
        }
        float getQuadratic() {
            return _quadratic;
        }
        void setConstant(float constant) {
            _constant = constant;
        }
        void setLinear(float linear) {
            _linear = linear;
        }
        void setQuadratic(float quadratic) {
            _quadratic = quadratic;
        }
    };
}