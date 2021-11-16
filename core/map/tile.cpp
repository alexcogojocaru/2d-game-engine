#include "include/gamemap/tile.h"

#define SCALE_FACTOR 4

namespace core
{
	namespace map
	{
		const uint32_t Tile::TILE_DIMENSION = 16;
	
		Tile::Tile(b2World& world, uint32_t width, uint32_t height, b2Vec2& pos)
		{
			b2BodyDef groundBodyDefinition;
			groundBodyDefinition.type = b2_staticBody;
			groundBodyDefinition.position.Set(pos.x, pos.y);

			m_body = world.CreateBody(&groundBodyDefinition);
			
			b2PolygonShape groundBox;
			groundBox.SetAsBox(width * 2, height * 2);
			m_body->CreateFixture(&groundBox, 0.0f);

			m_outline = sf::RectangleShape(sf::Vector2f(width * 2, height * 2));
			m_outline.setPosition(pos.x, pos.y);
			m_outline.setFillColor(sf::Color::Red);
			m_outline.setOutlineColor(sf::Color::Red);
			m_outline.setOutlineThickness(0.5);
			m_outline.setScale(SCALE_FACTOR, SCALE_FACTOR);
		}

		void Tile::draw(sf::RenderWindow& window)
		{
			window.draw(m_outline);
		}
	}
}