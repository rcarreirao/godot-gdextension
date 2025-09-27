#!/usr/bin/env python
import os
import sys

env = SConscript("lib/godot-cpp/SConstruct")
opts = Variables([], ARGUMENTS)

# For reference:
# - CCFLAGS are compilation flags shared between C and C++
# - CFLAGS are for C-specific compilation flags
# - CXXFLAGS are for C++-specific compilation flags
# - CPPFLAGS are for pre-processor flags
# - CPPDEFINES are for pre-processor defines
# - LINKFLAGS are for linking flags

opts.Add(EnumVariable('platform', "Compilation platform", 'linux', ['', 'windows', 'x11', 'linux', 'osx']))
opts.Add(BoolVariable('use_llvm', "Use the LLVM / Clang compiler", 'no'))

#Godot Headers
godot_headers_path = "lib/godot-cpp/godot_headers/"
godot_cpp_bindings_path = "lib/godot-cpp/"

#Godot Appending headers
env.Append(CPPPATH=['.', godot_headers_path, godot_cpp_bindings_path + 'include/', 
                    godot_cpp_bindings_path + 'include/core/', 
                    godot_cpp_bindings_path + 'include/godot_cpp/variant', 
                    godot_cpp_bindings_path + 'include/godot_cpp/core', 
                    godot_cpp_bindings_path + 'gen/include/godot_cpp/classes', 
                    godot_cpp_bindings_path + 'gen/include/godot_cpp/core', 
                    godot_cpp_bindings_path + 'gen/include/godot_cpp/variant',
                    ])
env.Append(CCFLAGS = ['-g'])
env.Append(CXXFLAGS = ['-g'])

#Sol Headers
sol_headers_path = "lib/sol2/include/"
sol_cpp_bindings_path = "lib/sol2/include/sol/"
#Sol2 Appending headers
env.Append(CPPPATH=[sol_headers_path, sol_cpp_bindings_path ,
                    sol_cpp_bindings_path + 'compatibility'])
# Sol defines
env.Append(CPPDEFINES=["SOL_EXCEPTIONS_SAFE_PROPAGATION=1", "SOL_NO_NIL=0", "SOL_USING_CXX_LUA=1"])
if env['target'] == "template_debug":
    env.Append(CPPDEFINES=["SOL_ALL_SAFETIES_ON=1", "SOL_PRINT_ERRORS=1"])
#Lua Headers
lua_headers_path = "lib/lua"
lua_cpp_bindings_path = "lib/lua/"
#Lua Appending headers
env.Append(CPPPATH=[lua_headers_path, lua_cpp_bindings_path])

#Lua Gd Extension Headers
luagd_headers_path = "lib/lua-gdextension/src"
luagd_cpp_bindings_path = "lib/lua-gdextension/src"
#Lua Gd Extension Appending headers
env.Append(CPPPATH=[luagd_headers_path, luagd_cpp_bindings_path,
                   luagd_cpp_bindings_path + "/luaopen",
                   luagd_cpp_bindings_path + "/script-language",
                   luagd_cpp_bindings_path + "/utils",
                   
                   ])

# tweak this if you want to use different folders, or more folders, to store your source code in.
env.Append(CPPPATH=["src/", "src/scenes/camera/hud", "src/scenes/level/base"])
sources = Glob("src/*.cpp") + \
    Glob("src/objects/node/*.cpp")+ \
    Glob("src/objects/script/*.cpp")+ \
    Glob("src/scenes/environment/*.cpp")+ \
    Glob("src/scenes/world/*.cpp")+ \
    Glob("src/scenes/level/base/*.cpp")+ \
    Glob("src/scenes/level/base/wall/*.cpp")+ \
    Glob("src/scenes/camera/*.cpp")+ \
    Glob("lib/lua-gdextension/src/*.cpp")+ \
    Glob("lib/lua-gdextension/src/luaopen/*.cpp")+ \
    Glob("lib/lua-gdextension/src/utils/*.cpp")+ \
    Glob("lib/lua-gdextension/src/script-language/*.cpp")+ \
    Glob("src/scenes/camera/hud/*.cpp")


# Build Lua GDExtension
# Setup variant build dir for each setup
# def remove_prefix(s, prefix):
#     return s[len(prefix):] if s.startswith(prefix) else s

# build_dir = f"build/{remove_prefix(env['suffix'], '.')}"
# VariantDir(build_dir, 'src', duplicate=False)
# source_directories = ["lib/lua-gdextension/src/luaopen", "lib/lua-gdextension/src/utils", "lib/lua-gdextension/src/script-language"]
# sources = [
#     Glob(f"{build_dir}/{directory}/*.cpp")
#     for directory in source_directories
# ]
# End Build Lua GDExtension

# Compile with debugging symbols
def remove_options(lst, *options) -> bool:
    removed_something = False
    for opt in options:
        if opt in lst:
            lst.remove(opt)
            removed_something = True
    return removed_something

# Lua GDExtension uses C++20 instead of C++17 from godot-cpp
if remove_options(env["CXXFLAGS"], "-std=c++17"):
    env.Append(CXXFLAGS="-std=c++20")
elif remove_options(env["CXXFLAGS"], "/std:c++17"):
    env.Append(CXXFLAGS="/std:c++20")
# Avoid stripping all symbols, we need `luagdextension_entrypoint` exported
remove_options(env["LINKFLAGS"], "-s")

# Lua needs exceptions enabled
remove_options(env["CXXFLAGS"], "-fno-exceptions")

if env["platform"] == "macos":
    library = env.SharedLibrary(
        "demo/bin/libgdexample.{}.{}.framework/libgdexample.{}.{}".format(
            env["platform"], env["target"], env["platform"], env["target"]
        ),
        source=sources,
    )
    env.Append(CPPDEFINES="LUA_USE_MACOSX")
elif env["platform"] == "ios":
    if env["ios_simulator"]:
        library = env.StaticLibrary(
            "demo/bin/libgdexample.{}.{}.simulator.a".format(env["platform"], env["target"]),
            source=sources,
        )
    else:
        library = env.StaticLibrary(
            "demo/bin/libgdexample.{}.{}.a".format(env["platform"], env["target"]),
            source=sources,
        )
else:
    env["suffix"] = ".{}.{}.dev.x86_64".format(env["platform"], env["target"])
    library = env.SharedLibrary(
        "demo/bin/libgdexample{}{}".format(env["suffix"], env["SHLIBSUFFIX"]),
        source=sources,
    )
    env.Append(CPPDEFINES="LUA_USE_LINUX")



Default(library)
