#ifndef WALLUP_BACKGROUND_HPP
#define WALLUP_BACKGROUND_HPP

#include <csg_mesh3d.hpp>
#include <plane_mesh.hpp>
#include <resource_loader.hpp>
#include <standard_material3d.hpp>
#include <mesh_instance3d.hpp>
#include <godot_cpp/classes/texture2d.hpp>

namespace godot {

    class WallUpBackground : public Node3D {
        GDCLASS(WallUpBackground, Node3D)

    private:
        MeshInstance3D *mesh;
        PlaneMesh *planeMesh;
        StandardMaterial3D *materialPlaneMesh;
        Ref<Texture2D> texture;
    protected:
        static void _bind_methods();
        void setup();
        
    public:
        WallUpBackground();
        ~WallUpBackground();

        void _process(double delta) override;
        void _ready() override;
        void setPlaneMeshSize(Vector2 vector);
        void setupMaterialPlaneMesh();

    };

}

#endif