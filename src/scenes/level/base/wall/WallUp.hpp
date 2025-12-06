#ifndef WALLUP_HPP
#define WALLUP_HPP

#include <csg_mesh3d.hpp>
#include <plane_mesh.hpp>
#include <resource_loader.hpp>
#include <standard_material3d.hpp>
#include <godot_cpp/classes/texture2d.hpp>
#include "WallUpBackground.hpp"

namespace godot {

    class WallUp : public CSGMesh3D {
        GDCLASS(WallUp, CSGMesh3D)

    private:
        

    protected:
        static void _bind_methods();
        void setup();
        
    public:
        WallUp();
        ~WallUp();

        void _process(double delta) override;
        void _ready() override;

    };

}

#endif