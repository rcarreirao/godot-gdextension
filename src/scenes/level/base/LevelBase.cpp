#include "LevelBase.hpp"

using namespace godot;

LevelBase::LevelBase() { this->i = 0;}

LevelBase::~LevelBase() {}

void LevelBase::_bind_methods() {}
void LevelBase::_process(double delta) {

}

void LevelBase::_ready() {
    print_line("Level base initialized");

    this->wallDown = memnew(WallDown());
    this->add_child(this->wallDown);

    this->wallUp = memnew(WallUp());
    this->add_child(this->wallUp);
    this->load_script();
}

void LevelBase::load_script(){
    print_line("Call Gdscript method initialized");

    Ref<Resource> res = ResourceLoader::get_singleton()->load("res://my_script.gd");

    if (res.is_null()) {
        UtilityFunctions::print("Failed to load script.");
        return;
    }

    this->gdscript = res;
    if (gdscript.is_null()) {
        UtilityFunctions::print("Script is not a GDScript.");
        return;
    }

    // GDScript::new_() returns a Variant
    Variant instance_var = this->gdscript->new_();
    this->instance = Object::cast_to<Object>(instance_var.operator Object *());

    if (!this->instance) {
        UtilityFunctions::print("Failed to instantiate GDScript.");
        return;
    }
    
    if(this->i < 2){
        this->i++;
        this->call_method("my_method", Array::make(42));
    }
    
}

void LevelBase::reload_script() {
    unload_script();
    load_script();
}

void LevelBase::unload_script() {
    UtilityFunctions::print("Unloading script.");
    this->instance = nullptr;
    this->gdscript.unref();
}


void LevelBase::call_method(String method_name, Array args = Array()){
    if(!this->instance){
        UtilityFunctions::print("No script instance loaded.");
        return;
    }
    Variant ret = this->instance->call(method_name, args);
    UtilityFunctions::print("Call result:", ret);
    this->reload_script();
}
