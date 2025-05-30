extends Camera3D
enum StateMachine { IDLE, WALK}

@export var speed := 1

var motion := Vector3()
var state = StateMachine.IDLE
var directionX := 0
var directionY := 0
var enter_state := true
var smooth:= 4

func _process(delta: float) -> void:
	directionX = Input.get_axis("ui_left", "ui_right")
	#directionY = Input.get_axis("ui_camera_up", "ui_camera_down")
	#directionVertical = Input.get_axis("ui_up", "ui_down")
	
	_check_state(delta)

func _check_state(delta):
	match state: 
		StateMachine.IDLE: _state_idle(delta)
		StateMachine.WALK: _state_walk(delta)

func _state_idle(delta: float) -> void:
	_stop_movement()
	if directionX || directionY:
		_enter_state(StateMachine.WALK)

	
func _state_walk(delta: float) -> void:
	_move_and_slide(delta)
	
	if not directionX && not directionY:
		_enter_state(StateMachine.IDLE)


func _move_and_slide(delta: float) -> void:
	position.x = lerp(position.x, position.x+float(directionX * speed) , smooth * delta)
	position.y = lerp(position.y, position.y + float(directionY * speed * -1)  , smooth * delta)
	print("Movendo" + str(position.x))

func _stop_movement() -> void:
	motion.x = 0
	motion.y = 0

func _enter_state(new_state)  -> void:
	if state != new_state:
		state = new_state
		enter_state = true
