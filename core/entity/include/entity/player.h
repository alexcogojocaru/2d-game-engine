#pragma once

#include "entity.h"
#include "animation.h"
#include "../items/weapon.h"
#include "../items/collider.h"

using namespace core::constants::players;

/// <summary>
/// Namespace that contains the implementation for the core game
/// </summary>
namespace core
{
    /// <summary>
    /// Player class, controls the player actions
    /// </summary>
    class Player : public Entity
    {
    private:
        std::shared_ptr<Item>       m_weapon;
        std::unique_ptr<Collider>   m_collider;
        entity_info                 m_info;
        bool                        m_hasAttackStarted;
        float                       m_attackTotalTime;
        uint32_t                    m_numberOfRotations;
        std::shared_ptr<Entity>     m_testEnemy;

    public:
        /// <summary>
        /// Constructor
        /// </summary>
        /// <param name="world">a valid box2d world</param>
        /// <param name="texturePos">texture position in the sprite sheet</param>
        /// <param name="texture">a valid texture reference</param>
        /// <param name="pos">position of the entity on the screen</param>
        Player(b2World& world, entity_info entityInfo, const sf::Texture& texture);

        /// <summary>
        /// Calls the previous constructor (this one has a r-value reference for player position)
        /// </summary>
        //Player(b2World& world, sf::Vector2f&& texturePos, const sf::Texture& texture, const sf::Vector2f&& pos);
        
        /// <summary>
        /// This method is called every frame and applies updates on the player
        /// </summary>
        /// <param name="deltaTime">the game loop delta time</param>
        void update(float deltaTime) override;

        void setEnemyDebug(std::shared_ptr<Entity> enemy) { m_testEnemy = enemy; }

        void attack(float deltaTime);

        void draw(sf::RenderWindow& window) override;
    };
}