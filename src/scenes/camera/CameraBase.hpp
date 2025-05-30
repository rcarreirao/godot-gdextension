#ifndef CAMERABASE_HPP
#define CAMERABASE_HPP

#include <camera3d.hpp>
#include <vector3.hpp>
#include <input_event.hpp>
#include "hud/CameraHud.hpp"
#include "../../enum/StateMachine.hpp"
//#include "hud/CameraContainer.hpp"
namespace godot {

class CameraBase : public Camera3D {
	GDCLASS(CameraBase, Camera3D)

private:
    Vector3     motion ;     
    float   directionX;
    float   directionY;  
    float   directionZ;  
    bool    enter_state; 
    float   smooth     ; 
    float   speed       ;
    StateMachine state;
    CameraHud *cameraHud;
    Camera3D *camera = nullptr;

protected:
	static void _bind_methods();

public:
	CameraBase();
	~CameraBase();

	void _process(double delta) override;
	void checkState(double delta);
	void stateIdle(double delta);
	void stateWalk(double delta);
	void enterState(StateMachine state);
	void moveAndSlide(double delta);
    virtual void _input(const Ref<InputEvent> &p_event) override;
    void _ready() override;
};

}

#endif