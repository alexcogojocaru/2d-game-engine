#pragma once

#include <SFML/Graphics.hpp>
#include "input_properties.h"

namespace engine
{
	namespace input
	{
		class ControllerInput
		{
		public:
			static unsigned int getPressedButton(unsigned int joystick);
		};
	}
}