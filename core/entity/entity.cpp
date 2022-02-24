#include <iostream>
#include "include/entity/entity.h"

namespace core
{
    Entity::Entity(b2World& world, entity_info entityInfo, const sf::Texture& texture, float dimension) : 
        Drawable(texture), 
        m_damageSwitchTime(0.3f),
        m_damageTotalTime(0.0f),
        m_isFacingRight(true), 
        m_animInfo(entityInfo.animInfo), 
        p_isAttacking(false), 
        p_attackCount(0),
        isDead(false)
    {
        createBody(world, entityInfo.pos.x, entityInfo.pos.y, dimension);
        m_offset = (dimension == LARGE_DIMENSION) ? LARGE_DIMENSION : 0;

        stats = { 100.0f, 250.0f, 8000 };
        stats.health = 100.0f;

        m_outline = sf::RectangleShape(sf::Vector2f(dimension * SCALE_FACTOR, dimension * SCALE_FACTOR));
		m_outline.setFillColor(sf::Color(0, 0, 0, 0));
		m_outline.setOutlineColor(sf::Color::Red);
		m_outline.setOutlineThickness(1);
        m_outline.setPosition(entityInfo.pos.x, entityInfo.pos.y);

        m_animationFrameOffset = (dimension == LARGE_DIMENSION) ? 2 : 1;
        m_animInfo = entityInfo.animInfo;

        const sf::Texture& healthTexture = TextureManager::getInstance()->getTexture(texp::HEALTH_TEXTURE);
        m_healthBar = HealthBar::getInstance(healthTexture, 100.0f, 6);
    }

    Entity::~Entity()
    {
        
    }

    void Entity::createBody(b2World& world, float x, float y, float dimension)
    {
        b2BodyDef bodyDefinition;
        bodyDefinition.type = b2_dynamicBody;
        bodyDefinition.position.Set(x, y);
        m_body = world.CreateBody(&bodyDefinition);

        b2PolygonShape dynamicBox;
        float bounding_box = dimension / 2 * SCALE_FACTOR;
        dynamicBox.SetAsBox(bounding_box, bounding_box);

        b2FixtureDef fixtureDefinition;
        fixtureDefinition.shape         = &dynamicBox;
        fixtureDefinition.density       = 100.0f;
        fixtureDefinition.friction      = 1.0f;
        fixtureDefinition.restitution   = 0.0;

        m_body->CreateFixture(&fixtureDefinition);
    }

    void Entity::animationUpdate(float deltaTime)
    {
        m_sprite.setPosition(m_body->GetPosition().x - m_offset, m_body->GetPosition().y - m_offset);
        m_outline.setPosition(m_body->GetPosition().x - m_offset, m_body->GetPosition().y - m_offset);

        lastPosition = m_sprite.getPosition().x - lastPosition;

        m_isFacingRight = (lastPosition > 0) ? true : ((lastPosition == 0) ? m_isFacingRight : false);
        if (lastPosition != 0)
        {
            m_animation.changeAnimation(m_animInfo.runningInfo);
        }
        else
        {
            m_animation.changeAnimation(m_animInfo.idleInfo);
        }
    }

    void Entity::update(float deltaTime)
    {
        m_animation.update(deltaTime, m_animationFrameOffset);
        
        sf::IntRect textureRect = m_animation.getTextureBox();
        textureRect.width       *= (m_isFacingRight) ? 1 : -1;
        textureRect.left        += (m_isFacingRight) ? 0 : m_animInfo.dimension;
        
        m_sprite.setTextureRect(textureRect);
        lastPosition = m_sprite.getPosition().x;

        if (attacked)
        {
            if (m_damageTotalTime == 0.0f)
            {
                m_sprite.setColor(sf::Color::Red);
            }

            m_damageTotalTime += deltaTime;
            if (m_damageTotalTime >= m_damageSwitchTime)
            {
                m_damageTotalTime = 0.0f;
                m_sprite.setColor(sf::Color::White);
                attacked = false;
            }
        }
    }

    void Entity::draw(sf::RenderWindow& window)
    {
        window.draw(m_sprite);
#ifdef DEBUG
        window.draw(m_outline);
#endif
    }

    void Entity::takeDamage(float deltaTime, float damage)
    {
        attacked = true;
        stats.health -= damage * deltaTime;

        if (stats.health <= 0.0f)
        {
            isDead = true;
            m_body->SetTransform(b2Vec2(200 * 64, 200 * 64), 0);
        }
    }
}