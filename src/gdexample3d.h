#ifndef GDEXAMPLE3D_H
#define GDEXAMPLE3D_H

#include <godot_cpp/classes/sprite3d.hpp>
#include <godot_cpp/classes/texture2d.hpp>
namespace godot {

class GDExample3D : public Sprite3D {
	GDCLASS(GDExample3D, Sprite3D)

private:
	double time_passed;

protected:
	static void _bind_methods();
    Ref<Texture2D> texture;
public:
	GDExample3D();
	~GDExample3D();

	void _process(double delta) override;
	void _ready() override;
};

}

#endif