#include "Node3DScript.hpp"

using namespace godot;

Node3DScript::Node3DScript() {}

Node3DScript::~Node3DScript() {}

void Node3DScript::_bind_methods() {}
void Node3DScript::load_script() {}
void Node3DScript::call_method(String method_name, Array args) {}

Node3DScript* Node3DScript::setScriptPath(String path){
    this->scriptPath = "res://" + path;
    return this;
}

Ref<GDScript> Node3DScript::get_script_object(){
    return this->scriptObject;
}
