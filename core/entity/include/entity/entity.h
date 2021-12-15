#pragma once

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include <memory>
#include <gameui/gameui.h>
#include <resources_pool/texture_manager.h>
#include "animation.h"
#include "drawable.h"
#include "../items/item.h"

#define TILESET_DIMENSION   16
#define MOVE_SPEED          8000
#define SWITCH_TIME         0.2f

using namespace engine::resources;
using namespace core::constants;

/// <summary>
/// Namespace that contains the implementation for the core game
/// </summary>
namespace core
{
    /// <summary>
    /// Abstract class for entities that interact on the screen (players, enemies)
    /// </summary>
    class Entity : public Drawable
    {
    protected:
        std::shared_ptr<Item>           m_weapon;
        sf::Vector2f                    m_texturePos;           // the texture position in the sprite sheet
        Animation                       m_animation;            // animation object for sprite transition
        b2Body*                         m_body;                 // box2d body for collision
        entity_stats                    stats;                  // entity's stats and properties
        animation_info                  m_animInfo;             // animation info with the entity's state
        float                           m_animationFrameOffset; // animation frame offset (how many position to skip in the sprite sheet)
        bool                            m_isFacingRight;        // the direction of the entity
        float                           lastPosition;
        float                           m_offset;
        bool                            m_hasTakenDamage;
        float                           m_damageSwitchTime;

    public:
        bool                            p_isAttacking;
        uint32_t                        p_attackCount;

    private:
        /// <summary>
        /// Creates the entity body and adds it to the box2d world
        /// </summary>
        /// <param name="world">the box2d world, previously initialized</param>
        /// <param name="x">the x axis position for the body</param>
        /// <param name="y">the y axis position for the body</param>
        /// <param name="dimension">the dimension for an edge (the body is a square shape)</param>
        void createBody(b2World& world, float x, float y, float dimension);

    protected:
        void animationUpdate(float deltaTime);

    public:
        /// <summary>
        /// Constructor
        /// </summary>
        /// <param name="world">a valid box2d world</param>
        /// <param name="entityInfo"></param>
        /// <param name="texture">a valid texture reference</param>
        /// <param name="dimension">dimension of the entity (can be MEDIUM_DIMENSION or LARGE_DIMENSION)</param>
        Entity(b2World& world, entity_info entityInfo, const sf::Texture& texture, float dimension=MEDIUM_DIMENSION);

        /// <summary>
        /// Destructor
        /// </summary>
        virtual ~Entity();

        void takeDamage() { m_hasTakenDamage = true; }
        Drawable* getWeapon() const { return m_weapon.get(); }

        /// <summary>
        /// This method is called every frame and applies updates on the entity
        /// </summary>
        /// <param name="deltaTime">the game loop delta time</param>
        void update(float deltaTime) override;

        /// <summary>
        /// Changes the entity's direction to left or right based on the argument provided
        /// </summary>
        /// <param name="right">the direction is facing</param>
        void setDirectionToRight(bool right) { m_isFacingRight = right; }
    };
}