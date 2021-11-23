#include "include/entity/entity.h"

namespace core
{
    Entity::Entity(b2World& world, sf::Vector2f& texturePos, const sf::Texture& texture)
    {
        textureManager = TextureManager::getInstance();

        createBody(world);

        sf::IntRect textureRect(8 * TILESET_DIMENSION, 5 * TILESET_DIMENSION, TILESET_DIMENSION, TILESET_DIMENSION);
        m_sprite = sf::Sprite(texture, textureRect);

        m_sprite.setScale(SCALE_FACTOR, SCALE_FACTOR);

        stats = { 100.0f, 10.0f };
        printf("created entity\n");

        m_outline = sf::RectangleShape(sf::Vector2f(16.0f * SCALE_FACTOR, 16.0f * SCALE_FACTOR));
		m_outline.setFillColor(sf::Color(0, 0, 0, 0));
		m_outline.setOutlineColor(sf::Color::Red);
		m_outline.setOutlineThickness(1);

        /*std::vector<sf::Vector2f> health = { constants::ICON_NUMBER_ONE, constants::ICON_NUMBER_ZERO, constants::ICON_NUMBER_ZERO };

        const sf::Texture& textureIcon = textureManager->getTexture("icons");
        m_healthIndicator = Word(health, sf::Vector2f(400, 300), textureIcon);*/
    }

    Entity::~Entity()
    {
        
    }

    void Entity::createBody(b2World& world)
    {
        b2BodyDef bodyDefinition;
        bodyDefinition.type = b2_dynamicBody;
        bodyDefinition.position.Set(400, 400);
        m_body = world.CreateBody(&bodyDefinition);

        b2PolygonShape dynamicBox;
        dynamicBox.SetAsBox(8.0f * SCALE_FACTOR, 8.0f * SCALE_FACTOR);

        b2FixtureDef fixtureDefinition;
        fixtureDefinition.shape = &dynamicBox;
        fixtureDefinition.density = 100.0f;
        fixtureDefinition.friction = 0.0f;
        fixtureDefinition.restitution = 0.9;

        m_body->CreateFixture(&fixtureDefinition);
    }

    void Entity::setPosition(const sf::Vector2f& pos)
    {

    }

    void Entity::setPosition(const sf::Vector2f&& pos)
    {
        
    }
}