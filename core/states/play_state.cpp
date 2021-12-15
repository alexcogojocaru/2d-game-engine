#include <stdio.h>
#include <gamemap/seed_generator.h>
#include "include/state/play_state.h"

namespace core
{
    PlayState::PlayState(sf::RenderWindow& window, uint32_t width, uint32_t height)
        : State(window, width, height)
    {
        const sf::Texture& healthTexture    = textureManager->getTexture(texp::HEALTH_TEXTURE);
        const sf::Texture& texture          = textureManager->getTexture("texture");

        m_healthBar = HealthBar::getInstance(healthTexture, 100.0f, 4);
        setupWorld();

        animation_info playerAnimInfo;
        playerAnimInfo.idleInfo     = MALE_DINO_IDLE;
        playerAnimInfo.runningInfo  = MALE_DINO_RUNNING;
        playerAnimInfo.dimension    = MEDIUM_DIMENSION;

        animation_info ogreAnimInfo;
        ogreAnimInfo.idleInfo      = OGRE_MONSTER_IDLE;
        ogreAnimInfo.runningInfo   = OGRE_MONSTER_RUNNING;
        ogreAnimInfo.dimension     = LARGE_DIMENSION;
        
        animation_info undeadAnimInfo;
        undeadAnimInfo.idleInfo     = UNDEAD_MONSTER_IDLE;
        undeadAnimInfo.runningInfo  = UNDEAD_MONSTER_RUNNING;
        undeadAnimInfo.dimension    = LARGE_DIMENSION;

        entity_info ogreInfo    = { ogreAnimInfo, sf::Vector2f(1000, 400) };
        entity_info undeadInfo  = { undeadAnimInfo, sf::Vector2f(700, 500) };
        entity_info playerInfo  = { playerAnimInfo, sf::Vector2f(300, 400) };

        m_player    = std::make_shared<Player>(*m_world, playerInfo, texture);
        m_enemy     = std::make_shared<Enemy>(*m_world, ogreInfo, texture, LARGE_DIMENSION);
        m_enemy0    = std::make_shared<Enemy>(*m_world, undeadInfo, texture, LARGE_DIMENSION);

        std::string seed = map::SeedGenerator::generate();

        float startX = 1;
        float startY = 1;

        map = new map::Map(*m_world, seed, sf::Vector2f(startX, startY));
        map::seed_info mapSeedInfo = map->getSeedInfo();

        //startX += 4;
        startX = startX + mapSeedInfo.width + 2;
        //startY = startY + mapSeedInfo.height + 3;

        seed = map::SeedGenerator::generate();
        //map1 = new map::Map(*m_world, seed, sf::Vector2f(startX, startY));

        dynamic_cast<Player&>(*m_player).setEnemyDebug(m_enemy0);

        m_collisionManager = new CollisionManager(m_player->getWeapon());
        m_collisionManager->subscribe(m_enemy.get());
        m_collisionManager->subscribe(m_enemy0.get());
    }

    void PlayState::setupWorld()
    {
        b2Vec2 gravity(0.0f, 0.0f);
        m_world = std::make_shared<b2World>(gravity);
    }

    void PlayState::update(float deltaTime)
    {
        sf::Event _event;
        while (window.pollEvent(_event))
        {
            switch (_event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::KeyPressed:
                if (_event.type == sf::Event::KeyPressed)
                {
                    if (_event.key.code == sf::Keyboard::Escape)
                    {
                        window.close();
                    }

                    if (_event.key.code == sf::Keyboard::F11)
                    {
                        if (!m_isFullscreen)
                        {
                            window.create(sf::VideoMode::getDesktopMode(), "title", sf::Style::Fullscreen);
                        }
                        else
                        {
                            window.create(sf::VideoMode::getDesktopMode(), "title", sf::Style::Default);
                        }

                        m_isFullscreen = !m_isFullscreen;
                    }

                    if (_event.key.code == sf::Keyboard::Space)
                    {
                        m_hasPlayerAttacked = true;
                        m_playerAttackCount = (m_playerAttackCount + 1) % 4;
                    }
                }
                break;

            case sf::Event::MouseButtonPressed:
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                log_info("%d %d", mousePos.x, mousePos.y);
                m_hasPlayerAttacked = true;

                break;
            }
        }

        m_world->Step(timeStep, velocityIterations, positionIterations);

        if (m_hasPlayerAttacked)
        {
            m_player->p_isAttacking = true;
            m_hasPlayerAttacked = false;
            m_player->p_attackCount = m_playerAttackCount;
            m_collisionManager->collide();
        }

        m_player->update(deltaTime);
        m_enemy->update(deltaTime);
        m_enemy0->update(deltaTime);
        map->update();
        //map1->update();
    }

    void PlayState::draw()
    {
        m_player->draw(window);
        m_enemy->draw(window);
        m_enemy0->draw(window);
        m_healthBar->draw(window);
        map->draw(window);
        //map1->draw(window);
    }
}