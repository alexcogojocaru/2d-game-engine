#pragma once

#include "entity.h"
#include "../items/collider.h"

namespace core
{
	class CollisionManager
	{
	private:
		std::unique_ptr<Collider>	m_targetCollider;
		std::vector<Entity*>		m_entities;

	public:
		CollisionManager(Drawable* target);
	
		void subscribe(Entity* entity);
		void collide();
	};
}