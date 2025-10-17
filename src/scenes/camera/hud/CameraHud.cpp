#include "CameraHud.hpp"

using namespace godot;

void CameraHud::_bind_methods() {
}

CameraHud::CameraHud() {
    this->cameraContainer = memnew(CameraContainer());
    add_child(this->cameraContainer);
}

CameraHud::~CameraHud() {
	// Add your cleanup here.
}

void CameraHud::_process(double delta) {
}

void CameraHud::updateCameraPosition(Vector3 position){
    this->cameraContainer->updateCameraPosition(position);
}