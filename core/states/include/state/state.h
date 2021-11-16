#pragma once

#include <SFML/Graphics.hpp>
#include <gameui/gameui.h>
#include <resources_pool/texture_manager.h>
#include <vector>
#include <logging/log.h>

using namespace engine::resources;

namespace core
{
	class State
	{
	protected:
		std::vector<Word> m_words;
		uint32_t screenWidth;
		uint32_t screenHeight;

	public:
		State(uint32_t width, uint32_t height);
		
		virtual void update() = 0;
		virtual void draw(sf::RenderWindow& window) = 0;
	};
}