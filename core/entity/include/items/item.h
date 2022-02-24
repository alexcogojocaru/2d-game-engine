#pragma once

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include <resources_pool/texture_manager.h>
#include "../entity/drawable.h"

/// <summary>
/// Namespace that contains the implementation for the core game
/// </summary>
namespace core
{
	class Item : public Drawable
	{
	private:
		b2Body* m_body;

	public:
		Item(b2World& world, const sf::Texture& texture, const sf::Vector2f texturePos);
		
		void setPosition(float x, float y);
		void setOrigin(float x, float y);
		void rotate(float angle);

		sf::Vector2f getSize() const { return sf::Vector2f(m_sprite.getTextureRect().width, m_sprite.getTextureRect().height); }

		virtual void update(float deltaTime);
		virtual void draw(sf::RenderWindow& window);
	};
}