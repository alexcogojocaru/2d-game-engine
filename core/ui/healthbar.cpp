#include "include/gameui/healthbar.h"

namespace core
{
	std::shared_ptr<HealthBar> HealthBar::s_instance = nullptr;

	std::shared_ptr<HealthBar> HealthBar::getInstance(const sf::Texture& healthBarTexture, float totalHealth, int8_t numberOfHearts)
	{
		if (s_instance == nullptr)
		{
			s_instance = std::make_shared<HealthBar>(healthBarTexture, totalHealth, numberOfHearts);
		}

		return s_instance;
	}

	HealthBar::HealthBar(const sf::Texture& healthBarTexture, float totalHealth, int8_t numberOfHearts, float scaleFactor)
		: m_totalHealth(totalHealth)
	{
		float heart_position_x = 0;
		float heart_position_y = 0;

		for (int32_t i = 0; i < numberOfHearts; i++)
		{
			Icon icon(healthBarTexture, 0, 0, HEART_DEFAULT_WIDTH, HEART_DEFAULT_HEIGHT, HEART_DEFAULT_TILE_DIMENSION, scaleFactor);
			float scaleFactor = icon.getScaleFactor();

			icon.setPosition(sf::Vector2f(heart_position_x * scaleFactor, heart_position_y * scaleFactor));

			heart_position_x += HEART_DEFAULT_WIDTH;
			m_healthIcons.push_back(icon);
		}
	}

	void HealthBar::draw(sf::RenderWindow& window)
	{
		for (auto& icon : m_healthIcons)
		{
			icon.draw(window);
		}
	}

	void HealthBar::changePosition(sf::Vector2f pos)
	{
		float heartPosition = pos.x;
		for (auto& icon : m_healthIcons)
		{
			float scaleFactor = icon.getScaleFactor();
			icon.setPosition(sf::Vector2f(heartPosition * scaleFactor, pos.y * scaleFactor));
			heartPosition += HEART_DEFAULT_WIDTH;
		}
	}
}