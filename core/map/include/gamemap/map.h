#pragma once

#include "seed_generator.h"
#include "wall.h"

/// <summary>
/// Namespace that contains the implementation for the core game
/// </summary>
namespace core
{
	namespace map
	{
		class Map
		{
		private:
			std::vector<Wall> m_walls;
			seed_info m_seedInfo;
			b2World world;

		public:
			Map();
			Map(b2World& world, std::string seed, sf::Vector2f pos);

			seed_info getSeedInfo() const { return m_seedInfo; }

			void update();
			void draw(sf::RenderWindow& window);
		};
	}
}