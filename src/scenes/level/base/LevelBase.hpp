#ifndef LEVELBASE_HPP
#define LEVELBASE_HPP

#include <node3d.hpp>
#include "wall/WallDown.hpp"
#include "wall/WallUp.hpp"
namespace godot {

    class LevelBase : public Node3D {
        GDCLASS(LevelBase, Node3D)

    private:
        WallDown *wallDown;
        WallUp *wallUp;
        
    protected:
        static void _bind_methods();
        
    public:
        LevelBase();
        ~LevelBase();

        void _process(double delta) override;
        void _ready() override;
    };

}

#endif