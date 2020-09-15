#include "Movable.h"

using namespace nail;

void Movable::setPosition(Position pos) {
    _pos = pos;
}

Position Movable::getPosition() {
    return _pos;
}

void Movable::move(vec3 vec) {
    _pos += vec;
}