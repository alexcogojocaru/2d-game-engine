#pragma once

#include <entity/player.h>
#include <entity/enemy.h>
#include <items/collider.h>
#include <box2d/box2d.h>
#include <gamemap/map.h>
#include <items/item.h>
#include <set>
#include "state.h"

/// <summary>
/// Namespace that contains the implementation for the core game
/// </summary>
namespace core
{
    class PlayState : public State
    {
    private:
        std::shared_ptr<HealthBar>  m_healthBar;
        std::shared_ptr<Entity>     m_player;
        std::shared_ptr<Entity>     m_enemy;
        std::shared_ptr<Entity>     m_enemy0;
        std::shared_ptr<b2World>    m_world;
        std::shared_ptr<Item>       m_item;
        map::Map*                   map;
        sf::VertexArray             quad;
        sf::Vector2f                m_initialViewCenter;
        std::vector <std::shared_ptr<Entity>> m_enemies;
        std::set<std::shared_ptr<Entity>> scheduledForDestroying;

        float timeStep              = 1.0f / 60.0f;
        int32 velocityIterations    = 6;
        int32 positionIterations    = 2;

        std::vector<Icon> counter;
        unsigned int enemiesKilled = 0;

        unsigned int mapWidth;
        unsigned int mapHeight;

        std::vector<sf::Vector2f> numbers;

    private:
        void setupWorld();

    public:
        PlayState(sf::RenderWindow& window, uint32_t width, uint32_t height, frame_compact animInfo);

        void update(float deltaTime) override;
		void draw() override;
    
    }; // class PlayState

} // namespace core