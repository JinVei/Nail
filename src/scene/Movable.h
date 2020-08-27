#pragma once
#include "IMovable.h"

namespace nail
{
    class Movable: public IMovable {
    private:
        Position _pos;
    public:
        virtual void setPosition(Position pos) override;
        virtual Position getPosition() override;
        virtual Position move(vec3 vec) override;
    };
} // namespace nail
