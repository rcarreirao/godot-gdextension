local LuaBouncingLogo = {
	-- base class (optional, defaults to RefCounted)
	extends = Sprite2D,
	-- if true, allow the script to be executed by the editor (optional)
	tool = false,
	-- global class name (optional)
	class_name = "LuaBouncingLogo",
	
	-- Declare properties
	linear_velocity = export(100),
	count = 0,
	initial_angle = export({
		type = float,
		default = 0,
		hint = PROPERTY_HINT_RANGE,
		hint_string = "0,360,degrees"
	}),
	-- Declare signals
	bounced = signal(),
}
-- Called when the node enters the scene tree for the first time.
function LuaBouncingLogo:_ready()
	print("Ready lua----------------------")
	--self.position = self:get_viewport():get_size() / 2
	-- self.movement = Vector2(self.linear_velocity, 0):rotated(deg_to_rad(self.initial_angle))
end

function LuaBouncingLogo:get_viewport()
	
end

function LuaBouncingLogo:_rods()
	print("Rods")
	local n = Node:new()
	--self:add_child(n)
	print(self)
	print(n:is_inside_tree())  -- false
	--n:queue_free()
	--local sprite = Sprite2D:new()

	--Load and assign a texture
	-- sprite.texture = self:load("res://icon_green.png")

	--Set position (optional)
	--sprite.position = Vector2(5, -5)

	--Add the sprite to the current scene
	return 1
end

-- Called every frame. 'delta' is the elapsed time since the previous frame.
function LuaBouncingLogo:_process(delta)
	-- print("_process lua")
	--print(self.count)
	if(self.count == 0) then
		local sprite = Sprite2D:new()

		sprite.texture = ResourceLoader:load("res://icon_green.png")
		print("Exists")
		print(ResourceLoader:exists("res://icon_green.png"))

		sprite.position = Vector2(150, 5)
		self:add_child(sprite)
	end
	self.count = self.count + 1
	-- local viewport_size = self:get_viewport():get_size()
	-- local viewport_rect = Rect2(Vector2(), viewport_size)
	-- if not viewport_rect:encloses(self.global_transform * self:get_rect()) then
	-- 	self.movement = self.movement:rotated(deg_to_rad(90))
	--	self.bounced:emit()
	--end
	--self.position = self.position + self.movement * delta
end

-- Return the metadata table for the script to be usable by Godot objects
return LuaBouncingLogo
