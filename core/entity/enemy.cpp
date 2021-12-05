#include "include/entity/enemy.h"

namespace core
{
    Enemy::Enemy(b2World& world, entity_info entityInfo, const sf::Texture& texture, float dimension) : 
        Entity(world, entityInfo, texture, dimension)
    {
        m_animation = Animation(entityInfo.animInfo);
    }

    void Enemy::update(float deltaTime)
    {
        Entity::update(deltaTime);
        Entity::animationUpdate(deltaTime);
    }
}