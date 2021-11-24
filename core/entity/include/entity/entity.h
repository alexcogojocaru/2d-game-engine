#pragma once

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include <memory>
#include <gameui/gameui.h>
#include <resources_pool/texture_manager.h>
#include "properties.h"

#define TILESET_DIMENSION 16
#define MOVE_SPEED 50
#define SCALE_FACTOR 4

using namespace engine::resources;

namespace core
{
    class Entity
    {
    protected:
        sf::Sprite m_sprite;
        sf::RectangleShape m_outline;
        sf::Vector2f m_texturePos;
        b2Body* m_body;
        entity_stats stats;
        Word m_healthIndicator;
        std::shared_ptr<TextureManager> textureManager;
        sf::Clock* m_clock;

    private:
        void createBody(b2World& world, float x, float y, float dimension);

    public:
        Entity(b2World& world, sf::Vector2f& texturePos, const sf::Texture& texture, const sf::Vector2f& pos, float dimension=16);
        Entity(b2World& world, sf::Vector2f& texturePos, const sf::Texture& texture, const sf::Vector2f&& pos, float dimension=16);
        virtual ~Entity();

        void setPosition(const sf::Vector2f&& pos);
        void setPosition(const sf::Vector2f& pos);
        void setClock(sf::Clock* clock) { m_clock = clock; }

        virtual void update() = 0;
        virtual void draw(sf::RenderWindow& window) = 0;
    };
}