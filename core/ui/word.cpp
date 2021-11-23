#include "include/gameui/word.h"

namespace core
{
	const uint32_t Word::CHARACTER_SPACING		= 32u;
	const uint32_t Word::CHARACTER_MOVE_OFFSET	= 2u;

	Word::Word()
	{

	}

	Word::Word(std::vector<sf::Vector2f>& letterCodes, sf::Vector2f& startPos, const sf::Texture& texture, float scale_factor)
		: m_position(startPos)
	{
		float xPosition = startPos.x;
		float yPosition = startPos.y;

		for (auto& code : letterCodes)
		{
			ui::Icon icon(texture, code);
			icon.setPosition(xPosition, yPosition);
			//icon.setScaleFactor(scale_factor);
			m_letters.push_back(icon);

			xPosition += CHARACTER_SPACING;
		}

		m_length = m_letters.size();
	}

	Word::Word(std::vector<sf::Vector2f>& letterCodes, sf::Vector2f&& startPos, const sf::Texture& texture, float scale_factor)
		: Word(letterCodes, startPos, texture)
	{

	}

	void Word::update(bool move)
	{

	}

	void Word::draw(sf::RenderWindow& window)
	{
		for (auto& letter : m_letters)
		{
			letter.draw(window);
		}
	}
}