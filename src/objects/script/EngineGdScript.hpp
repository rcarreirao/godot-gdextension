#ifndef ENGINEGDSCRIPT_HPP
#define ENGINEGDSCRIPT_HPP

#include "../node/Node3DScript.hpp"
#include <node3d.hpp>
#include <script-language/LuaScript.hpp>
#include <godot_cpp/classes/gd_script.hpp>
#include <godot_cpp/classes/resource_loader.hpp>


namespace godot {

    class EngineGdScript : public Node3DScript {
        GDCLASS(EngineGdScript, Node3DScript)

    private:
        Object *instanceGdScript = nullptr;

        int i;
        int g;

    protected:
        void reload_script();
        void unload_script();
        static void _bind_methods();

    public:
        void load_script();
        void call_method(String method_name, Array args);
        EngineGdScript();
        ~EngineGdScript();

    };

}

#endif