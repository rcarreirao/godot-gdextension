#include "gdexample.h"
#include "register_types.h"
#include "gdexample3d.h"
#include <gdextension_interface.h>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

using namespace godot;

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
}

void uninitialize_example_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
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