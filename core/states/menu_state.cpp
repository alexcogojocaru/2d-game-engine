#include "include/state/menu_state.h"

namespace core
{
	MenuState::MenuState(sf::RenderWindow& window, uint32_t width, uint32_t height) 
		: State(window, width, height)
	{
		std::vector<sf::Vector2f> letters = { constants::LETTER_CAPITAL_P, constants::LETTER_CAPITAL_L, constants::LETTER_CAPITAL_A, constants::LETTER_CAPITAL_Y };
		
		const sf::Texture& texture = textureManager->getTexture(texp::ICON_TEXTURE);
		Word playWord(letters, sf::Vector2f(100, height / 2 - 140), texture);
		m_words.push_back(playWord);

		std::vector<sf::Vector2f> exitLetters = { constants::LETTER_CAPITAL_E, constants::LETTER_CAPITAL_X, constants::LETTER_CAPITAL_I, constants::LETTER_CAPITAL_T };
		Word exitWord(exitLetters, sf::Vector2f(100, height / 2 - 70 ), texture);
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

		const sf::Texture& backgroundTexture = textureManager->getTexture(texp::MENU_BACKGROUND_TEXTURE);
		m_background = sf::Sprite(backgroundTexture);
		m_background.setScale(3.5, 3);
	}

	void MenuState::update(float deltaTime)
	{
		sf::Event _event;
		while (window.pollEvent(_event))
		{
			switch (_event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::KeyPressed:
				if (_event.type == sf::Event::KeyPressed)
				{
					if (_event.key.code == sf::Keyboard::Escape)
					{
						window.close();
					}

					if (_event.key.code == sf::Keyboard::F11)
					{
						if (!m_isFullscreen)
						{
							window.create(sf::VideoMode::getDesktopMode(), "title", sf::Style::Fullscreen);
						}
						else
						{
							window.create(sf::VideoMode::getDesktopMode(), "title", sf::Style::Default);
						}

						m_isFullscreen = !m_isFullscreen;
					}

					if (_event.key.code == sf::Keyboard::Enter)
					{
						if (currentWord == 0)
						{
							changeState = true;
						}

						if (currentWord == m_words.size() - 1)
						{
							window.close();
						}
					}

					if (_event.key.code == sf::Keyboard::Down)
					{
						currentWord = (currentWord + 1) % m_words.size();
						m_words[currentWord].select();

						for (int i = 0; i < m_words.size(); i++)
						{
							if (i != currentWord)
							{
								m_words[i].deselect();
							}
						}
					}

					if (_event.key.code == sf::Keyboard::Up)
					{
						currentWord--;

						if (currentWord < 0)
						{
							currentWord = m_words.size() - 1;
						}

						m_words[currentWord].select();
						for (int i = 0; i < m_words.size(); i++)
						{
							if (i != currentWord)
							{
								m_words[i].deselect();
							}
						}
					}
				}
				break;
			}
		}

		for (auto& word : m_words)
		{
			word.update(deltaTime);
		}
	}

	void MenuState::draw()
	{
		window.draw(m_background);

		for (auto& word : m_words)
		{
			word.draw(window);
		}
	}
}