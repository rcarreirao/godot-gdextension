#ifndef ENVIRONMENT_LIGHT_HPP
#define ENVIRONMENT_LIGHT_HPP

#include <directional_light3d.hpp>
#include <godot_cpp/variant/transform3d.hpp>
namespace godot {

    class EnvironmentLight : public DirectionalLight3D {
        GDCLASS(EnvironmentLight, DirectionalLight3D)

    private:

    protected:
        static void _bind_methods();
        
    public:
        EnvironmentLight();
        ~EnvironmentLight();

        void _process(double delta) override;
        void _ready() override;
    };

}

#endif