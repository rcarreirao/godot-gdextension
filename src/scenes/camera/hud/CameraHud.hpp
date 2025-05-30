#ifndef CAMERAHUD_HPP
#define CAMERAHUD_HPP

#include <container.hpp>
#include "CameraContainer.hpp"
namespace godot {

class CameraHud : public Container {

private:
    CameraContainer *cameraContainer;

protected:
	static void _bind_methods();

public:
	CameraHud();
	~CameraHud();

	void _process(double delta) override;
    void updateLabel(godot::String text);

};

}

#endif