#ifndef WORLDBASE_HPP
#define WORLDBASE_HPP

#include <node3d.hpp>
#include "../../objects/node/Node3DScript.hpp"
#include "../camera/CameraBase.hpp"
#include "../../gdexample.h"
#include "../../gdexample3d.h"
#include "../level/base/LevelBase.hpp"
#include "../environment/EnvironmentLight.hpp"
namespace godot {

    class WorldBase : public Node3D {
        GDCLASS(WorldBase, Node3D)

    private:
        CameraBase *cameraBase;
        GDExample *gdExample;
        GDExample3D *gdExample3D;
        LevelBase *levelBase;
        EnvironmentLight *environmentLight;
        Node3DScript *script;
        String scriptPath = "scripts/world/world_base.lua";
        String scriptPathGd = "scripts/world/world_base.gd";

    protected:
        static void _bind_methods();
        void loadScript();
        void loadScriptLua();
        
    public:
        WorldBase();
        ~WorldBase();

        void _process(double delta) override;
        void _ready() override;
    };

}

#endif
