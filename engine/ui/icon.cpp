#include "include/ui/icon.h"

namespace engine
{
	namespace ui
	{
		Icon::Icon(const sf::Texture& texture, int8_t x, int8_t y, int8_t width, int8_t height, int8_t tiledimension, float scaleFactor)
			: m_scaleFactor(scaleFactor)
		{
			sf::IntRect rect(x * tiledimension, y * tiledimension, width, height);
			m_sprite = new sf::Sprite(texture, rect);

			m_outline = sf::RectangleShape(sf::Vector2f(width, height));
			m_outline.setFillColor(sf::Color(0, 0, 0, 0));
			m_outline.setOutlineColor(sf::Color::Red);
			m_outline.setOutlineThickness(0.5);

			m_sprite->setScale(sf::Vector2f(scaleFactor, scaleFactor));
			m_outline.setScale(sf::Vector2f(scaleFactor, scaleFactor));
		}

		Icon::Icon(const sf::Texture& texture, sf::Vector2f& pos, int8_t width, int8_t height, int8_t tiledimension, float scaleFactor)
			: Icon(texture, pos.x, pos.y, width, height, tiledimension, scaleFactor)
		{
		}

		Icon::~Icon()
		{
			
		}

		void Icon::setScaleFactor(const float& scale)
		{ 
			m_sprite->setScale(sf::Vector2f(scale, scale)); 
			m_outline.setScale(sf::Vector2f(scale, scale));

			m_scaleFactor = scale;
		}

		void Icon::setPosition(const sf::Vector2f& pos)
		{ 
			m_sprite->setPosition(pos); 
			m_outline.setPosition(pos);
		}

		void Icon::draw(sf::RenderWindow& window)
		{
			window.draw(*m_sprite);
#ifdef DEBUG_MODE
			window.draw(m_outline);
#endif
		}
	}
}
