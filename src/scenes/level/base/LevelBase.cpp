#include "LevelBase.hpp"

LevelBase::LevelBase() { 
    this->i = 0;
    print_line("Level base initialized");

    this->wallDown = memnew(WallDown);
    this->add_child(this->wallDown);

    this->wallUp = memnew(WallUp);
    this->wallUp->set_name("wallUp");
    this->add_child(this->wallUp);
    this->levelGround = memnew(LevelGround);
    this->levelGround->set_name("levelGround");
    this->add_child(this->levelGround);
    this->load_gd_script();
}

LevelBase::~LevelBase() {}

void LevelBase::_bind_methods() {
}
void LevelBase::_process(double delta) {
    this->g = 0;
}

void LevelBase::process1() {
    this->g = 0;
}

void LevelBase::_ready() {
    
    //this->load_script();

    // Call a method from the Lua script
    this->script->call_method("rods", Array::make());
}

void LevelBase::load_lua_script(){
    // print_line("Initiating Engine Lua Script");

    // this->script = memnew(EngineLuaScript());    
    // this->script->setScriptPath("bouncing_logo.lua")->load_script();
    // this->add_child(this->script);

    // // Call a method from the Lua script
    // this->script->call_method("_rods", Array::make("Hello from LevelBase!"));
}

void LevelBase::load_gd_script(){
    print_line("Initiating Engine Gd Script");

    this->script = memnew(EngineGdScript);    
    this->script->setScriptPath("scripts/levels/level_base.gd")->load_script();
    this->set_script(this->script->get_script_object());
    if (this->has_method("rods"))
    {
        UtilityFunctions::print("MyNode: has function someFunction");
        this->call("rods");
    }
    else
    {
        UtilityFunctions::print("MyNode: does not have function someFunction");
    }
}

