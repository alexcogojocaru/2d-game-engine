#include "include/state/state.h"

namespace core
{
	State::State(sf::RenderWindow& window, uint32_t width, uint32_t height)
		: screenWidth(width), screenHeight(height), window(window)
	{
		textureManager = TextureManager::getInstance();
	}
}