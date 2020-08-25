#pragma once

namespace nail
{
    struct Position {
        int x,y,z;
    };
    class Movable {
    private:
        Position _pos;
    public:
        void setPosition(Position pos);
        Position getPosition();
    };
} // namespace nail
