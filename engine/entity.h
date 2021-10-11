#pragma once

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>

#define TILESET_DIMENSION 16
#define SCALE_FACTOR 4

namespace engine
{
    class Entity
    {
    private:
        sf::Sprite* m_sprite;

    public:
        Entity(const sf::Vector2f position, sf::Vector2f texturePos, b2World& world, const sf::Texture& texture);
        ~Entity();

        void draw(sf::RenderWindow& window, const b2Body* bodyInfo);
    };
}