#include "include/items/collider.h"

namespace core
{
	Collider::Collider(Drawable* item) :
		m_item(item)
	{

	}

	bool Collider::checkCollision(Drawable* object)
	{
		return m_item->getOutlineBounds().intersects(object->getOutlineBounds());
	}
}