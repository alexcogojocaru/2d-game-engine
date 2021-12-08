#include <iostream>
#include "include/gamemap/map.h"

namespace core
{
	namespace map
	{
		Map::Map(b2World& world, std::string seed, sf::Vector2f pos) : world(world)
		{
			std::cout << seed << std::endl;
			m_seedInfo = SeedGenerator::evaluate(seed);

			map::Wall horizontal_wall_0 = map::Wall(world, m_seedInfo.width + 1, 1, b2Vec2(pos.x, pos.y));
			map::Wall horizontal_wall_1 = map::Wall(world, m_seedInfo.width + 1, 1, b2Vec2(pos.x, pos.y + m_seedInfo.height + 1));

			map::Wall vertical_wall_0 = map::Wall(world, 1, m_seedInfo.height, b2Vec2(pos.x, pos.y + 1));
			map::Wall vertical_wall_1 = map::Wall(world, 1, m_seedInfo.height, b2Vec2(m_seedInfo.width + pos.x, pos.y + 1));
			//map::Wall vertical_wall_1_1 = map::Wall(world, 1, m_seedInfo.height - m_seedInfo.height / 2 - 1, b2Vec2(m_seedInfo.width + pos.x, pos.y + m_seedInfo.height / 2 + 1));

			m_walls.push_back(horizontal_wall_0);
			m_walls.push_back(horizontal_wall_1);
			m_walls.push_back(vertical_wall_0);
			m_walls.push_back(vertical_wall_1);
			//m_walls.push_back(vertical_wall_1_1);
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