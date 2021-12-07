#include "include/gamemap/map.h"

namespace core
{
	namespace map
	{
		Map::Map(b2World& world) : world(world)
		{
			map::Wall horizontal_wall_0 = map::Wall(world, 28, 1, b2Vec2(1, 1));
			map::Wall horizontal_wall_1 = map::Wall(world, 28, 1, b2Vec2(1, 15));

			map::Wall vertical_wall_0 = map::Wall(world, 1, 13, b2Vec2(1, 2));
			map::Wall vertical_wall_1 = map::Wall(world, 1, 13, b2Vec2(28, 2));
			map::Wall vertical_wall_2 = map::Wall(world, 1, 4, b2Vec2(10, 2));
			map::Wall vertical_wall_3 = map::Wall(world, 2, 5, b2Vec2(12, 10));
			map::Wall vertical_wall_4 = map::Wall(world, 1, 10, b2Vec2(23, 2));

			m_walls.push_back(horizontal_wall_0);
			m_walls.push_back(horizontal_wall_1);

			m_walls.push_back(vertical_wall_0);
			m_walls.push_back(vertical_wall_1);
			m_walls.push_back(vertical_wall_2);
			m_walls.push_back(vertical_wall_3);
			m_walls.push_back(vertical_wall_4);
		}

		void Map::update()
		{

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