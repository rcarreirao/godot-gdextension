#ifndef LEVELBASE_HPP
#define LEVELBASE_HPP

#include <node3d.hpp>
#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/resource_loader.hpp>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/memory.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include "wall/WallDown.hpp"
#include "wall/WallUp.hpp"
#include "../../../objects/node/Node3DScript.hpp"
#include "../../../objects/script/EngineLuaScript.hpp"
#include "../../../objects/script/EngineGdScript.hpp"

#include <godot_cpp/classes/file_access.hpp>
#include "../utils/VariantArguments.hpp"

using namespace luagdextension;
namespace godot {

    class LevelBase : public Node3D {
        GDCLASS(LevelBase, Node3D)

    private:
        WallDown *wallDown;
        WallUp *wallUp;
        String script_path = "res://my_script.gd";
        String file = "/var/www/html/godot-tests/godot-gd-game/demo/bouncing_logo.lua";
        int i;
        int g;
        Node3DScript *script;
        
    protected:
        static void _bind_methods();
        void load_lua_script();
        
    public:
        LevelBase();
        ~LevelBase();

        void _process(double delta) override;
        void _ready() override;
    };

}

#endif