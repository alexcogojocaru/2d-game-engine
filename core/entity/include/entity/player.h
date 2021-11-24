#pragma once

#include "entity.h"

namespace core
{
    class Player : public Entity
    {
    public:
        Player(b2World& world, sf::Vector2f& texturePos, const sf::Texture& texture, const sf::Vector2f& pos);
        Player(b2World& world, sf::Vector2f&& texturePos, const sf::Texture& texture, const sf::Vector2f&& pos);
        ~Player();

        void update() override;
        void draw(sf::RenderWindow& window) override;
    };
}