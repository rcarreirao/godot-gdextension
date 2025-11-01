local WorldBase = {
	-- base class (optional, defaults to RefCounted)
	extends = Node3D,
	-- if true, allow the script to be executed by the editor (optional)
	tool = false,
	-- global class name (optional)
	class_name = "WorldBase",
	
    cameraBase = CameraBase:new(),
    levelBase = LevelBase:new(),
    environmentLight = DirectionalLight3D:new()
}
local floors = {
    "res://assets/levels/ground/ground_4.png",
    "res://assets/levels/ground/ground_4.png",
    "res://assets/levels/ground/ground_4.png",
    "res://assets/levels/ground/ground_4.png",
    "res://assets/levels/ground/ground_4.png"
}

-- Called when the node enters the scene tree for the first time.
function WorldBase:_ready()
	print("Ready WorldBase.lua")
    self:add_child(self.cameraBase)
    self:add_child(self.levelBase)
    self:startEnvironmentLight()
    self:warmUp()
end

function WorldBase:startEnvironmentLight()
    self.environmentLight.light_energy = 4.429
    self.environmentLight.light_color = Color(1, 1, 1)
    self.environmentLight.rotation_degrees = Vector3(-70, 0, 0)
    self.environmentLight.position = Vector3(0, 1, 1.315)
    self:add_child(self.environmentLight)
end

function WorldBase:warmUp()
    local mesh = ArrayMesh:new();
	local planeMesh = PlaneMesh:new();
    local data = {};
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
end

-- Return the metadata table for the script to be usable by Godot objects
return WorldBase