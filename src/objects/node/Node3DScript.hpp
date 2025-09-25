#ifndef NODE3DSCRIPT_HPP
#define NODE3DSCRIPT_HPP

#include <node3d.hpp>
#include <LuaState.hpp>
#include <LuaFunction.hpp>
#include <LuaScript.hpp>
#include <LuaScriptMethod.hpp>
#include <LuaCoroutine.hpp>
#include <LuaScriptResourceFormatLoader.hpp>
#include <script-language/LuaScript.hpp>
#include <godot_cpp/classes/gd_script.hpp>

namespace godot {

    class Node3DScript : public Node3D {
        GDCLASS(Node3DScript, Node3D)

    private:
        Ref<GDScript> gdscript;
        Object *instanceGdScript = nullptr;
        // Lua
        luagdextension::LuaState *luastate;
        luagdextension::LuaScriptResourceFormatLoader *formatl;
        Ref<luagdextension::LuaScript> luascript;
        Object *instanceLuaScript = nullptr;
    protected: 
        String scriptPath;
        
    protected:
        void reload_script();
        void unload_script();
        static void _bind_methods();

    public:
        virtual void load_script();
        void call_method(String method_name, Array args);
        Node3DScript* setScriptPath(String path);
        Node3DScript();
        ~Node3DScript();
    };

}

#endif
