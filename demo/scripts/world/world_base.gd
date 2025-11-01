@tool # <-- So it runs in the editor
extends WorldBase

#var levelBase := LevelBase()
#var environmentLight := EnvironmentLight()


# Called when the node enters the scene tree for the first time.
func _ready():
	print("ready");
	var cameraBase := CameraBase.new()
	var levelBase := LevelBase.new()
	var environmentLight := EnvironmentLight.new()

	add_child(cameraBase)
	add_child(levelBase)
	add_child(environmentLight)
	pass

# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(_delta):
	#print("process");
	pass
