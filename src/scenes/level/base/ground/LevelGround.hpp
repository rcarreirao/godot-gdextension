#ifndef LEVEL_GROUND_HPP
#define LEVEL_GROUND_HPP

#include <plane_mesh.hpp>
#include <area3d.hpp>
#include <vector3.hpp>
#include <collision_shape3d.hpp>
#include <resource_loader.hpp>
#include <standard_material3d.hpp>
#include <godot_cpp/classes/texture2d.hpp>
#include <mesh_instance3d.hpp>

namespace godot {

    class LevelGround : public Node3D {
        GDCLASS(LevelGround, Node3D)

    private:
        MeshInstance3D *mesh;
        PlaneMesh *planeMesh;
        Area3D *area3d; // this will hold ground area for collision detection
        CollisionShape3D *checkpoint;
        StandardMaterial3D *materialPlaneMesh;
        Ref<Texture2D> texture;

    protected:
        static void _bind_methods();
        void setupPlaneMesh();
        void setupArea3d();
        
    public:
        LevelGround();
        ~LevelGround();

        void _process(double delta) override;
        void _ready() override;
        void setup();
    };

}

#endif