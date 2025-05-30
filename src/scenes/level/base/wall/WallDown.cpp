#include "WallDown.hpp"

using namespace godot;

WallDown::WallDown() {}

WallDown::~WallDown() {}

void WallDown::_bind_methods() {
}
void WallDown::_process(double delta) {

}

void WallDown::_ready() {
    this->setup();
}

void WallDown::setup(){
    this->boxMesh = memnew(BoxMesh());
    this->setBoxMeshSize(Vector3(9, 0.1, 4));
    this->set_rotation(Vector3(90, 0, 0));
    this->set_mesh(this->boxMesh);
    this->set_use_collision(true);
    this->set_visible(false);
}

void WallDown::setBoxMeshSize(Vector3 vector){
    this->boxMesh->set_size(vector);
}