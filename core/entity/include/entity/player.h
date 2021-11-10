#pragma once

#include "entity.h"

namespace core
{
    class Player : public Entity
    {
    public:
        Player(b2World& world, sf::Vector2f& texturePos, const sf::Texture& texture);
        ~Player();

        void update() override;
        void draw(sf::RenderWindow& window) override;
    };
}