#ifndef GDEXAMPLE_REGISTER_TYPES_H
#define GDEXAMPLE_REGISTER_TYPES_H

#include <godot_cpp/core/class_db.hpp>
#include "scenes/world/WorldBase.hpp"
#include "gdexample3d.h"
#include <gdextension_interface.h>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>
#include <LuaObject.hpp>
#include <LuaCoroutine.hpp>
#include <LuaError.hpp>
#include <LuaFunction.hpp>
#include <LuaLightUserdata.hpp>
#include <LuaObject.hpp>
#include <LuaState.hpp>
#include <LuaTable.hpp>
#include <LuaUserdata.hpp>
#include <script-language/LuaCodeEdit.hpp>
#include <script-language/LuaScript.hpp>
#include <script-language/LuaScriptLanguage.hpp>
#include <script-language/LuaScriptResourceFormatLoader.hpp>
#include <script-language/LuaScriptResourceFormatSaver.hpp>
#include <script-language/LuaSyntaxHighlighter.hpp>

using namespace godot;

void initialize_example_module(ModuleInitializationLevel p_level);
void uninitialize_example_module(ModuleInitializationLevel p_level);
void initialize_lua_module(ModuleInitializationLevel p_level);


#endif // GDEXAMPLE_REGISTER_TYPES_H
