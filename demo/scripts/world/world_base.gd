@tool # <-- So it runs in the editor
extends Node3D

#var levelBase := LevelBase()
#var environmentLight := EnvironmentLight()
#@onready var cameraBase := CameraBase.new();

# Called when the node enters the scene tree for the first time.
func _ready():
	print("world base gd ready");
	
	#var levelBase := LevelBase.new()
	#var environmentLight := EnvironmentLight.new()

#	add_child(cameraBase)
	#add_child(levelBase)
	#add_child(environmentLight)
	#environmentLight.setup();
	pass

# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(_delta):
	#print("process");
	pass
