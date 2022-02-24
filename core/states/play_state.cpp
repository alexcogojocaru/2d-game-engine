#include <stdio.h>
#include <gamemap/seed_generator.h>
#include "include/state/play_state.h"

#define NUMBER_OF_MONSTERS 100
#define TARGET_ENEMIES_KILLED 20

namespace core
{
    PlayState::PlayState(sf::RenderWindow& window, uint32_t width, uint32_t height, frame_compact animInfo) :
        State(window, width, height),
        enemiesKilled(0)
    {
        const sf::Texture& healthTexture    = textureManager->getTexture(texp::HEALTH_TEXTURE);
        const sf::Texture& texture          = textureManager->getTexture(texp::SPRITE_TEXTURE);
        const sf::Texture& iconTexture      = textureManager->getTexture(texp::ICON_TEXTURE);

        setupWorld();

        animation_info playerAnimInfo;
        playerAnimInfo.idleInfo     = animInfo.idle;
        playerAnimInfo.runningInfo  = animInfo.running;

        playerAnimInfo.dimension    = MEDIUM_DIMENSION;

        animation_info ogreAnimInfo;
        ogreAnimInfo.idleInfo      = OGRE_MONSTER_IDLE;
        ogreAnimInfo.runningInfo   = OGRE_MONSTER_RUNNING;
        ogreAnimInfo.dimension     = LARGE_DIMENSION;
        
        animation_info undeadAnimInfo;
        undeadAnimInfo.idleInfo     = UNDEAD_MONSTER_IDLE;
        undeadAnimInfo.runningInfo  = UNDEAD_MONSTER_RUNNING;
        undeadAnimInfo.dimension    = LARGE_DIMENSION;

        animation_info demonAnimInfo;
        demonAnimInfo.idleInfo = DEMON_MONSTER_IDLE;
        demonAnimInfo.runningInfo = DEMON_MONSTER_RUNNING;
        demonAnimInfo.dimension = LARGE_DIMENSION;

        map = new map::Map(*m_world, "w20h10", sf::Vector2f(0, 0));

        sf::Vector2f& playerPos = map->getSpawnPosition(map->MAP_WIDTH, map->MAP_HEIGHT);
        playerPos.x *= 64;
        playerPos.y *= 64;

        entity_info playerInfo  = { playerAnimInfo, playerPos };
        m_player    = std::make_shared<Player>(*m_world, playerInfo, texture);

        sf::View view = window.getView();
        sf::Vector2f center = view.getCenter();
        b2Vec2 playerPosition = m_player->getPosition();

        view.move(sf::Vector2f(playerPosition.x - 1920 / 2, playerPosition.y - 1080 / 2));
        window.setView(view);

        entity_info ogreInfo    = { ogreAnimInfo,   sf::Vector2f(1000, 400) };
        entity_info undeadInfo  = { undeadAnimInfo, sf::Vector2f(700, 500)  };
        entity_info demonInfo   = { demonAnimInfo,  sf::Vector2f(700, 900)  };

        m_enemies.push_back(std::make_shared<Enemy>(*m_world, ogreInfo, texture, LARGE_DIMENSION));
        m_enemies.push_back(std::make_shared<Enemy>(*m_world, undeadInfo, texture, LARGE_DIMENSION));
        m_enemies.push_back(std::make_shared<Enemy>(*m_world, demonInfo, texture, LARGE_DIMENSION));

        for (int i = 0; i < NUMBER_OF_MONSTERS; i++)
        {
            int monsterType = rand() % 3;
            entity_info monsterInfo;
            monsterInfo.pos = map->getSpawnPosition(map->MAP_WIDTH, map->MAP_HEIGHT);
            monsterInfo.pos.x *= 64;
            monsterInfo.pos.y *= 64;

            monsterInfo.animInfo = (monsterType == 0) ? ogreAnimInfo : ((monsterType == 1) ? undeadAnimInfo : demonAnimInfo);

            m_enemies.push_back(std::make_shared<Enemy>(*m_world, monsterInfo, texture, LARGE_DIMENSION));
        }

        std::string seed = map::SeedGenerator::generate();

        dynamic_cast<Player&>(*m_player).setEnemiesData(&m_enemies);

        numbers = { ICON_NUMBER_ZERO, ICON_NUMBER_ONE, ICON_NUMBER_TWO, ICON_NUMBER_THREE, ICON_NUMBER_FOUR, ICON_NUMBER_FIVE, ICON_NUMBER_SIX, ICON_NUMBER_SEVEN, ICON_NUMBER_EIGHT, ICON_NUMBER_NINE };
        std::vector<sf::Vector2f> letters = { ICON_NUMBER_ZERO, ICON_NUMBER_ZERO };
        counter.push_back(Icon(iconTexture, ICON_NUMBER_ZERO));
        counter.push_back(Icon(iconTexture, ICON_NUMBER_ZERO));
        counter.push_back(Icon(iconTexture, PUNCTUATION_SLASH));
        counter.push_back(Icon(iconTexture, numbers[TARGET_ENEMIES_KILLED / 10 % 10]));
        counter.push_back(Icon(iconTexture, numbers[TARGET_ENEMIES_KILLED % 10]));

        counter[0].setPosition(playerPosition.x - center.x, playerPosition.y - center.y);
        counter[1].setPosition(playerPosition.x - center.x + 40, playerPosition.y - center.y);
        counter[2].setPosition(playerPosition.x - center.x + 40 * 2, playerPosition.y - center.y);
        counter[3].setPosition(playerPosition.x - center.x + 40 * 3, playerPosition.y - center.y);
        counter[4].setPosition(playerPosition.x - center.x + 40 * 4, playerPosition.y - center.y);

        m_initialViewCenter = window.getView().getCenter();
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
                m_playerAttackCount = (m_playerAttackCount + 1) % 4;
                break;
            }
        }

        m_world->Step(timeStep, velocityIterations, positionIterations);

        if (m_hasPlayerAttacked)
        {
            m_player->p_isAttacking = true;
            m_hasPlayerAttacked = false;
            m_player->p_attackCount = m_playerAttackCount;
        }

        sf::View view = window.getView();
        sf::Vector2f center = view.getCenter();
        b2Vec2 playerPosition = m_player->getPosition();

        float xOffsetPlayer = m_player->xOffset * deltaTime * 100;
        float yOffsetPlayer = m_player->yOffset * deltaTime * 100;

        bool isOutOfBounds_Horizontal = (center.x - (float)sf::VideoMode::getDesktopMode().width / 2) < 0.0f;
        float xOffset = (isOutOfBounds_Horizontal) ? 0.0f : xOffsetPlayer;

        bool isOutOfBounds_Vertical = (center.y - (float)sf::VideoMode::getDesktopMode().height / 2) < 0.0f;
        float yOffset = (isOutOfBounds_Vertical) ? 0.0f : yOffsetPlayer;

        xOffset = (xOffset == 0.0f && xOffsetPlayer > 0.0f) ? xOffsetPlayer : xOffset;
        yOffset = (yOffset == 0.0f && yOffsetPlayer > 0.0f) ? yOffsetPlayer : yOffset;

        view.move(xOffset, yOffset);
        window.setView(view);

        counter[0].setPosition(xOffset + counter[0].getPosition().x, yOffset + counter[0].getPosition().y);
        counter[1].setPosition(xOffset + counter[1].getPosition().x, yOffset + counter[1].getPosition().y);
        counter[2].setPosition(xOffset + counter[2].getPosition().x, yOffset + counter[2].getPosition().y);
        counter[3].setPosition(xOffset + counter[3].getPosition().x, yOffset + counter[3].getPosition().y);
        counter[4].setPosition(xOffset + counter[4].getPosition().x, yOffset + counter[4].getPosition().y);

        int firstPos = dynamic_cast<Player&>(*m_player).enemiesKilled / 10;
        int secondPos = dynamic_cast<Player&>(*m_player).enemiesKilled % 10;

        counter[0].setSprite(numbers[firstPos]);
        counter[1].setSprite(numbers[secondPos]);

        m_player->update(deltaTime);
        for (auto& enemy : m_enemies)
        {
            enemy->update(deltaTime);
        }
        map->update();

        if (dynamic_cast<Player&>(*m_player).enemiesKilled == TARGET_ENEMIES_KILLED)
        {
            changeState = true;
        }
    }

    void PlayState::draw()
    {
        map->draw(window);

        m_player->draw(window);

        for (auto& enemy : m_enemies)
        {
            enemy->draw(window);
        }

        for (auto& icon : counter)
        {
            icon.draw(window);
        }
    }
}