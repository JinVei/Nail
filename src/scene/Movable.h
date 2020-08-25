#pragma once
#include "common/vec.h"

namespace nail
{
    class Movable {
    private:
        Position _pos;
    public:
        void setPosition(Position pos);
        Position getPosition();
        Position move(vec3 vec);
    };
} // namespace nail
