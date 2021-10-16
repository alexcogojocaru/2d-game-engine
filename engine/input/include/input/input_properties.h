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
    } // namespace input
} // namespace engine