#pragma once

#include <godot_cpp/godot.hpp>
#include <godot_cpp/classes/character_body2d.hpp>

class Fred : public godot::CharacterBody2D
{
	GDCLASS(Fred, CharacterBody2D)

public:

	static void		_bind_methods();

};