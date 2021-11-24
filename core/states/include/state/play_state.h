#pragma once

#include <gameui/gameui.h>
#include <entity/player.h>
#include <entity/enemy.h>
#include <box2d/box2d.h>
#include <gamemap/map.h>
#include "state.h"

namespace texp=core::texture_properties;

namespace core
{
    class PlayState : public State
    {
    private:
        std::shared_ptr<HealthBar> m_healthBar;
        std::shared_ptr<Entity> m_player;
        std::shared_ptr<Entity> m_enemy;
        std::shared_ptr<b2World> m_world;
        sf::Clock clock;
        map::Map* map;

        float timeStep = 1.0f / 60.0f;
        int32 velocityIterations = 6;
        int32 positionIterations = 2;

    private:
        void setupWorld();

    public:
        PlayState(sf::RenderWindow& window, uint32_t width, uint32_t height);

        void update() override;
		void draw() override;
    
    }; // class PlayState

} // namespace core