#include "WallUp.hpp"

using namespace godot;

WallUp::WallUp() {
    this->set_name("wallUp");
    this->setup();
}

WallUp::~WallUp() {}

void WallUp::_bind_methods() {
}
void WallUp::_process(double delta) {

}

void WallUp::_ready() {
}

void WallUp::setup(){
    this->wallUpBackground = memnew(WallUpBackground());
    this->wallUpBackground->set_name("wallUpBackground");
    this->add_child(wallUpBackground);
}
