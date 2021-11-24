#include <iostream>
#include "include/entity/enemy.h"

namespace core
{
    Enemy::Enemy(b2World& world, sf::Vector2f& texturePos, const sf::Texture& texture, const sf::Vector2f& pos, float dimension)
        : Entity(world, texturePos, texture, pos, dimension)
    {
        m_offset = (dimension == 32) ? 32 : 0;
    }

    Enemy::Enemy(b2World& world, sf::Vector2f& texturePos, const sf::Texture& texture, const sf::Vector2f&& pos, float dimension)
        : Entity(world, texturePos, texture, pos, dimension)
    {

    }

    Enemy::~Enemy()
    {

    }

    void Enemy::update()
    {
        m_sprite.setPosition(m_body->GetPosition().x, m_body->GetPosition().y);
        m_outline.setPosition(m_body->GetPosition().x - m_offset, m_body->GetPosition().y - m_offset);
    }

    void Enemy::draw(sf::RenderWindow& window)
    {
        update();

        window.draw(m_sprite);
        window.draw(m_outline);
    }
}