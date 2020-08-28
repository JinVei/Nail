#pragma once
#include "Pass.h"
#include <vector>
namespace nail {
    class Material {
    public:
        virtual ~Material(){}
        virtual void addPass(ref<Pass>) = 0;
        virtual std::vector<ref<Pass>> getPasses() = 0;
    };
}
