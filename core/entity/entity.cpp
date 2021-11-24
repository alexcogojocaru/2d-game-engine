#include <iostream>
#include "include/entity/entity.h"

namespace core
{
    Entity::Entity(b2World& world, sf::Vector2f& texturePos, const sf::Texture& texture, const sf::Vector2f& pos, float dimension)
    {
        textureManager = TextureManager::getInstance();
        createBody(world, pos.x, pos.y, dimension);

        sf::IntRect textureRect(texturePos.x * 16, texturePos.y * 16, dimension, dimension);
        m_sprite = sf::Sprite(texture, textureRect);

        m_sprite.setScale(SCALE_FACTOR, SCALE_FACTOR);

        stats = { 100.0f, 10.0f };
        printf("created entity\n");

        m_outline = sf::RectangleShape(sf::Vector2f(dimension * SCALE_FACTOR, dimension * SCALE_FACTOR));
		m_outline.setFillColor(sf::Color(0, 0, 0, 0));
		m_outline.setOutlineColor(sf::Color::Red);
		m_outline.setOutlineThickness(1);
        m_outline.setPosition(pos.x, pos.y);

        /*std::vector<sf::Vector2f> health = { constants::ICON_NUMBER_ONE, constants::ICON_NUMBER_ZERO, constants::ICON_NUMBER_ZERO };

        const sf::Texture& textureIcon = textureManager->getTexture("icons");
        m_healthIndicator = Word(health, sf::Vector2f(400, 300), textureIcon);*/
    }

    Entity::Entity(b2World& world, sf::Vector2f& texturePos, const sf::Texture& texture, const sf::Vector2f&& pos, float dimension)
        : Entity(world, texturePos, texture, pos)
    {

    }

    Entity::~Entity()
    {
        
    }

    void Entity::createBody(b2World& world, float x, float y, float dimension)
    {
        float offset = (dimension == 32) ? 0 : 0;
        b2BodyDef bodyDefinition;
        bodyDefinition.type = (dimension == 32) ? b2_staticBody : b2_dynamicBody;
        bodyDefinition.position.Set(x + offset, y + offset);
        m_body = world.CreateBody(&bodyDefinition);

        b2PolygonShape dynamicBox;
        float bounding_box = dimension / 2 * SCALE_FACTOR;

        dynamicBox.SetAsBox(bounding_box, bounding_box);

        b2FixtureDef fixtureDefinition;
        fixtureDefinition.shape = &dynamicBox;
        fixtureDefinition.density = 100.0f;
        // fixtureDefinition.friction = 0.0f;
        // fixtureDefinition.restitution = 0.0;

        m_body->CreateFixture(&fixtureDefinition);
    }

    void Entity::setPosition(const sf::Vector2f& pos)
    {

    }

    void Entity::setPosition(const sf::Vector2f&& pos)
    {
        
    }
}