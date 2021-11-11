#pragma once

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include <memory>
#include "properties.h"

#define TILESET_DIMENSION 16
#define MOVE_SPEED 75
#define SCALE_FACTOR 4

namespace core
{
    class Entity
    {
    protected:
        sf::Sprite m_sprite;
        sf::Vector2f m_texturePos;
        b2Body* m_body;
        entity_stats stats;

    private:
        void createBody(b2World& world);

    public:
        Entity(b2World& world, sf::Vector2f& texturePos, const sf::Texture& texture);
        virtual ~Entity();

        void setPosition(const sf::Vector2f&& pos);
        void setPosition(const sf::Vector2f& pos);

        virtual void update() = 0;
        virtual void draw(sf::RenderWindow& window) = 0;
    };
}