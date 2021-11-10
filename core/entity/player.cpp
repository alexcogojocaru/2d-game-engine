#include <input/keyboard_input.h>
#include <iostream>
#include "include/entity/player.h"

namespace core
{
    Player::Player(b2World& world, sf::Vector2f& texturePos, const sf::Texture& texture)
        : Entity(world, texturePos, texture)
    {
        printf("created player\n");
    }

    Player::~Player()
    {

    }

    void Player::update()
    {
        engine::input::_directions moveVector = engine::input::KeyboardInput::handleInput();
        m_body->SetLinearVelocity(b2Vec2(moveVector.x_ * MOVE_SPEED, moveVector.y_ * MOVE_SPEED));
    }

    void Player::draw(sf::RenderWindow& window)
    {
        update();

        m_sprite.setPosition(m_body->GetPosition().x, m_body->GetPosition().y);
        window.draw(m_sprite);
    }
}