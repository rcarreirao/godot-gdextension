#include "EngineGdScript.hpp"

EngineGdScript::EngineGdScript() {this->i = 0;}

EngineGdScript::~EngineGdScript() {}

void EngineGdScript::_bind_methods() {}

void EngineGdScript::load_script() {
    print_line("Call Gdscript method initialized from EngineGd");

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
    this->instanceGdScript = Object::cast_to<Object>(instance_var.operator Object *());

    if (!this->instanceGdScript) {
        UtilityFunctions::print("Failed to instantiate GDScript.");
        return;
    }
    
    if(this->i < 2){
        this->i++;
        this->call_method("my_method", Array::make(42));
    }
    
}

void EngineGdScript::reload_script() {
    unload_script();
    load_script();
}

void EngineGdScript::unload_script() {
    UtilityFunctions::print("Unloading script.");
    this->instanceGdScript = nullptr;
    this->gdscript.unref();
}


void EngineGdScript::call_method(String method_name, Array args = Array()){
    if(!this->instanceGdScript){
        UtilityFunctions::print("No script instance loaded.");
        return;
    }
    Variant ret = this->instanceGdScript->call(method_name, args);
    UtilityFunctions::print("Call result:", ret);
    this->reload_script();
}