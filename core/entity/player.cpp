#include <iostream> 
#include <input/keyboard_input.h>
#include <Candle/RadialLight.hpp>
#include "include/entity/player.h"

namespace core
{
    Player::Player(b2World& world, sf::Vector2f& texturePos, const sf::Texture& texture)
        : Entity(world, texturePos, texture)
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