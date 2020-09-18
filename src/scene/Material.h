#pragma once
#include "IMaterial.h"

namespace nail {
    class Material : public IMaterial {
    private:
        std::vector<ref<Pass>> _pass_unit;

    public:
        void addPass(ref<Pass> pass) override {
            _pass_unit.push_back(pass);
        }

        std::vector<ref<Pass>> getPasses() override {
            return _pass_unit;
        }
    };
}