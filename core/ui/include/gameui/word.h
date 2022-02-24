#pragma once

#include <ui/icon.h>
#include <vector>

using namespace engine;

/// <summary>
/// Namespace that contains the implementation for the core game
/// </summary>
namespace core
{
	class Word
	{
	private:
		static const uint32_t CHARACTER_SPACING;
		static const uint32_t CHARACTER_MOVE_OFFSET;

		std::vector<ui::Icon>	m_letters;
		std::string				m_string;
		sf::Vector2f			m_position;
		uint32_t				m_length;
		float                   m_switchTime;
		int                     m_upDirection;
		bool                    m_isSelected;

	public:
		Word();
		Word(std::vector<sf::Vector2f>& letterCodes, sf::Vector2f& startPos, const sf::Texture& texture, float scale_factor=1.0f);
		Word(std::vector<sf::Vector2f>& letterCodes, sf::Vector2f&& startPos, const sf::Texture& texture, float scale_factor=1.0f);

		void select() { m_isSelected = true; }
		void deselect();

		void update(float deltaTime);
		void draw(sf::RenderWindow& window);

		uint32_t getLength() const { return m_length; }
		std::vector<ui::Icon>& getLetters() { return m_letters; }
	};
}