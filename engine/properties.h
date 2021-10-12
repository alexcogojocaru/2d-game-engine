#pragma once

namespace entity
{
	enum class main_character_class
	{
		KNIGHT	= 0xC00,
		ARCHER	= 0xC01,
		MAGE	= 0xC02
	};

	enum class animation_state
	{
		IDLE		= 0xA01,
		RUNNING		= 0xA02,
		ATTACKING	= 0xA03
	};

	struct entity_property
	{
		double health;
		double damage;
		double armor;
	};
}