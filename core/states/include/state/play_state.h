#pragma once

#include <gameui/gameui.h>
#include <entity/player.h>
#include <entity/enemy.h>
#include <items/collider.h>
#include <box2d/box2d.h>
#include <gamemap/map.h>
#include <items/item.h>
#include "state.h"

namespace texp=core::texture_properties;

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
        candle::RadialLight*        light;
        sf::VertexArray             quad;

        float timeStep = 1.0f / 60.0f;
        int32 velocityIterations = 6;
        int32 positionIterations = 2;

    private:
        void setupWorld();

    public:
        PlayState(sf::RenderWindow& window, uint32_t width, uint32_t height);

        void update(float deltaTime) override;
		void draw() override;
    
    }; // class PlayState

} // namespace core