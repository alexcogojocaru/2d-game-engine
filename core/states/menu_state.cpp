#include "include/state/menu_state.h"

namespace core
{
	MenuState::MenuState(sf::RenderWindow& window, uint32_t width, uint32_t height) 
		: State(window, width, height)
	{
		// std::shared_ptr<TextureManager> textureManager = TextureManager::getInstance();
		std::vector<sf::Vector2f> letters = { constants::LETTER_CAPITAL_P, constants::LETTER_CAPITAL_L, constants::LETTER_CAPITAL_A, constants::LETTER_CAPITAL_Y };
		
		const sf::Texture& texture = textureManager->getTexture("icons");
		Word word(letters, sf::Vector2f(100, 100), texture);
		m_words.push_back(word);

		std::vector<sf::Vector2f> optionsLetters = { constants::LETTER_CAPITAL_O, constants::LETTER_CAPITAL_P, constants::LETTER_CAPITAL_T, constants::LETTER_CAPITAL_I, constants::LETTER_CAPITAL_O, constants::LETTER_CAPITAL_N, constants::LETTER_CAPITAL_S };
		Word optionsWord(optionsLetters, sf::Vector2f(100, 170), texture);
		m_words.push_back(optionsWord);

		std::vector<sf::Vector2f> exitLetters = { constants::LETTER_CAPITAL_E, constants::LETTER_CAPITAL_X, constants::LETTER_CAPITAL_I, constants::LETTER_CAPITAL_T };
		Word exitWord(exitLetters, sf::Vector2f(100, 240), texture);
		m_words.push_back(exitWord);
	
		// determine the x position so the text is centered on the screen
		for (auto& word : m_words)
		{
			log_info("length = %u", word.getLength());
			std::vector<ui::Icon>& letters = word.getLetters();

			// first half is moved on the left side of the screen
			int32_t offset = width / 2 - 64;
			for (int i = word.getLength() / 2 - 1; i >= 0; i--)
			{
				letters[i].setPosition(offset, letters[i].get_y_axis());
				offset -= 32;
			}

			offset = width / 2 - 32;
			for (int i = word.getLength() / 2; i < word.getLength(); i++)
			{
				letters[i].setPosition(offset, letters[i].get_y_axis());
				offset += 32;
			}
		}
	}

	void MenuState::update()
	{

	}

	void MenuState::draw()
	{
		for (auto& word : m_words)
		{
			word.draw(window);
		}
	}
}