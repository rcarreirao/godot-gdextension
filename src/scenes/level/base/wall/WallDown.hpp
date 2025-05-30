#ifndef WALLDOWN_HPP
#define WALLDOWN_HPP

#include <csg_mesh3d.hpp>
#include <box_mesh.hpp>
#include <vector3.hpp>
namespace godot {

    class WallDown : public CSGMesh3D {
        GDCLASS(WallDown, CSGMesh3D)

    private:
        BoxMesh *boxMesh;

    protected:
        static void _bind_methods();
        
    public:
        WallDown();
        ~WallDown();

        void _process(double delta) override;
        void _ready() override;
        void setup();
        void setBoxMeshSize(Vector3 vector);
    };

}

#endif