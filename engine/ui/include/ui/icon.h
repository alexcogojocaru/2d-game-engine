#pragma once

#include <SFML/Graphics.hpp>

namespace engine
{
	namespace ui
	{
		class Drawable
		{
		public:
			virtual void draw(sf::RenderWindow& window) = 0;
		};

		class Icon : public Drawable
		{
		private:
			sf::Sprite* m_sprite;

		public:
			Icon(sf::Texture& texture, int8_t x, int8_t y, int8_t width = 32, int8_t height = 32, int8_t tiledimension = 32);
			Icon(sf::Texture& texture, sf::Vector2f& pos, int8_t width = 32, int8_t height = 32, int8_t tiledimension = 32);
			~Icon();

			void setScale(sf::Vector2f& scale) { m_sprite->setScale(scale); }
			void setScale(sf::Vector2f&& scale) { m_sprite->setScale(scale); }

			void setPosition(sf::Vector2f& pos) { m_sprite->setPosition(pos); }
			void setPosition(sf::Vector2f&& pos) { m_sprite->setPosition(pos); }

			void draw(sf::RenderWindow& window) override;
		};
	}
}