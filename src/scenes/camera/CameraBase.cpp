#include "CameraBase.hpp"
#include <cstdio>

using namespace godot;

void CameraBase::_bind_methods() {
    //ClassDB::bind_method(D_METHOD("_process"), &CameraBase::process);
    ClassDB::bind_method(D_METHOD("checkState"), &CameraBase::checkState);
    ClassDB::bind_method(D_METHOD("updateCameraPosition"), &CameraBase::updateCameraPosition);
    ClassDB::bind_method(D_METHOD("setPosition"), &CameraBase::setPosition);
}

CameraBase::CameraBase() {
	// Initialize any variables here.
    this->cameraHud = memnew(CameraHud());
    this->add_child(this->cameraHud);
    //print_line("Camera base initialized");
    this->state = StateMachine::IDLE;
    this->directionX = this->directionY = this->directionZ = 0;
    this->rotation.x = this->rotation.y = this->rotation.z =0;
    // this->position.x = 0 ; this->position.y = 1.346; this->position.z = 2.568;
    this->speed = 1;
    this->smooth = 4;
    this->set_current(true);
    this->set_as_top_level(true);
    this->make_current();
    // this->set_rotation(this->rotation);
    this->set_position(this->position);
    //this->loadScript();

}

CameraBase::~CameraBase() {
	// Add your cleanup here.
}

void CameraBase::_process(double delta) {
    //print_line("Camera process");

	this->checkState(delta);
}

void CameraBase::_ready() {
    print_line("Camera ready c++");
    this->setup();
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
    this->updateCameraPosition();
	if (this->directionX == 0 && this->directionY == 0 && this->directionZ == 0) {
		this->enterState(StateMachine::IDLE);
	}

	//text := fmt.Sprintf("%f", this->Super().AsNode3D().Position().X);
	//this->cameraHud.Container.GetLabelPosition().SetText(text);
}

void CameraBase::moveAndSlide(double delta) {
    this->position = this->get_position();
	this->position.x = godot::Math::lerp((float) (this->position.x), 
        (float) (this->position.x+(this->directionX * speed)), 
        (float) (this->smooth * delta));
    this->position.y = godot::Math::lerp((float) (this->position.y), 
        (float) (this->position.y+(this->directionY * speed )), 
        (float) (this->smooth * delta));
    this->position.z = godot::Math::lerp((float) (this->position.z), 
        (float) (this->position.z+(this->directionZ * speed)), 
        (float) (this->smooth * delta));
}

void CameraBase::updateCameraPosition(){
    this->cameraHud->updateCameraPosition(this->position);
	this->set_position(this->position);
}

void CameraBase::enterState(StateMachine newState) {
	if (this->state != newState) {
		this->state = newState;
		this->enter_state = true;
	}
}

void CameraBase::setPosition(Vector3 newPosition){
	this->position = newPosition;
    this->set_position(this->position);
}

void CameraBase::_input(const Ref<InputEvent> &p_event){
    //print_line("pressing");
    this->directionX = p_event->get_action_strength("ui_left") - p_event->get_action_strength("ui_right");
    this->directionY = p_event->get_action_strength("ui_up") - p_event->get_action_strength("ui_down");
    this->directionZ = p_event->get_action_strength("ui_page_down") - p_event->get_action_strength("ui_page_up");
}

CameraBase* CameraBase::setup(){
    this->loadScript();
    return this;
}

void CameraBase::loadScript(){
    this->script = memnew(EngineGdScript);    
    this->script->setScriptPath(this->scriptPath);
    this->script->load_script();
    this->set_script(this->script->get_script_object());
    if(this->has_method("teste")){
        this->script->call_method("_ready", Array());
        this->script->call_method("teste", Array());
    }
}