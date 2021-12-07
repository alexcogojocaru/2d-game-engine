#pragma once

#include "item.h"

namespace core
{
	class Collider
	{
	private:
		Drawable* m_item;

	public:
		Collider(Item* item);
	
		bool checkCollision(Drawable* object);
	};
}