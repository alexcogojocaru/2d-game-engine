#pragma once

#include <SFML/Graphics.hpp>

/// <summary>
/// Namespace that contains the implementation for the core game
/// </summary>
namespace core
{
    /// <summary>
    /// Animation states that an entity can transition between
    /// </summary>
    enum class AnimationState
    {
        IDLE, RUNNING
    };

    /// <summary>
    /// The primary stats that describe an entity
    /// </summary>
    struct entity_stats
    {
        float health;
        float attackDamage;
        float speed;
    };

    /// <summary>
    /// Sprite sheet information like x start and end position (_range struct) and y position
    /// </summary>
    struct _frame_info
    {
        /// <summary>
        /// 
        /// </summary>
        struct _range
        {
            float start;
            float end;
        } range;
        float y;

        inline bool operator==(_frame_info op)
        {
            return (range.start == op.range.start) && (range.end == op.range.end) && (y == op.y);
        }

        inline bool operator!=(_frame_info op)
        {
            return !this->operator==(op);
        }
    };

    enum class Gender { MALE, FEMALE };

    struct gender_anim_info
    {
        Gender gender;
        _frame_info info;
    };

    struct animation_info
    {
        _frame_info idleInfo;
        _frame_info runningInfo;
        float switchtime;
        float dimension;

        animation_info() : switchtime(0.15f) {}
    };

    struct entity_info
    {
        animation_info animInfo;
        sf::Vector2f pos;
    };

    namespace constants
    {
        constexpr float MEDIUM_DIMENSION = 16u;
        constexpr float LARGE_DIMENSION  = 32u;

        namespace players
        {
            const _frame_info FEMALE_ELF_IDLE       = { { 8, 11 }, 1 };
            const _frame_info FEMALE_ELF_RUNNING    = { { 12, 15 }, 1 };
            const _frame_info MALE_ELF_IDLE         = { { 8, 11 }, 3 };
            const _frame_info MALE_ELF_RUNNING      = { { 12, 15 }, 3 };

            const _frame_info FEMALE_KNIGHT_IDLE    = { { 8, 11 }, 5 };
            const _frame_info FEMALE_KNIGHT_RUNNING = { { 12, 15 }, 5 };
            const _frame_info MALE_KNIGHT_IDLE      = { { 8, 11 }, 7 };
            const _frame_info MALE_KNIGHT_RUNNING   = { { 12, 15 }, 7 };

            const _frame_info FEMALE_MAGE_IDLE      = { { 8, 11 }, 9 };
            const _frame_info FEMALE_MAGE_RUNNING   = { { 12, 15 }, 9 };
            const _frame_info MALE_MAGE_IDLE        = { { 8, 11 }, 11 };
            const _frame_info MALE_MAGE_RUNNING     = { { 12, 15 }, 11 };

            const _frame_info FEMALE_DINO_IDLE      = { { 8, 11 }, 13 };
            const _frame_info FEMALE_DINO_RUNNING   = { { 12, 15 }, 13 };
            const _frame_info MALE_DINO_IDLE        = { { 8, 11 }, 15 };
            const _frame_info MALE_DINO_RUNNING     = { { 12, 15 }, 15 };
        }
        
        namespace monsters
        {
            const _frame_info UNDEAD_MONSTER_IDLE    = { { 1, 4 }, 17 };
            const _frame_info OGRE_MONSTER_IDLE     = { { 1, 4 }, 20 };
            const _frame_info DEMON_MONSTER_IDLE      = { { 1, 4 }, 23 };

            const _frame_info UNDEAD_MONSTER_RUNNING = { { 7, 8 }, 17 };
            const _frame_info OGRE_MONSTER_RUNNING  = { { 7, 8 }, 20 };
            const _frame_info DEMON_MONSTER_RUNNING   = { { 7, 8 }, 23 };
        }
    }
}