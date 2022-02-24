#pragma once

#include <SFML/Graphics.hpp>
#include "properties.h"

/// <summary>
/// Namespace that contains the implementation for the core game
/// </summary>
namespace core
{
    /// <summary>
    /// Animation class, controls the transitions between sprite sheets states
    /// </summary>
    class Animation
    {
    private:
        animation_info              m_animInfo;
        uint32_t                    m_currentImage;
        float                       m_totalTime;

    public:
        /// <summary>
        /// Default Constructor (not used)
        /// </summary>
        Animation();

        /// <summary>
        /// Constructor
        /// </summary>
        /// <param name="animInfo">holds the information needed for the animation</param>
        Animation(animation_info animInfo);

        /// <summary>
        /// This method is called every frame and applies updates on the animation state
        /// </summary>
        /// <param name="deltaTime">the game loop delta time</param>
        /// <param name="increment">how many sprite sheets positions to skip</param>
        void update(float deltaTime, uint32_t increment);

        /// <summary>
        /// Get a new textureBox with the updated sprite sheet coordinates
        /// </summary>
        /// <returns>sf::IntRect with the new sprite positions</returns>
        sf::IntRect getTextureBox();

        /// <summary>
        /// Used to change between the animation states
        /// </summary>
        /// <param name="frameInfo">the new animation frame info</param>
        void changeAnimation(_frame_info frameInfo);

        /// <summary>
        /// Changes the idle animation, in case the character changes mid game or in selection screen
        /// </summary>
        /// <param name="idleInfo"></param>
        void changeIdleAnimation(_frame_info idleInfo) { m_animInfo.idleInfo = idleInfo; }

        animation_info getAnimInfo() const { return m_animInfo; }
    };
}