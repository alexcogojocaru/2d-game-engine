#include "item.h"

namespace core
{
	class Weapon : public Item
	{
	public:
		Weapon(b2World& world, const sf::Texture& texture, const sf::Vector2f texturePos);
	};
}