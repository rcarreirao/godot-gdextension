#include "CameraContainer.hpp"

using namespace godot;

void CameraContainer::_bind_methods() {
}

CameraContainer::CameraContainer() {
    print_line("Camera Container?");
    this->labelPosition = memnew(Label);
    this->labelPosition->set_text("Teste de Label");
	this->labelPosition->set_position(Vector2(10, 10));
    this->add_child(this->labelPosition);
}

CameraContainer::~CameraContainer() {
	// Add your cleanup here.
}

void CameraContainer::_process(double delta) {

}

void CameraContainer::_ready() {
    //fprintf("CameraContainer ready");
    print_line("Camera Container?");
}

bool CameraContainer::unreference(){
    return true;
}

void CameraContainer::updateLabel(godot::String text){
    this->labelPosition->set_text(text);
}