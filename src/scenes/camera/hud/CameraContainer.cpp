#include "CameraContainer.hpp"

using namespace godot;

void CameraContainer::_bind_methods() {
}

CameraContainer::CameraContainer() {
    this->initializePositionLabels();
}

void CameraContainer::initializePositionLabels() {
    this->labelPosition = memnew(Label);
    this->labelPosition->set_text("Camera Position:");
	this->labelPosition->set_position(Vector2(10, 10));
    this->labelPositionX = memnew(Label);
    this->add_child(this->labelPosition);
    this->labelPositionX->set_text("X: 0");
    this->labelPositionX->set_position(Vector2(10, 30));
    this->add_child(this->labelPositionX);
    this->labelPositionY = memnew(Label);
    this->labelPositionY->set_text("Y: 0");
    this->labelPositionY->set_position(Vector2(10, 50));
    this->add_child(this->labelPositionY);
    this->labelPositionZ = memnew(Label);
    this->labelPositionZ->set_text("Z: 0");
    this->labelPositionZ->set_position(Vector2(10, 70));
    this->add_child(this->labelPositionZ);
}

CameraContainer::~CameraContainer() {
	// Add your cleanup here.
}

void CameraContainer::_process(double delta) {

}

void CameraContainer::_ready() {
    //fprintf("CameraContainer ready");
}

bool CameraContainer::unreference(){
    return true;
}

void CameraContainer::updateCameraPosition(Vector3 position){
    this->labelPositionX->set_text(godot::String::num(position.x));
    this->labelPositionY->set_text(godot::String::num(position.y));
    this->labelPositionZ->set_text(godot::String::num(position.z));
}