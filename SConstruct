#!/usr/bin/env python
import os
import sys

env = SConscript("godot-cpp/SConstruct")
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

godot_headers_path = "godot-cpp/godot_headers/"
cpp_bindings_path = "godot-cpp/"


# tweak this if you want to use different folders, or more folders, to store your source code in.
env.Append(CPPPATH=["src/", "src/scenes/camera/hud", "src/scenes/level/base"])
sources = Glob("src/*.cpp") + \
    Glob("src/scenes/environment/*.cpp")+ \
    Glob("src/scenes/world/*.cpp")+ \
    Glob("src/scenes/level/base/*.cpp")+ \
    Glob("src/scenes/level/base/wall/*.cpp")+ \
    Glob("src/scenes/camera/*.cpp")+ \
    Glob("src/scenes/camera/hud/*.cpp")

if env["platform"] == "macos":
    library = env.SharedLibrary(
        "demo/bin/libgdexample.{}.{}.framework/libgdexample.{}.{}".format(
            env["platform"], env["target"], env["platform"], env["target"]
        ),
        source=sources,
    )
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
    library = env.SharedLibrary(
        "demo/bin/libgdexample{}{}".format(env["suffix"], env["SHLIBSUFFIX"]),
        source=sources,
    )

env.Append(CPPPATH=['.', godot_headers_path, cpp_bindings_path + 'include/', 
                    cpp_bindings_path + 'include/core/', 
                    cpp_bindings_path + 'include/godot_cpp/variant', 
                    cpp_bindings_path + 'include/godot_cpp/core', 
                    cpp_bindings_path + 'gen/include/godot_cpp/classes', 
                    cpp_bindings_path + 'gen/include/godot_cpp/core', 
                    cpp_bindings_path + 'gen/include/godot_cpp/variant'])

Default(library)
