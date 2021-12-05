#include "include/items/weapon.h"

namespace core
{
	Weapon::Weapon(b2World& world, const sf::Texture& texture, const sf::Vector2f texturePos) :
		Item(world, texture, texturePos)
	{

	}
}