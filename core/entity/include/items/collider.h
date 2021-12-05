#pragma once

#include "item.h"

namespace core
{
	class Collider
	{
	private:
		Item* m_item;

	public:
		Collider(Item* item);
	
		template <typename T>
		void checkCollision(T* object)
		{
			if (m_item->getOutlineBounds().intersects(object->getOutlineBounds()))
			{
				printf("collided\n");
			}
		}
	};
}