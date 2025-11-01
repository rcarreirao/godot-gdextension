extends Node3D

@onready var level : Node3D = get_parent().get_parent().get_node("Level")
var collided = 0;
var backgrounds = [];

# Called when the node enters the scene tree for the first time.
func _ready():
	pass # Replace with function body.


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


func addWallUpMesh():
	var positionX = 0;
	if(backgrounds.size()):
		var b = backgrounds[-1];
		positionX = b.position.x + n.get_node("mesh").mesh.size.x
		n.get_node("mesh").mesh.material.set_texture(StandardMaterial3D.TEXTURE_ALBEDO, walls[backgrounds.size()%5]);
	else:
		positionX = 0;
		#n.get_node("mesh").position.y = 0.85;
		#n.get_node("mesh").position.z = -0.22;
	#print("PositionX:"+ str(positionX))
	n.position.x = positionX ;
	n.position.y = n.position.y;
	n.position.z = n.position.z;
	#print("Count"+str(backgrounds.size()))
	backgrounds.append(n);
	add_child(n)