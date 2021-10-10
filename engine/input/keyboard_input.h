#pragma once

#include "abstract_keyboard_input.h"

namespace engine
{
    namespace core
    {
        class KeyboardInput : public AbstractInput
        {
        public:
            _directions handler() override
            {
                _directions input;

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                {
                    input.right = -1;
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                {
                    input.right = 1;
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                {
                    input.up = 1;
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                {
                    input.up = -1;
                }

                return input;
            }
        };
    }
}