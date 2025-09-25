#ifndef GDEXAMPLE_H
#define GDEXAMPLE_H

#include <godot_cpp/classes/sprite2d.hpp>
#include <godot_cpp/classes/texture2d.hpp>
namespace godot {

class GDExample : public Sprite2D {
	GDCLASS(GDExample, Sprite2D)

private:
	double time_passed;

protected:
	static void _bind_methods();
    Ref<Texture2D> texture;
public:
	GDExample();
	~GDExample();

	void _process(double delta) override;
	void _ready() override;
};

}

#endif