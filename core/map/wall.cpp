#include <stdio.h>
#include "include/gamemap/wall.h"

#define SCALE_FACTOR 4
#define DIMENSION 32

namespace core
{
	namespace map
	{
		const uint32_t Wall::TILE_DIMENSION = 16;
	
		Wall::Wall()
		{

		}

		Wall::Wall(b2World& world, uint32_t width, uint32_t height, b2Vec2& pos)
		{
			width  *= 32;
			height *= 32;

			pos.x *= 64;
			pos.y *= 64;

			uint32_t width_minimum_factor = (width / DIMENSION - 1) * DIMENSION;
			uint32_t height_minimum_factor = (height / DIMENSION - 1) * DIMENSION;

			b2BodyDef groundBodyDefinition;
			groundBodyDefinition.type = b2_staticBody;
			groundBodyDefinition.position.Set(pos.x + width_minimum_factor, pos.y + height_minimum_factor);

			m_body = world.CreateBody(&groundBodyDefinition);
		
			b2PolygonShape groundBox;
			groundBox.SetAsBox(width, height);
			m_body->CreateFixture(&groundBox, 0.0f);

			m_outline = sf::RectangleShape(sf::Vector2f(width * 2, height * 2));
			m_outline.setPosition(pos.x, pos.y);
			m_outline.setFillColor(sf::Color::Red);
			// m_outline.setOutlineColor(sf::Color::Red);
			// m_outline.setOutlineThickness(0.5);
			// m_outline.setScale(SCALE_FACTOR, SCALE_FACTOR);
		}

		Wall::Wall(b2World& world, uint32_t width, uint32_t height, b2Vec2&& pos)
			: Wall(world, width, height, pos)
		{

		}

		void Wall::draw(sf::RenderWindow& window)
		{
			window.draw(m_outline);
		}
	}
}