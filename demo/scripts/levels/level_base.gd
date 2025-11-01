@tool # <-- So it runs in the editor
extends Node3D
@onready var wallUp = $wallUp;
@onready var levelGround = $levelGround;
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
	print(wallUp.get_children());
	wallUp.get_child(0).setup()
	levelGround.set_position(Vector3(3, 0.13, 1));


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	pass

