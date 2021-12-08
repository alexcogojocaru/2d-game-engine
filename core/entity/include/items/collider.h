#pragma once

#include "item.h"

namespace core
{
	class Collider
	{
	private:
		Drawable* m_item;

	public:
		Collider(Drawable* item);
	
		bool checkCollision(Drawable* object);
	};
}