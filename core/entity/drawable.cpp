#include "include/entity/drawable.h"

namespace core
{
	Drawable::Drawable(const sf::Texture& texture)
	{
		m_sprite = sf::Sprite(texture);
		m_sprite.setScale(SCALE_FACTOR, SCALE_FACTOR);

		//m_sprite.setColor(sf::Color::Red);
		//m_sprite.setColor(sf::Color::White);
	}

	void Drawable::draw(sf::RenderWindow& window)
	{
		window.draw(m_sprite);
		#ifdef DEBUG
			window.draw(m_outline);
		#endif
	}
}