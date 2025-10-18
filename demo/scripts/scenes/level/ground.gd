var clamped := -15.0
@onready var player : CharacterBody3D = get_parent().get_node("Player")

func _check_state(delta):
	match state: 
		StateMachine.IDLE: _state_idle(delta)
		StateMachine.WALK: _state_walk(delta)

func set_camera_limit(limit: float) -> void:
	clamped = limit


func _state_idle(delta: float) -> void:
	_stop_movement()
	if directionX || directionY:
		_enter_state(StateMachine.WALK)

	
func _state_walk(delta: float) -> void:
	_move_and_slide(delta)
	
	if not directionX && not directionY:
		_enter_state(StateMachine.IDLE)
