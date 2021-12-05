#include "include/state/state.h"

namespace core
{
	State::State(sf::RenderWindow& window, uint32_t width, uint32_t height) : 
        screenWidth(width), 
        screenHeight(height), 
        window(window), 
        m_isFullscreen(false), 
        m_hasPlayerAttacked(false), 
        m_playerAttackCount(0)
	{
		textureManager = TextureManager::getInstance();
	}

	void State::update(float deltaTime)
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

            case sf::Event::MouseButtonPressed:
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                log_info("%d %d", mousePos.x, mousePos.y);
                m_hasPlayerAttacked = true;
                m_playerAttackCount = (m_playerAttackCount + 1) % 4;
                break;
            }
        }
	}
}