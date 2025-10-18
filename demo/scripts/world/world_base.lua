local WorldBase = {
	-- base class (optional, defaults to RefCounted)
	extends = Node3D,
	-- if true, allow the script to be executed by the editor (optional)
	tool = false,
	-- global class name (optional)
	class_name = "WorldBase",
	
    cameraBase = CameraBase:new(),
    levelBase = LevelBase:new()
}

-- Called when the node enters the scene tree for the first time.
function WorldBase:_ready()
	print("Ready WorldBase.lua")
    self:add_child(self.cameraBase)
    self:add_child(self.levelBase)
end

-- Return the metadata table for the script to be usable by Godot objects
return WorldBase