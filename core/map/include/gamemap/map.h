#pragma once

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
			b2World world;

		public:
			Map();
			Map(b2World& world);

			void update();
			void draw(sf::RenderWindow& window);
		};
	}
}