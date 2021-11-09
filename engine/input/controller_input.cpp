#include "include/input/controller_input.h"

namespace engine
{
	namespace input
	{
		unsigned int ControllerInput::getPressedButton(unsigned int joystick)
		{
			unsigned int button;

			if (sf::Joystick::isButtonPressed(joystick, CONTROLLER_A_BUTTON))
			{
				button = CONTROLLER_A_BUTTON;
			}

			return button;
		}
	}
}