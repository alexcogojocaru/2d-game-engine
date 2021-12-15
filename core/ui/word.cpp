#include "include/gameui/word.h"

namespace core
{
	const uint32_t Word::CHARACTER_SPACING		= 32u;
	const uint32_t Word::CHARACTER_MOVE_OFFSET	= 2u;

	Word::Word()
	{

	}

	Word::Word(std::vector<sf::Vector2f>& letterCodes, sf::Vector2f& startPos, const sf::Texture& texture, float scale_factor) : 
		m_position(startPos), 
		m_switchTime(0), 
		m_upDirection(1), 
		m_isSelected(false)
	{
		float xPosition = startPos.x;
		float yPosition = startPos.y;

		for (auto& code : letterCodes)
		{
			ui::Icon icon(texture, code);
			icon.setPosition(xPosition, yPosition);
			m_letters.push_back(icon);

			xPosition += CHARACTER_SPACING;
		}

		m_length = m_letters.size();
	}

	Word::Word(std::vector<sf::Vector2f>& letterCodes, sf::Vector2f&& startPos, const sf::Texture& texture, float scale_factor)
		: Word(letterCodes, startPos, texture)
	{

	}

	void Word::deselect() 
	{ 
		m_isSelected = false; 
		for (auto& letter : m_letters)
		{
			letter.setScaleFactor(3.0);
		}
	}

	void Word::update(float deltaTime)
	{
		if (m_isSelected)
		{
			for (auto& letter : m_letters)
			{
				/*sf::Vector2f pos = letter.getPosition();
				letter.setPosition(pos.x, pos.y + 1 * m_upDirection);

				m_switchTime++;
				if (m_switchTime == 50)
				{
					m_switchTime = 0;
					m_upDirection *= -1;
				}*/
				letter.setScaleFactor(4);
			}
		}
	}

	void Word::draw(sf::RenderWindow& window)
	{
		for (auto& letter : m_letters)
		{
			letter.draw(window);
		}
	}
}