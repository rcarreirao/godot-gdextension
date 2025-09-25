#include "WorldBase.hpp"

using namespace godot;

WorldBase::WorldBase() {}

WorldBase::~WorldBase() {
    memdelete(this->script);
}

void WorldBase::_bind_methods() {
}
void WorldBase::_process(double delta) {

}

void WorldBase::_ready() {
    this->loadScript();
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

void WorldBase::loadScript(){
    this->script = memnew(EngineLuaScript());    
    this->script->setScriptPath(this->scriptPath);
    this->script->load_script();
    this->add_child(this->script);
}
