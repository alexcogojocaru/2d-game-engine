#pragma once

#include <SFML/Graphics.hpp>
#include <gameui/gameui.h>
#include <resources_pool/texture_manager.h>
#include <gameui/gameui.h>
#include <logging/log.h>
#include <vector>
#include <entity/properties.h>

using namespace engine::resources;

namespace texp = core::texture_properties;

/// <summary>
/// Namespace that contains the implementation for the core game
/// </summary>
namespace core
{
	struct frame_compact
	{
		_frame_info idle;
		_frame_info running;
	};

	class State
	{
	protected:
		std::shared_ptr<TextureManager> textureManager;
		sf::RenderWindow&				window;
		std::vector<Word>				m_words;
		uint32_t						screenWidth;
		uint32_t						screenHeight;

		bool							m_isFullscreen;
		bool							m_hasPlayerAttacked;
		uint32_t						m_playerAttackCount;

	public:
		bool changeState = false;

	public:
		State(sf::RenderWindow& window, uint32_t width, uint32_t height);
		
		virtual void update(float deltaTime);
		virtual void draw() = 0;
	};
}