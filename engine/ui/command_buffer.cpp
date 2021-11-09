#include "include\ui\command_buffer.h"

namespace engine
{
	namespace ui
	{
		void CommandUIBuffer::addCoords(const sf::Vector2f& point1, const sf::Vector2f& point2)
		{
			//m_coords[point1] = point2;
		}
		bool CommandUIBuffer::isButtonClicked(const sf::Vector2f& mouseCoords)
		{
			for (auto key : m_coords)
			{
				printf("%d %d\n", key.first.x, key.first.y);
			}
			return true;
		}
	}
}
