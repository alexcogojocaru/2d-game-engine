#include <stdio.h>
#include "include/state/play_state.h"

namespace core
{
    PlayState::PlayState(sf::RenderWindow& window, uint32_t width, uint32_t height)
        : State(window, width, height)
    {
        const sf::Texture& healthTexture = textureManager->getTexture(texp::HEALTH_TEXTURE);
        m_healthBar = HealthBar::getInstance(healthTexture, 100.0f, 4);

        setupWorld();
        sf::Vector2f texturePos = sf::Vector2f(8, 5);
        const sf::Texture& texture = textureManager->getTexture("texture");
        m_player = std::make_shared<Player>(*m_world, texturePos, texture);

        /*tile = map::Wall(*m_world, 20, 1, b2Vec2(64, 64));*/
        map = new map::Map(*m_world);
        m_player->setClock(&clock);
    }

    void PlayState::setupWorld()
    {
        b2Vec2 gravity(0.0f, 0.0f);
        m_world = std::make_shared<b2World>(gravity);
    }

    void PlayState::update()
    {
        State::update();

        m_world->Step(timeStep, velocityIterations, positionIterations);

        for (b2Body* bodyIterator = m_world->GetBodyList(); bodyIterator != 0; bodyIterator = bodyIterator->GetNext())
        {
            if (bodyIterator->GetType() == b2_staticBody)
            {
                const sf::Texture& texture = textureManager->getTexture(texp::SPRITE_TEXTURE);
                sf::Vector2f texturePosition(1, 1);
                sf::IntRect spriteTextureRect(texturePosition.x * TILESET_DIMENSION, texturePosition.y * TILESET_DIMENSION, 16, 16);
                sf::Sprite sprite(texture, spriteTextureRect);

                sprite.setScale(SCALE_FACTOR, SCALE_FACTOR);
                sprite.setPosition(bodyIterator->GetPosition().x, bodyIterator->GetPosition().y);
                sprite.setRotation(bodyIterator->GetAngle() * 180 / b2_pi);

                window.draw(sprite);
            }
        }

        m_player->update();
    }

    void PlayState::draw()
    {
        m_player->draw(window);
        m_healthBar->draw(window);
        map->draw(window);
    }
}