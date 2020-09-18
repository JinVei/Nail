#pragma once
#include "IMovable.h"

namespace nail
{
    class Movable: public IMovable {
    private:
        Position _pos;
    public:
        virtual ~Movable() = default;
        virtual void setPosition(Position pos) override;
        virtual Position getPosition() override;
        virtual void move(vec3 v) override;
    };
} // namespace nail
