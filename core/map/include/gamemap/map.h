#pragma once

#include "wall.h"

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

			void draw(sf::RenderWindow& window);
		};
	}
}