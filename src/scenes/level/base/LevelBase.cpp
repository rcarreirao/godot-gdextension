#include "LevelBase.hpp"

using namespace godot;

LevelBase::LevelBase() {}

LevelBase::~LevelBase() {}

void LevelBase::_bind_methods() {}
void LevelBase::_process(double delta) {

}

void LevelBase::_ready() {
    this->wallDown = memnew(WallDown());
    this->add_child(this->wallDown);

    this->wallUp = memnew(WallUp());
    this->add_child(this->wallUp);
}
