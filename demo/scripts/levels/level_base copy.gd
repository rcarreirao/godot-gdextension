@tool # <-- So it runs in the editor
extends Node3D
@onready var wallUp = $wallUp;
@onready var imageTexture = preload("res://assets/levels/1/backgrounds/background_2.png");
var walls = [
	preload("res://assets/levels/1/backgrounds/background_1.png"),
	preload("res://assets/levels/1/backgrounds/background_2.png"),
	preload("res://assets/levels/1/backgrounds/background_3.png"),
	preload("res://assets/levels/1/backgrounds/background_4.png"),
	preload("res://assets/levels/1/backgrounds/background_5.png")
]
var floors = [
	preload("res://assets/levels/1/ground/ground_4.png"),
	preload("res://assets/levels/1/ground/ground_4.png"),
	preload("res://assets/levels/1/ground/ground_4.png"),
	preload("res://assets/levels/1/ground/ground_4.png"),
	preload("res://assets/levels/1/ground/ground_4.png")
]

var grounds = [];
var wallsLoaded = [];
# Called when the node enters the scene tree for the first time.

func _ready():
	print("_read level_base");
	
func _old():
	var a = get_children();
	print(a);
	for fruit in a:
		print(fruit)
	var data = [];
	var mesh = ArrayMesh.new();
	var planeMesh = PlaneMesh.new();
	data.resize(ArrayMesh.ARRAY_MAX)
	data[ArrayMesh.ARRAY_VERTEX] = PackedVector3Array([
		Vector3(0,0,0),
		Vector3(1,0,0),
		Vector3(1,1,0)
	]);
	data[ArrayMesh.ARRAY_TEX_UV] = PackedVector2Array([
		Vector2(0.1,1),
		Vector2(0,1),
		Vector2(0,0)
	]);
	mesh.add_surface_from_arrays(Mesh.PRIMITIVE_TRIANGLES, data)
	
	data[ArrayMesh.ARRAY_VERTEX] = PackedVector3Array([
		Vector3(1,0,0),
		Vector3(2,1,0),
		Vector3(1,1,0)
	]);
	data[ArrayMesh.ARRAY_TEX_UV] = PackedVector2Array([
		Vector2(0.1,1),
		Vector2(0,0),
		Vector2(0.1,0)
	])
	mesh.add_surface_from_arrays(Mesh.PRIMITIVE_TRIANGLES, data)
	
	var m = MeshInstance3D.new()
	var icon = preload("res://assets/levels/1/ground/ground_4.png")
	
	var material = StandardMaterial3D.new()
	
	material.albedo_texture = icon
	
	planeMesh.size.x = 15
	mesh.surface_set_material(0, material)
	mesh.surface_set_material(1, material)
	m.mesh = mesh
	#m.rotate_x(deg_to_rad(90.0))
	add_child(m);
	
    #addWallUpMesh();
	#addGroundMesh();

	#wallUp2.material_override.albedo_texture = imageTexture;
	

# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	pass

func addGroundMesh():
	pass
	# var c = preload("res://scenes/levels/ground.tscn")
	# var n = c.instantiate();
	# var positionX = 0;
	# if(grounds.size()):
	# 	var b = grounds[-1];
	# 	positionX = b.position.x + n.get_node("mesh").mesh.size.x
	# 	n.get_node("mesh").mesh.material.set_texture(StandardMaterial3D.TEXTURE_ALBEDO, floors[grounds.size()%5]);
	# else:
	# 	positionX = 0;
	# 	#n.get_node("mesh").position.y = 0.85;
	# 	#n.get_node("mesh").position.z = -0.22;
	# print("PositionX:"+ str(positionX))
	# n.position.x = positionX ;
	# n.position.y = n.position.y;
	# n.position.z = 1;
	# print("Count"+str(grounds.size()))
	# grounds.append(n);
	# add_child(n)
	
func rods():
	print("_rods");
	pass
