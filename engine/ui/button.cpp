#include "include/ui/button.h"
#include "include/ui/command_buffer.h"

namespace engine
{
	namespace ui
	{
		Button::Button(sf::Font& font, sf::Vector2f& position)
		{
			
			m_text.setFont(font);
			m_text.setString("default asd buna siua buna frate");
			m_text.setCharacterSize(24);
			m_text.setPosition(position);
			m_text.scale(sf::Vector2f(2, 2));

			uint16_t stringLength = m_text.getString().getSize();

			m_box.setFillColor(sf::Color(255, 255, 255, TRANSPARENCY_THRESHOLD));
			m_box.setSize(sf::Vector2f((m_text.getString().getSize() / 2) * 24, 24));
			m_box.setOutlineColor(sf::Color::White);
			m_box.setOutlineThickness(2);
			m_box.setPosition(position);

			printf("(x1, y1) = (%f, %f)\n", m_box.getPosition().x, m_box.getPosition().y);
			printf("(x2, y2) = (%f, %f)\n", m_box.getPosition().x + m_box.getSize().x, m_box.getPosition().y + m_box.getSize().y);
		}

		Button::~Button()
		{
			
		}

		void Button::setString(std::string& string) 
		{ 
			m_text.setString(string); 
			m_box.setSize(sf::Vector2f((m_text.getString().getSize() / 2) * 24, 24));
		}

		void Button::setString(std::string&& string)
		{
			setString(string);
		}

		void Button::draw(sf::RenderWindow& window)
		{
			window.draw(m_text);
			window.draw(m_box);
		}
	}
}