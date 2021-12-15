#pragma once

#include <SFML/Graphics.hpp>
#include <gameui/gameui.h>
#include <resources_pool/texture_manager.h>
#include <vector>
#include <gameui/gameui.h>
#include <logging/log.h>

using namespace engine::resources;

namespace texp = core::texture_properties;

/// <summary>
/// Namespace that contains the implementation for the core game
/// </summary>
namespace core
{
	class State
	{
	protected:
		std::shared_ptr<TextureManager>		textureManager;
		std::vector<Word>					m_words;
		uint32_t							screenWidth;
		uint32_t							screenHeight;
		sf::RenderWindow&					window;

		bool								m_changeState;
		bool								m_isFullscreen;
		bool								m_hasPlayerAttacked;
		uint32_t							m_playerAttackCount;

	public:
		State(sf::RenderWindow& window, uint32_t width, uint32_t height);
		
		bool isTheStateChanged() const { return m_changeState; }

		virtual void update(float deltaTime) = 0;
		virtual void draw() = 0;
	};
}