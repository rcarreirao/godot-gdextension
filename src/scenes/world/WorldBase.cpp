#include "WorldBase.hpp"

using namespace godot;

WorldBase::WorldBase() {
    //this->loadScript();
}

WorldBase::~WorldBase() {
}

void WorldBase::_bind_methods() {
}
void WorldBase::_process(double delta) {

}

void WorldBase::_ready() {
    
    // this->cameraBase = memnew(CameraBase());
    // this->levelBase = memnew(LevelBase());
    // this->gdExample = memnew(GDExample());
    // this->gdExample3D = memnew(GDExample3D());
    // this->environmentLight = memnew(EnvironmentLight());
    // this->cameraBase->add_child(this->gdExample);
    // // this->add_child(this->gdExample3D);
    // this->add_child(this->cameraBase);
    // // this->add_child(this->levelBase);
    // // this->add_child(this->environmentLight);
    // this->cameraBase->set_current(true);
}

void WorldBase::loadScriptLua(){
    this->script = memnew(EngineLuaScript);    
    this->script->setScriptPath(this->scriptPath);
    this->script->load_script();
    this->add_child(this->script);
}

void WorldBase::loadScript(){
    this->script = memnew(EngineGdScript);    
    this->script->setScriptPath(this->scriptPathGd);
    this->script->load_script();
    this->set_script(this->script->get_script_object());
    this->add_child(this->script);
}