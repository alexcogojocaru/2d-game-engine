#pragma once

#include <SFML/Graphics.hpp>
#include <ui/ui.h>
#include <memory>
#include <vector>
#include <iostream>

using namespace engine::ui;

namespace core
{
	constexpr int32_t HEART_DEFAULT_WIDTH			= 16;
	constexpr int32_t HEART_DEFAULT_HEIGHT			= 16;
	constexpr int32_t HEART_DEFAULT_TILE_DIMENSION	= 16;
	
	class HealthBar : public Drawable
	{
	private:
		static std::shared_ptr<HealthBar> s_instance;
		std::vector<Icon> m_healthIcons;
		float m_totalHealth;

	public:
		HealthBar(const sf::Texture& healthBarTexture, float totalHealth, int8_t numberOfHearts);

		static std::shared_ptr<HealthBar> getInstance(const sf::Texture& healthBarTexture, float totalHealth, int8_t numberOfHearts);
		void draw(sf::RenderWindow& window) override;
	};
}