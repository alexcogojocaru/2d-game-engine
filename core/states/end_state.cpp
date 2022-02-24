#include "include/state/end_state.h"

namespace core
{
	EndState::EndState(sf::RenderWindow& window, uint32_t width, uint32_t height) :
		State(window, width, height)
	{
		const sf::Texture& iconTexture = textureManager->getTexture(texp::ICON_TEXTURE);

		std::vector<sf::Vector2f> youLetters = { LETTER_CAPITAL_Y, LETTER_CAPITAL_O, LETTER_CAPITAL_U };
		std::vector<sf::Vector2f> finishedLetters = { LETTER_CAPITAL_F, LETTER_CAPITAL_I, LETTER_CAPITAL_N, LETTER_CAPITAL_I, LETTER_CAPITAL_S, LETTER_CAPITAL_H, LETTER_CAPITAL_E, LETTER_CAPITAL_D, PUNCTUATION_EXCLAMATION_MARK };

        std::vector<sf::Vector2f> pressLetters = { LETTER_CAPITAL_P, LETTER_CAPITAL_R, LETTER_CAPITAL_E, LETTER_CAPITAL_S, LETTER_CAPITAL_S };
        std::vector<sf::Vector2f> escapeLetters = { LETTER_CAPITAL_E, LETTER_CAPITAL_S, LETTER_CAPITAL_C, LETTER_CAPITAL_A, LETTER_CAPITAL_P, LETTER_CAPITAL_E };
        std::vector<sf::Vector2f> toLetters = { LETTER_CAPITAL_T, LETTER_CAPITAL_O };
        std::vector<sf::Vector2f> exitLetters = { LETTER_CAPITAL_E, LETTER_CAPITAL_X, LETTER_CAPITAL_I, LETTER_CAPITAL_T };

		int startPosition = 700;
        int yPosition = 400;
		congrats.push_back(Word(youLetters, sf::Vector2f(startPosition, yPosition), iconTexture));
		startPosition += (youLetters.size() + 1) * 32;

		congrats.push_back(Word(finishedLetters, sf::Vector2f(startPosition, yPosition), iconTexture));

        startPosition = 600;
        yPosition = 500;

        congrats.push_back(Word(pressLetters, sf::Vector2f(startPosition, yPosition), iconTexture));
        startPosition += (pressLetters.size() + 1) * 32;

        congrats.push_back(Word(escapeLetters, sf::Vector2f(startPosition, yPosition), iconTexture));
        startPosition += (escapeLetters.size() + 1) * 32;

        congrats.push_back(Word(toLetters, sf::Vector2f(startPosition, yPosition), iconTexture));
        startPosition += (toLetters.size() + 1) * 32;

        congrats.push_back(Word(exitLetters, sf::Vector2f(startPosition, yPosition), iconTexture));
        startPosition += (exitLetters.size() + 1) * 32;

        sf::View view(sf::Vector2f(1920 / 2, 1080 / 2), sf::Vector2f(1920, 1080));
        window.setView(view);
	}

	void EndState::update(float deltaTime)
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
                }
                break;
            }
        }
	}

	void EndState::draw()
	{
		for (auto& word : congrats)
		{
			word.draw(window);
		}
	}
}