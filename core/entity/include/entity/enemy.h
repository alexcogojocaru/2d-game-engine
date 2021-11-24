#pragma once

#include "entity.h"

namespace core
{
    class Enemy : public Entity
    {
    private:
        float m_offset;
        
    public:
        Enemy(b2World& world, sf::Vector2f& texturePos, const sf::Texture& texture, const sf::Vector2f& pos, float dimension=16);
        Enemy(b2World& world, sf::Vector2f& texturePos, const sf::Texture& texture, const sf::Vector2f&& pos, float dimension=16);
        ~Enemy();

        void update() override;
        void draw(sf::RenderWindow& window) override;
    };
}