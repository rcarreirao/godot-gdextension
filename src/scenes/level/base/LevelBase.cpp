#include "LevelBase.hpp"

LevelBase::LevelBase() { this->i = 0;}

LevelBase::~LevelBase() {}

void LevelBase::_bind_methods() {}
void LevelBase::_process(double delta) {
    this->g = 0;
}

void LevelBase::_ready() {
    print_line("Level base initialized");

    this->wallDown = memnew(WallDown());
    this->add_child(this->wallDown);

    this->wallUp = memnew(WallUp());
    this->add_child(this->wallUp);
    //this->load_script();
    this->load_lua_script();
}

void LevelBase::load_lua_script(){
    print_line("Call Load Lua script4");

    this->luastate = memnew(luagdextension::LuaState());
    luastate->load_file(this->file);
    int64_t size = this->file.length();
    this->luascript = LuaScriptLanguage::get_singleton()->_create_script();
	this->luascript->set_path(this->file);
	this->luascript->set_source_code(FileAccess::get_file_as_string(this->file));
    this->luascript->validate("bouncing_logo.lua", "/var/www/html/godot-tests/godot-gd-game/demo");
	Error status = this->luascript->reload();

    const LuaScriptMethod *method = this->luascript->get_metadata().methods.getptr("ready");
    if(this->luascript->_has_method("ready")){
        print_line("Tem method");
    }else{
        print_line("Não Tem method");
    }
    //Variant result = resl->invoke_lua(method->method, Array::make("a"), false);
	if (status == 1) {
        print_line("Lua ok;");
		return ;
	}
	print_line("Lua script not ok;");
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
