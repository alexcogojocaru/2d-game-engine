#pragma once

#include <SFML/Graphics.hpp>

//#define DEBUG_MODE

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
			sf::RectangleShape m_outline;

			float m_scaleFactor;

		public:
			Icon(const sf::Texture& texture, int8_t x, int8_t y, int8_t width = 32, int8_t height = 32, int8_t tiledimension = 32, float scaleFactor=3.0f);
			Icon(const sf::Texture& texture, sf::Vector2f& pos, int8_t width = 32, int8_t height = 32, int8_t tiledimension = 32, float scaleFactor = 3.0f);
			~Icon();

			void setScaleFactor(const float& scale);
			void setPosition(const sf::Vector2f& pos);
			float getScaleFactor() const { return m_scaleFactor; }

			void draw(sf::RenderWindow& window) override;
		};
	}
}