#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

namespace core
{
    class Animation
    {
    private:
        static uint32_t s_switchTime;
        std::vector<sf::Sprite> m_sprites;

    private:
        sf::Sprite createSprite(sf::Texture& texture, sf::Vector2f pos);

    public:
        Animation(sf::Texture& texture, sf::Vector2f pos, uint32_t length);

        void update();
        void draw(sf::RenderWindow& window);
    };
}