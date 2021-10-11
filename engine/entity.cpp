#include "entity.h"

namespace engine
{
    Entity::Entity(const sf::Vector2f position, sf::Vector2f texturePos, b2World& world, const sf::Texture& texture)
    {
        b2BodyDef bodyDefinition;

        bodyDefinition.type = b2_dynamicBody;
        bodyDefinition.position.Set(position.x, position.y);

        b2Body* body;
        body = world.CreateBody(&bodyDefinition);

        b2PolygonShape dynamicBox;
        dynamicBox.SetAsBox(8.0f * SCALE_FACTOR, 8.0f * SCALE_FACTOR);

        b2FixtureDef fixtureDefinition;
        fixtureDefinition.shape = &dynamicBox;
        fixtureDefinition.density = 100.0f;
        fixtureDefinition.friction = 0.0f;
        fixtureDefinition.restitution = 0.2;

        body->CreateFixture(&fixtureDefinition);

        sf::IntRect textureRect(texturePos.x * TILESET_DIMENSION, texturePos.y * TILESET_DIMENSION, TILESET_DIMENSION, TILESET_DIMENSION);
        m_sprite = new sf::Sprite(texture, textureRect);

        m_sprite->setScale(SCALE_FACTOR, SCALE_FACTOR);
    }

    Entity::~Entity()
    {
        delete m_sprite;
    }

    void Entity::draw(sf::RenderWindow& window, const b2Body* bodyInfo)
    {
        m_sprite->setPosition(bodyInfo->GetPosition().x, bodyInfo->GetPosition().y);
        m_sprite->setRotation(bodyInfo->GetAngle() * 180 / b2_pi);

        window.draw(*m_sprite);
    }

} // namespace engine