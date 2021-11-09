#pragma once

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include <input/keyboard_input.h>

#define TILESET_DIMENSION 16
#define MOVE_SPEED 50
#define SCALE_FACTOR 4

namespace e_input = engine::input;

namespace engine
{
    class Entity
    {
    private:
        sf::Sprite* m_sprite;
        sf::Vector2f m_texturePos;
        std::string m_name;
        bool m_isFacingRight;
        b2Body* body;

    public:
        Entity(const sf::Vector2f position, sf::Vector2f texturePos, b2World& world, const sf::Texture& texture);
        ~Entity();

        void setName(const std::string& name) { m_name = name; }
        void update();
        void draw(sf::RenderWindow& window);
    };
}