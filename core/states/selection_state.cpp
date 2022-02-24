#include "include/state/selection_state.h"

namespace core
{
	SelectionState::SelectionState(sf::RenderWindow& window, uint32_t width, uint32_t height) :
		State(window, width, height),
        m_currentSelection(0),
        m_currentGender(Gender::MALE)
	{
        const sf::Texture& iconTexture  = textureManager->getTexture(texp::ICON_TEXTURE);
		const sf::Texture& texture      = textureManager->getTexture(texp::SPRITE_TEXTURE);

        m_animationInfoCollection[Gender::MALE].push_back({ MALE_ELF_IDLE , MALE_ELF_RUNNING});
        m_animationInfoCollection[Gender::MALE].push_back({ MALE_KNIGHT_IDLE, MALE_KNIGHT_RUNNING });
        m_animationInfoCollection[Gender::MALE].push_back({ MALE_MAGE_IDLE, MALE_MAGE_RUNNING });
        m_animationInfoCollection[Gender::MALE].push_back({ MALE_DINO_IDLE, MALE_DINO_RUNNING });

        m_animationInfoCollection[Gender::FEMALE].push_back({ FEMALE_ELF_IDLE, FEMALE_ELF_RUNNING });
        m_animationInfoCollection[Gender::FEMALE].push_back({ FEMALE_KNIGHT_IDLE, FEMALE_KNIGHT_RUNNING });
        m_animationInfoCollection[Gender::FEMALE].push_back({ FEMALE_MAGE_IDLE, FEMALE_MAGE_RUNNING });
        m_animationInfoCollection[Gender::FEMALE].push_back({ FEMALE_DINO_IDLE, FEMALE_DINO_RUNNING });

		m_characterAnimInfo.idleInfo		= m_animationInfoCollection[m_currentGender][m_currentSelection].idle;
		m_characterAnimInfo.dimension		= MEDIUM_DIMENSION;

		m_animation = Animation(m_characterAnimInfo);
		m_character = sf::Sprite(texture);
		m_character.scale(sf::Vector2f(8, 8));
		m_character.setPosition(sf::Vector2f(800, 400));

        int startPosition = 400;
        std::vector<sf::Vector2f> pressLetters = { LETTER_CAPITAL_P, LETTER_CAPITAL_R, LETTER_CAPITAL_E, LETTER_CAPITAL_S, LETTER_CAPITAL_S };
        m_changeGenderWord.push_back(Word(pressLetters, sf::Vector2f(startPosition, 100), iconTexture));

        startPosition += (pressLetters.size() + 1) * 32;
        std::vector<sf::Vector2f> spaceLetters = { LETTER_CAPITAL_S, LETTER_CAPITAL_P, LETTER_CAPITAL_A, LETTER_CAPITAL_C, LETTER_CAPITAL_E };
        m_changeGenderWord.push_back(Word(spaceLetters, sf::Vector2f(startPosition, 100), iconTexture));

        startPosition += (spaceLetters.size() + 1) * 32;
        std::vector<sf::Vector2f> toLetters = { LETTER_CAPITAL_T, LETTER_CAPITAL_O };
        m_changeGenderWord.push_back(Word(toLetters, sf::Vector2f(startPosition, 100), iconTexture));

        startPosition += (toLetters.size() + 1) * 32;
        std::vector<sf::Vector2f> changeLetters = { LETTER_CAPITAL_C, LETTER_CAPITAL_H, LETTER_CAPITAL_A, LETTER_CAPITAL_N, LETTER_CAPITAL_G, LETTER_CAPITAL_E };
        m_changeGenderWord.push_back(Word(changeLetters, sf::Vector2f(startPosition, 100), iconTexture));
	
        startPosition += (changeLetters.size() + 1) * 32;
        std::vector<sf::Vector2f> genderLetters = { LETTER_CAPITAL_G, LETTER_CAPITAL_E, LETTER_CAPITAL_N, LETTER_CAPITAL_D, LETTER_CAPITAL_E, LETTER_CAPITAL_R };
        m_changeGenderWord.push_back(Word(genderLetters, sf::Vector2f(startPosition, 100), iconTexture));

        startPosition = 500;
        std::vector<sf::Vector2f> enterLetters = { LETTER_CAPITAL_E, LETTER_CAPITAL_N, LETTER_CAPITAL_T, LETTER_CAPITAL_E, LETTER_CAPITAL_R };
        
        m_enterPlayWord.push_back(Word(pressLetters, sf::Vector2f(startPosition, 600), iconTexture));
    
        startPosition += (pressLetters.size() + 1) * 32;
        m_enterPlayWord.push_back(Word(enterLetters, sf::Vector2f(startPosition, 600), iconTexture));

        startPosition += (enterLetters.size() + 1) * 32;
        m_enterPlayWord.push_back(Word(toLetters, sf::Vector2f(startPosition, 600), iconTexture));
    
        std::vector<sf::Vector2f> startLetters = { LETTER_CAPITAL_S, LETTER_CAPITAL_T, LETTER_CAPITAL_A, LETTER_CAPITAL_R, LETTER_CAPITAL_T };
        startPosition += (toLetters.size() + 1) * 32;
        m_enterPlayWord.push_back(Word(startLetters, sf::Vector2f(startPosition, 600), iconTexture));
    }

	void SelectionState::update(float deltaTime)
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
                
                    if ((_event.key.code == sf::Keyboard::D) || (_event.key.code == sf::Keyboard::Right))
                    {
                        m_currentSelection += 1;

                        if (m_currentSelection >= m_animationInfoCollection[m_currentGender].size())
                        {
                            m_currentSelection = 0;
                        }
                        m_animation.changeIdleAnimation(m_animationInfoCollection[m_currentGender][m_currentSelection].idle);
                    }

                    if ((_event.key.code == sf::Keyboard::A) || (_event.key.code == sf::Keyboard::Left))
                    {
                        m_currentSelection -= 1;

                        if (m_currentSelection < 0)
                        {
                            m_currentSelection = m_animationInfoCollection[m_currentGender].size() - 1;
                        }
                        m_animation.changeIdleAnimation(m_animationInfoCollection[m_currentGender][m_currentSelection].idle);
                    }

                    if ((_event.key.code == sf::Keyboard::Space))
                    {
                        m_currentGender = (m_currentGender == Gender::MALE) ? Gender::FEMALE : Gender::MALE;
                        m_animation.changeIdleAnimation(m_animationInfoCollection[m_currentGender][m_currentSelection].idle);
                    }

                    if ((_event.key.code == sf::Keyboard::Enter))
                    {
                        changeState = true;
                    }
                }
                break;
            }
        }

		m_animation.update(deltaTime, 1);
		sf::IntRect textureRect = m_animation.getTextureBox();
		m_character.setTextureRect(textureRect);
	}

	void SelectionState::draw()
	{
		window.draw(m_character);

        for (auto & word : m_changeGenderWord)
        {
            word.draw(window);
        }

        for (auto& word : m_enterPlayWord)
        {
            word.draw(window);
        }
	}
}