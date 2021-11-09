#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>

namespace engine
{
	namespace ui
	{
		class CommandUIBuffer
		{
		private:
			std::unordered_map<sf::Vector2f, sf::Vector2f> m_coords;
		
		public:
			void addCoords(const sf::Vector2f& point1, const sf::Vector2f& point2);
			bool isButtonClicked(const sf::Vector2f& mouseCoords);
		};
	}
}