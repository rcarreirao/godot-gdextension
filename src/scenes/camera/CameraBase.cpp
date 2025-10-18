#include "CameraBase.hpp"
#include <cstdio>

using namespace godot;

void CameraBase::_bind_methods() {
    //ClassDB::bind_method(D_METHOD("_process"), &CameraBase::process);
}

CameraBase::CameraBase() {
	// Initialize any variables here.
    this->cameraHud = memnew(CameraHud());
    this->add_child(this->cameraHud);
    //print_line("Camera base initialized");
    this->state = StateMachine::IDLE;
    this->directionX = this->directionY = this->directionZ = 0;
    this->speed = 1;
    this->smooth = 4;
    this->set_current(true);
    this->set_as_top_level(true);
    this->make_current();

}

CameraBase::~CameraBase() {
	// Add your cleanup here.
}

void CameraBase::_process(double delta) {
    //print_line("Camera process");

	this->checkState(delta);
}

void CameraBase::_ready() {
    //print_line("Camera ready");
}

void CameraBase::checkState(double delta){
    //print_line("pressing");

    switch (this->state) {
        case StateMachine::IDLE:
            this->stateIdle(delta);
            break;
        case StateMachine::WALK:
            this->stateWalk(delta);
            break;
        }
}

void CameraBase::stateIdle(double delta) {
	if (this->directionX != 0 || this->directionY != 0 || this->directionZ != 0) {
		this->enterState(StateMachine::WALK);
	}

}

void CameraBase::stateWalk(double delta) {
	this->moveAndSlide(delta);
	if (this->directionX == 0 && this->directionY == 0 && this->directionZ == 0) {
		this->enterState(StateMachine::IDLE);
	}

	//text := fmt.Sprintf("%f", this->Super().AsNode3D().Position().X);
	//this->cameraHud.Container.GetLabelPosition().SetText(text);
}

void CameraBase::moveAndSlide(double delta) {
    Vector3 vector3 = this->get_position();
	vector3.x = godot::Math::lerp((float) (vector3.x), 
        (float) (vector3.x+(this->directionX * speed)), 
        (float) (this->smooth * delta));
    vector3.y = godot::Math::lerp((float) (vector3.y), 
        (float) (vector3.y+(this->directionY * speed )), 
        (float) (this->smooth * delta));
    vector3.z = godot::Math::lerp((float) (vector3.z), 
        (float) (vector3.z+(this->directionZ * speed)), 
        (float) (this->smooth * delta));
    this->cameraHud->updateCameraPosition(vector3);
	this->set_position(vector3);
}

void CameraBase::enterState(StateMachine newState) {
	if (this->state != newState) {
		this->state = newState;
		this->enter_state = true;
	}
}

void CameraBase::_input(const Ref<InputEvent> &p_event){
    //print_line("pressing");
    this->directionX = p_event->get_action_strength("ui_left") - p_event->get_action_strength("ui_right");
    this->directionY = p_event->get_action_strength("ui_up") - p_event->get_action_strength("ui_down");
    this->directionZ = p_event->get_action_strength("ui_page_down") - p_event->get_action_strength("ui_page_up");
}