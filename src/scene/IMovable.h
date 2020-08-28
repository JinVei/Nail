#pragma once
#include "common/vec.h"

namespace nail
{
    class IMovable {
    public:
        virtual ~IMovable() {};
        virtual void setPosition(Position pos) = 0;
        virtual Position getPosition() = 0;
        virtual Position move(vec3 vec) = 0;
    };
} // namespace nail
