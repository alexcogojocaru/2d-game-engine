#include "include/entity/collision_manager.h"

namespace core
{
	CollisionManager::CollisionManager(Drawable* target)
	{
		m_targetCollider = std::make_unique<Collider>(target);
	}

	void CollisionManager::subscribe(Entity* entity)
	{
		m_entities.push_back(entity);
	}

	void CollisionManager::collide()
	{
		for (auto& entity : m_entities)
		{
			bool hasCollided = m_targetCollider->checkCollision(entity);
			if (hasCollided)
			{
				printf("collided\n");
				entity->setColor(sf::Color::Red);
				entity->takeDamage();
			}
		}
	}
}