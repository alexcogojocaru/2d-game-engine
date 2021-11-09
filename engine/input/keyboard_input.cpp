#include "include/input/keyboard_input.h"

namespace engine
{
    namespace input
    {
        _directions KeyboardInput::handleInput()
        {
            _directions characterMovement;

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                characterMovement.x_ = 1;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                characterMovement.x_ = -1;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                characterMovement.y_ = -1;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                characterMovement.y_ = 1;
            }

            return characterMovement;
        }
    }
}