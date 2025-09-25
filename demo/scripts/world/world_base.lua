local WorldBase = {
	-- base class (optional, defaults to RefCounted)
	extends = Node3D,
	-- if true, allow the script to be executed by the editor (optional)
	tool = false,
	-- global class name (optional)
	class_name = "WorldBase",
	
}

-- Called when the node enters the scene tree for the first time.
function WorldBase:_ready()
	print("Ready WorldBase.lua")
    local cameraBase = CameraBase:new()
    self:add_child(cameraBase)
end

-- Return the metadata table for the script to be usable by Godot objects
return WorldBase