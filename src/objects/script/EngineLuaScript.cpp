#include "EngineLuaScript.hpp"

using namespace godot;

EngineLuaScript::EngineLuaScript() {}

EngineLuaScript::~EngineLuaScript() {
    if(this->luascript != nullptr){
        memdelete(this->luastate);
        memdelete(this->formatl);
    }
    
}

void EngineLuaScript::_bind_methods() {}

void EngineLuaScript::call_method(String method_name, Array args = Array()){
    
}

void EngineLuaScript::load_script(){
    print_line("Call Load Lua script from EngineLua1");
    this->luastate = memnew(luagdextension::LuaState());
    luastate->open_libraries();
    //luastate->load_file(this->file);
    //Variant result = luastate->do_file("res://bouncing_logo.lua");
    //Variant result = luastate->do_string(FileAccess::get_file_as_string(this->file));
    //this->luascript = ResourceLoader::get_singleton()->load("res://bouncing_logo.lua");
    this->formatl = memnew(luagdextension::LuaScriptResourceFormatLoader());
    print_line(this->scriptPath);

    this->luascript = this->formatl->_load(this->scriptPath,"res://", true, 1);
    this->set_script(this->luascript);
}
void EngineLuaScript::load_script_old() {
    print_line("Call Load Lua script from EngineLua");

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
    //Variant ret = instanceLuaScript->call("_rods");
    //UtilityFunctions::print("Call result:", ret);
	print_line("Lua script not ok;");
}
