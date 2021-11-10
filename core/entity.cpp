#include <logging/log.h>
#include "entity.h"

namespace engine
{
    Entity::Entity(const sf::Vector2f position, sf::Vector2f texturePos, b2World& world, const sf::Texture& texture)
        : m_texturePos(texturePos), m_isFacingRight(true), m_name("DEFAULT_ENTITY_NAME")
    {
        b2BodyDef bodyDefinition;

        bodyDefinition.type = b2_dynamicBody;
        bodyDefinition.position.Set(position.x, position.y);

        body = world.CreateBody(&bodyDefinition);

        b2PolygonShape dynamicBox;
        dynamicBox.SetAsBox(8.0f * SCALE_FACTOR, 8.0f * SCALE_FACTOR);

        b2FixtureDef fixtureDefinition;
        fixtureDefinition.shape = &dynamicBox;
        fixtureDefinition.density = 100.0f;
        fixtureDefinition.friction = 0.0f;
        fixtureDefinition.restitution = 0.9;

        body->CreateFixture(&fixtureDefinition);

        sf::IntRect textureRect(texturePos.x * TILESET_DIMENSION, texturePos.y * TILESET_DIMENSION, TILESET_DIMENSION, TILESET_DIMENSION);
        m_sprite = new sf::Sprite(texture, textureRect);

        m_sprite->setScale(SCALE_FACTOR, SCALE_FACTOR);

        log_info("created entity %s", m_name.c_str());
    }

    Entity::~Entity()
    {
        log_info("destroyed entity %s", m_name.c_str());
        delete m_sprite;
    }

    void Entity::update()
    {
        e_input::_directions moveVector = e_input::KeyboardInput::handleInput();

        m_isFacingRight = (moveVector.x_ < 0) ? false : true;
        body->SetLinearVelocity(b2Vec2(moveVector.x_ * MOVE_SPEED, moveVector.y_ * MOVE_SPEED));
    }

    void Entity::draw(sf::RenderWindow& window)
    {
        update();

        m_sprite->setPosition(body->GetPosition().x, body->GetPosition().y);
        window.draw(*m_sprite);
    }

} // namespace engine