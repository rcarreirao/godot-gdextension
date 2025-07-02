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
    luastate->open_libraries();
    //luastate->load_file(this->file);
    //Variant result = luastate->do_file("res://bouncing_logo.lua");
    //Variant result = luastate->do_string(FileAccess::get_file_as_string(this->file));
    //this->luascript = ResourceLoader::get_singleton()->load("res://bouncing_logo.lua");
    this->formatl = memnew(luagdextension::LuaScriptResourceFormatLoader());
    this->luascript = this->formatl->_load("res://bouncing_logo.lua","res://", true, 1);
    this->set_script(this->luascript);

    const LuaScriptMethod *method = this->luascript->get_metadata().methods.getptr("_rods");
    if(this->luascript->_has_method("_rods")){
        print_line("Tem method");
    }else{
        print_line("Não Tem method");
    }
    // //Variant result = resl->invoke_lua(method->method, Array::make("a"), false);
	// if (status == 1) {
    //     print_line("Lua ok;");
	// 	return ;
	// }
    UtilityFunctions::print(method->name);
    LuaCoroutine::invoke_lua(method->method, VariantArguments(), false);
    //Variant ret = instance2->call("_rods");
    //UtilityFunctions::print("Call result:", ret);
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
