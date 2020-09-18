#pragma once
#include "common/vec.h"

namespace nail
{
    class IScalable {
    public:
        virtual void scale(vec3 v) = 0;
    };
}