#include "movable.h"

using namespace nail;

void Movable::setPosition(Position pos) {
    _pos = pos;
}

auto Movable::getPosition() -> Position {
    return _pos;
}