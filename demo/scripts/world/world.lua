local World = {
	-- base class (optional, defaults to RefCounted)
	extends = Node3D,
	-- if true, allow the script to be executed by the editor (optional)
	tool = false,
	-- global class name (optional)
	class_name = "World",
	
}

-- Called when the node enters the scene tree for the first time.
function LuaBouncingLogo:_ready()
	print("Ready World.lua")
		local cameraBase = CameraBase:new()
		self:add_child(cameraBase)
	end
end

-- Return the metadata table for the script to be usable by Godot objects
return World