#pragma once

#include <gameui/gameui.h>
#include <entity/player.h>
#include <box2d/box2d.h>
#include <gamemap/tile.h>
#include "state.h"

namespace texp=core::texture_properties;

namespace core
{
    class PlayState : public State
    {
    private:
        std::shared_ptr<HealthBar> m_healthBar;
        std::shared_ptr<Player> m_player;
        std::shared_ptr<b2World> m_world;
        map::Tile* tile;
        map::Tile* tile1;

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