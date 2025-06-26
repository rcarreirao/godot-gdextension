#ifndef LEVELBASE_HPP
#define LEVELBASE_HPP

#include <node3d.hpp>
#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/resource_loader.hpp>
#include <godot_cpp/classes/gd_script.hpp>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/memory.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include "wall/WallDown.hpp"
#include "wall/WallUp.hpp"
#include <LuaState.hpp>
#include <LuaFunction.hpp>
#include <LuaScript.hpp>
#include <LuaScriptMethod.hpp>
#include <script-language/LuaScript.hpp>
#include <godot_cpp/classes/file_access.hpp>

using namespace luagdextension;
namespace godot {

    class LevelBase : public Node3D {
        GDCLASS(LevelBase, Node3D)

    private:
        WallDown *wallDown;
        WallUp *wallUp;
        String script_path = "res://my_script.gd";
        String file = "/var/www/html/godot-tests/godot-gd-game/demo/bouncing_logo.lua";
        Ref<GDScript> gdscript;
        Ref<luagdextension::LuaScript> luascript;
        luagdextension::LuaState *luastate;
        Object *instance = nullptr;
        int i;
        int g;
        void load_script();
        void load_lua_script();
        void reload_script();
        void unload_script();
        void call_method(String method_name, Array args);
        
    protected:
        static void _bind_methods();
        
    public:
        LevelBase();
        ~LevelBase();

        void _process(double delta) override;
        void _ready() override;
    };

}

#endif