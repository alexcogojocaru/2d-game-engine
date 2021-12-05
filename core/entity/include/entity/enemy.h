#pragma once

#include "entity.h"
#include "animation.h"

using namespace core::constants::monsters;

/// <summary>
/// Namespace that contains the implementation for the core game
/// </summary>
namespace core
{
    /// <summary>
    /// Enemy class, describes the enemy actions
    /// </summary>
    class Enemy : public Entity
    {  
    public:
        /// <summary>
        /// Constructor
        /// </summary>
        /// <param name="world">a valid box2d world</param>
        /// <param name="texturePos">texture position in the sprite sheet</param>
        /// <param name="texture">a valid texture reference</param>
        /// <param name="pos">position of the entity on the screen</param>
        /// <param name="dimension">dimension of the entity</param>
        Enemy(b2World& world, entity_info entityInfo, const sf::Texture& texture, float dimension);
        
        /// <summary>
        /// This method is called every frame and applies updates on the enemy
        /// </summary>
        /// <param name="deltaTime">the game loop delta time</param>
        void update(float deltaTime) override;
    };
}