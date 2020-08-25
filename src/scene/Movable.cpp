#include "Movable.h"

using namespace nail;

void Movable::setPosition(Position pos) {
    _pos = pos;
}

Position Movable::getPosition() {
    return _pos;
}

Position Movable::move(vec3 vec) {
    _pos += vec;
    return _pos;
}