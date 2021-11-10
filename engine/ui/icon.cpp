#include "include/ui/icon.h"

namespace engine
{
	namespace ui
	{
		Icon::Icon(sf::Texture& texture, int8_t x, int8_t y, int8_t width, int8_t height, int8_t tiledimension)
		{
			sf::IntRect rect(x * tiledimension, y * tiledimension, width, height);
			m_sprite = new sf::Sprite(texture, rect);
		}

		Icon::Icon(sf::Texture& texture, sf::Vector2f& pos, int8_t width, int8_t height, int8_t tiledimension)
			: Icon(texture, pos.x, pos.y, width, height, tiledimension)
		{
		}

		Icon::~Icon()
		{
			delete m_sprite;
		}

		void Icon::draw(sf::RenderWindow& window)
		{
			window.draw(*m_sprite);
		}
	}
}
