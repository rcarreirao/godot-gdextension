#include "gdexample.h"
#include "register_types.h"


using namespace godot;
using namespace luagdextension;

void initialize_example_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
	GDREGISTER_RUNTIME_CLASS(GDExample);
	GDREGISTER_RUNTIME_CLASS(GDExample3D);
	GDREGISTER_RUNTIME_CLASS(WorldBase);
	GDREGISTER_RUNTIME_CLASS(CameraBase);
	GDREGISTER_RUNTIME_CLASS(LevelBase);
	GDREGISTER_RUNTIME_CLASS(WallDown);
	GDREGISTER_RUNTIME_CLASS(WallUp);
	GDREGISTER_RUNTIME_CLASS(WallUpBackground);
	GDREGISTER_RUNTIME_CLASS(EnvironmentLight);
	GDREGISTER_RUNTIME_CLASS(Node3DScript);
	GDREGISTER_RUNTIME_CLASS(EngineLuaScript);
	GDREGISTER_RUNTIME_CLASS(EngineGdScript);
    initialize_lua_module(p_level);
}

void uninitialize_example_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
}

void initialize_lua_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}

	// Lua object wrappers
	ClassDB::register_abstract_class<LuaObject>();

	ClassDB::register_abstract_class<LuaCoroutine>();
	ClassDB::register_abstract_class<LuaFunction>();
	ClassDB::register_abstract_class<LuaLightUserdata>();
	ClassDB::register_abstract_class<LuaTable>();
	ClassDB::register_abstract_class<LuaUserdata>(); 

	// Godot classes for interacting with Lua States
	ClassDB::register_class<LuaError>();
	ClassDB::register_class<LuaState>();

	// Lua Script Language
	ClassDB::register_abstract_class<LuaScript>();
	ClassDB::register_abstract_class<LuaScriptLanguage>();
	ClassDB::register_abstract_class<LuaScriptResourceFormatLoader>();
	ClassDB::register_abstract_class<LuaScriptResourceFormatSaver>();
	LuaScriptLanguage::get_or_create_singleton();
	LuaScriptResourceFormatLoader::register_in_godot();
	LuaScriptResourceFormatSaver::register_in_godot();

	// Lua code editing
	ClassDB::register_class<LuaCodeEdit>();
	ClassDB::register_class<LuaSyntaxHighlighter>();
}


extern "C" {
    // Initialization.
    GDExtensionBool GDE_EXPORT godot_gd_game_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, const GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization) {
        godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);
        init_obj.register_initializer(initialize_example_module);
        init_obj.register_terminator(uninitialize_example_module);
        //init_obj.register_initializer(initialize_lua_module);
        //init_obj.register_terminator(deinitialize_lua_module);
        init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

        return init_obj.init();
    }
}