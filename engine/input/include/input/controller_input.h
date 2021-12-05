#pragma once

#include <SFML/Graphics.hpp>
#include "input_properties.h"

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
		class ControllerInput
		{
		public:
			static unsigned int getPressedButton(unsigned int joystick);
		};
	}
}