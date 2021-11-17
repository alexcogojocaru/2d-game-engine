#pragma once

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include <memory>

namespace core
{
	namespace map
	{
		class Tile
		{
		private:
			static const uint32_t TILE_DIMENSION;
			sf::RectangleShape m_outline;
			b2Body* m_body;

		public:
			Tile(b2World& world, uint32_t width, uint32_t height, b2Vec2& pos);
			Tile(b2World& world, uint32_t width, uint32_t height, b2Vec2&& pos);

			void draw(sf::RenderWindow& window);
		};
	}
}