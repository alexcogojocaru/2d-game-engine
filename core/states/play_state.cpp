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

        tile = new map::Tile(*m_world, 320, 32, b2Vec2(64, 64));
        tile1 = new map::Tile(*m_world, 32, 224, b2Vec2(64, 128));
    }

    void PlayState::setupWorld()
    {
        b2Vec2 gravity(0.0f, 0.0f);
        m_world = std::make_shared<b2World>(gravity);
    
        // b2BodyDef groundBodyDefinition;
        // groundBodyDefinition.type = b2_staticBody;
        // groundBodyDefinition.position.Set(100.0f, 400.0f);

        // b2Body* groundBody = m_world->CreateBody(&groundBodyDefinition);
        // b2PolygonShape groundBox;
        // groundBox.SetAsBox(8.0f * SCALE_FACTOR, 8.0f * SCALE_FACTOR);

        // groundBody->CreateFixture(&groundBox, 0.0f);
    }

    void PlayState::update()
    {
        m_world->Step(timeStep, velocityIterations, positionIterations);

        sf::Event _event;
        while (window.pollEvent(_event))
        {
            switch (_event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::KeyPressed:
                break;

            case sf::Event::MouseButtonPressed:
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                log_info("%d %d", mousePos.x, mousePos.y);
                break;
            }
        }

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

                // b2Vec2 pos = bodyIterator->GetPosition();
                // printf("%f %f\n", pos.x, pos.y);

                window.draw(sprite);
            }
        }

        m_player->update();
    }

    void PlayState::draw()
    {
        m_player->draw(window);
        m_healthBar->draw(window);
        tile->draw(window);
        tile1->draw(window);
    }
}