@tool
extends CameraBase

func _ready():
	self.setPosition(Vector3(0,3,4));
	self.updateCameraPosition();
	print("Camera base gd ready");

func teste():
	print("Camera teste")

func _process(delta):
	if not Engine.is_editor_hint():
		self.checkState(delta);
	pass
