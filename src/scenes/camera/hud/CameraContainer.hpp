#ifndef CAMERACONTAINER_HPP
#define CAMERACONTAINER_HPP

#include <container.hpp>
#include <vector2.hpp>
#include <label.hpp>

namespace godot {

class CameraContainer : public Container {

private:
    Label *labelPosition;
protected:
	static void _bind_methods();

public:
	CameraContainer();
	~CameraContainer();

	void _process(double delta) override;
	void _ready() override;
    bool unreference();

    void updateLabel(godot::String text);
};

}

#endif