#pragma once

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

#define PACIFICO_FONT_PATH "fonts/sketch_gothic.ttf"
#define TRANSPARENCY_THRESHOLD 0x0

#define ICON_DIMENSION 32
#define ICON_1_X

namespace engine
{
	namespace ui
	{
		class Button
		{
		private:
			sf::Text m_text;
			sf::RectangleShape m_box;
			std::vector<sf::Sprite> m_icons;

		public:
			Button(sf::Font& font, sf::Vector2f& position);
			~Button();

			void setString(std::string& string);
			void setString(std::string&& string);
			
			void draw(sf::RenderWindow& window);
		};
	}
}