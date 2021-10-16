#pragma once

#include <SFML/Graphics.hpp>
#include "input_properties.h"

namespace engine
{
    namespace input
    {
        class KeyboardInput
        {
        public:
            static _directions handleInput();
        };

    } // namespace input
} // namespace engine