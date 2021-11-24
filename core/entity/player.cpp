#include <iostream> 
#include <input/keyboard_input.h>
#include "include/entity/player.h"

namespace core
{
    Player::Player(b2World& world, sf::Vector2f& texturePos, const sf::Texture& texture, const sf::Vector2f& pos)
        : Entity(world, texturePos, texture, pos)
    {
        
    }

    Player::Player(b2World& world, sf::Vector2f&& texturePos, const sf::Texture& texture, const sf::Vector2f&& pos)
        : Entity(world, texturePos, texture, pos)
    {

    }

    Player::~Player()
    {

    }

    void Player::update()
    {
        sf::Time dt = m_clock->restart();

        engine::input::_directions moveVector = engine::input::KeyboardInput::handleInput();
        m_body->SetLinearVelocity(b2Vec2(moveVector.x_ * MOVE_SPEED, moveVector.y_ * MOVE_SPEED));
    }

    void Player::draw(sf::RenderWindow& window)
    {
        update();

        m_sprite.setPosition(m_body->GetPosition().x, m_body->GetPosition().y);
        m_outline.setPosition(m_body->GetPosition().x, m_body->GetPosition().y);

        window.draw(m_sprite);
        window.draw(m_outline);
        //m_healthIndicator.draw(window);
    }
}