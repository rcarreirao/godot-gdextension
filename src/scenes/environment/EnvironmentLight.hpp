#ifndef ENVIRONMENT_LIGHT_HPP
#define ENVIRONMENT_LIGHT_HPP

#include <directional_light3d.hpp>
#include <godot_cpp/variant/transform3d.hpp>
#include "../../objects/node/Node3DScript.hpp"
#include "../../../objects/script/EngineGdScript.hpp"

namespace godot {

    class EnvironmentLight : public DirectionalLight3D {
        GDCLASS(EnvironmentLight, DirectionalLight3D)

    private:
        String scriptPath = "scripts/levels/1/environment/environment_light.gd";
        Node3DScript *script;

    protected:
        static void _bind_methods();
        
    public:
        EnvironmentLight();
        ~EnvironmentLight();

        void _process(double delta) override;
        void _ready() override;
        void loadScript();
        EnvironmentLight* setup();

    };

}

#endif