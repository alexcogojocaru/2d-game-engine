#pragma once

#include "graphics.h"
#include "utils.h"

namespace engine
{
    class Entity
    {
    private:
        sf::Sprite* m_sprite;

    public:
        Entity(const sf::Vector2f position, sf::Vector2f texturePos, b2World &world, const sf::Texture& texture);
        ~Entity();

        void draw(sf::RenderWindow& window, const b2Body* bodyInfo);
    };

} // namespace engine