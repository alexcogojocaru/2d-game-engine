#include "include/gamemap/map.h"

namespace core
{
	namespace map
	{
		Map::Map(b2World& world) : world(world)
		{
			map::Wall tile = map::Wall(world, 28, 1, b2Vec2(64, 64));
			m_walls.push_back(tile);
		}

		void Map::draw(sf::RenderWindow& window)
		{
			for (auto& wall : m_walls)
			{
				wall.draw(window);
			}
		}
	}
}