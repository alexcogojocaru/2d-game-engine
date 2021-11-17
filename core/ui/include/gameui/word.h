#pragma once

#include <ui/icon.h>
#include <vector>

using namespace engine;

namespace core
{
	class Word
	{
	private:
		static const uint32_t CHARACTER_SPACING;
		static const uint32_t CHARACTER_MOVE_OFFSET;

		std::vector<ui::Icon> m_letters;
		sf::Vector2f m_position;
		uint32_t m_length;

	public:
		Word();
		Word(std::vector<sf::Vector2f>& letterCodes, sf::Vector2f& startPos, const sf::Texture& texture);
		Word(std::vector<sf::Vector2f>& letterCodes, sf::Vector2f&& startPos, const sf::Texture& texture);

		void update(bool move);
		void draw(sf::RenderWindow& window);

		uint32_t getLength() const { return m_length; }
		std::vector<ui::Icon>& getLetters() { return m_letters; }
	};
}