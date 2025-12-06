@tool
extends Node3D
@onready var level : Node3D = get_parent().get_parent().get_node("LevelBase")
var collided = 0;
var backgrounds = [];

# Called when the node enters the scene tree for the first time.
func _ready():
	addWallUpBackground();
	pass # Replace with function body.

func addWallUpBackground():
	var c = preload("res://assets/levels/1/scenes/wall_up_background.tscn")
	var n = c.instantiate();
	#add_child(n)
# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	pass

func _on_area_3d_body_entered(body):
	if(collided == 0):
		level.addWallUpMesh()
		disableAreaEnteredEvent()
	collided+=1;
	pass # Replace with function body.

#This will disable the event to load new wall when camera enters.
func disableAreaEnteredEvent():
	get_node("Area3D").disconnect("body_entered", self._on_area_3d_body_entered)
	call_deferred("remove_child", get_node("Area3D"))
