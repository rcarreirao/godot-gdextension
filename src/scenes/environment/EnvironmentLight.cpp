#include "EnvironmentLight.hpp"

using namespace godot;

EnvironmentLight::EnvironmentLight() {}

EnvironmentLight::~EnvironmentLight() {}

void EnvironmentLight::_bind_methods() {
}
void EnvironmentLight::_process(double delta) {

}

void EnvironmentLight::_ready() {
    this->set_param(Light3D::Param::PARAM_ENERGY, 4.429);
    Transform3D new_transform;
    // Set origin (position)
    new_transform.origin = Vector3(0, 1, 1.315);
    // Set basis (rotation + scale). Identity for now
    new_transform.basis = Basis();
    // Apply the transform
    this->set_transform(new_transform);
    this->set_rotation(Vector3(-68, 0, 0));
}