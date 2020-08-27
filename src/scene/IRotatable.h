#pragma once
#include "common/vec.h"

namespace nail
{
    class IRotatable {
    public:
        virtual void rotate(float angle, Axis axis) = 0;
    };
} // namespace nail
