#include "WallUp.hpp"

using namespace godot;

WallUp::WallUp() {}

WallUp::~WallUp() {}

void WallUp::_bind_methods() {
}
void WallUp::_process(double delta) {

}

void WallUp::_ready() {
    this->setup();
}

void WallUp::setup(){
    this->wallUpBackground = memnew(WallUpBackground());
    this->add_child(wallUpBackground);
}
