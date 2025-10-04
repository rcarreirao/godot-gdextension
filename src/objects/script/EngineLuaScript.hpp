#ifndef ENGINELUASCRIPT_HPP
#define ENGINELUASCRIPT_HPP

#include <node3d.hpp>
#include <LuaState.hpp>
#include <LuaFunction.hpp>
#include <LuaScript.hpp>
#include <LuaScriptMethod.hpp>
#include <LuaCoroutine.hpp>
#include <LuaScriptResourceFormatLoader.hpp>
#include <script-language/LuaScript.hpp>
#include "../node/Node3DScript.hpp"
#include <godot_cpp/classes/gd_script.hpp>
#include "../utils/VariantArguments.hpp"
#include <godot_cpp/classes/resource_loader.hpp>


using namespace luagdextension;

namespace godot {

    class EngineLuaScript :  public Node3DScript {
        GDCLASS(EngineLuaScript, Node3DScript)

    private:
        luagdextension::LuaState *luastate;
        luagdextension::LuaScriptResourceFormatLoader *formatl;
        Ref<luagdextension::LuaScript> luascript;
        Object *instanceLuaScript = nullptr;


    protected:
        void reload_script();
        void unload_script();
        static void _bind_methods();

    public:
        void load_script();
        void load_script_old();
        void call_method(String method_name, Array args);
        EngineLuaScript();
        ~EngineLuaScript();

    };

}

#endif
