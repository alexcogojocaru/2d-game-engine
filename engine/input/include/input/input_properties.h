#pragma once

#include <stdint.h>

/// <summary>
/// Namespace that contains the implementation for the 2d engine
/// </summary>
namespace engine
{
    /// <summary>
    /// Namespace for the input system
    /// </summary>
    namespace input
    {
        /// <summary>
        /// Struct that contains the keyboard/controller input on the x and y axis
        /// </summary>
        struct _directions
        {
            int8_t x_;
            int8_t y_;

            _directions() : x_(0), y_(0) {}
        };

        constexpr uint32_t CONTROLLER_A_BUTTON = 0x0;
        constexpr uint32_t CONTROLLER_B_BUTTON = 0x1;
        constexpr uint32_t CONTROLLER_X_BUTTON = 0x2;
        constexpr uint32_t CONTROLLER_Y_BUTTON = 0x3;

    } // namespace input
} // namespace engine