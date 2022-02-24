#include <iostream> 
#include <input/keyboard_input.h>
#include "include/entity/player.h"

namespace core
{
    Player::Player(b2World& world, entity_info entityInfo, const sf::Texture& texture) : 
        Entity(world, entityInfo, texture),
        m_info(entityInfo), 
        m_hasAttackStarted(false), 
        m_attackTotalTime(0.0f), 
        m_numberOfRotations(0)
    {
        m_animation = Animation(entityInfo.animInfo);
        m_weapon = std::make_shared<Weapon>(world, texture, sf::Vector2f(18, 11));

        sf::Vector2f weaponPos = m_weapon->getSize();
        m_weapon->setOrigin(weaponPos.x * 0.5f, weaponPos.y * 0.9);

        m_collider = std::make_unique<Collider>(m_weapon.get());
    }

    void Player::update(float deltaTime)
    {
        Entity::update(deltaTime);

        engine::input::_directions moveVector = engine::input::KeyboardInput::handleInput();
        m_body->SetLinearVelocity(b2Vec2(moveVector.x_ * stats.speed * deltaTime, moveVector.y_ * stats.speed * deltaTime));

        xOffset = moveVector.x_;
        yOffset = moveVector.y_;

        Entity::animationUpdate(deltaTime);

        attack(deltaTime);
        m_weapon->setPosition(m_body->GetPosition().x + 32, m_body->GetPosition().y + 32);
    }

    void Player::attack(float deltaTime)
    {
        if (p_isAttacking)
        {    
            m_attackTotalTime += deltaTime;
            m_weapon->rotate(5);
            m_numberOfRotations += 5;

            if (enemies)
            {
                for (auto& enemy : *enemies)
                {
                    bool hasCollided = m_collider->checkCollision(enemy.get());
                    if (hasCollided)
                    {
                        enemy->takeDamage(deltaTime, stats.attackDamage);
                        if (enemy->isDead)
                        {
                            enemiesKilled++;
                        }
                    }
                }
            }

            if (m_numberOfRotations == 135)
            {
                p_isAttacking = false;
                m_weapon->rotate(-135);
                m_numberOfRotations = 0;
            }
        }
    }

    void Player::draw(sf::RenderWindow& window)
    {
        Drawable::draw(window);
        m_weapon->draw(window);
        //m_healthBar->draw(window);
    }
}