#pragma once
#include "common/vec.h"

namespace nail
{
    class IRotatable {
    public:
        virtual ~IRotatable(){}
        virtual void rotate(float angle, Axis axis) = 0;
    };
} // namespace nail
