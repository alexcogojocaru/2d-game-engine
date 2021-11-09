#pragma once

#include <stdint.h>

namespace engine
{
    namespace input
    {
        struct _directions
        {
            int8_t x_;
            int8_t y_;

            _directions() : x_(0), y_(0) {}
        };

#define CONTROLLER_A_BUTTON 0x0
#define CONTROLLER_B_BUTTON 0x1
#define CONTROLLER_X_BUTTON 0x2
#define CONTROLLER_Y_BUTTON 0x3

    } // namespace input
} // namespace engine