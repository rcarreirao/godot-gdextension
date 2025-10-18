#include "LevelBase.hpp"

LevelBase::LevelBase() { this->i = 0;}

LevelBase::~LevelBase() {}

void LevelBase::_bind_methods() {}
void LevelBase::_process(double delta) {
    this->g = 0;
}

void LevelBase::_ready() {
    print_line("Level base initialized");

    this->wallDown = memnew(WallDown);
    this->add_child(this->wallDown);

    this->wallUp = memnew(WallUp);
    this->add_child(this->wallUp);
    this->levelGround = memnew(LevelGround);
    this->add_child(this->levelGround);
    //this->load_script();
    this->load_lua_script();
}

void LevelBase::load_lua_script(){
    print_line("Initiating Engine Gd Script");

    this->script = memnew(EngineLuaScript());    
    this->script->setScriptPath("bouncing_logo.lua")->load_script();
    this->add_child(this->script);

    // Call a method from the Lua script
    this->script->call_method("_rods", Array::make("Hello from LevelBase!"));
}

