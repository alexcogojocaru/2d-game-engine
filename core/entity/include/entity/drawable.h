#pragma once

#include <SFML/Graphics.hpp>

#define SCALE_FACTOR 3
//#define DEBUG

/// <summary>
/// Namespace that contains the implementation for the core game
/// </summary>
namespace core
{
	/// <summary>
	/// Abstract class that needs to be extended by every class that draws on screen
	/// </summary>
	class Drawable
	{
	protected:
		sf::Sprite			m_sprite;
		sf::RectangleShape  m_outline;

	public:
		/// <summary>
		/// Constructor for the class, initializes the sprite with the texture
		/// </summary>
		/// <param name="texture">a valid texture</param>
		Drawable(const sf::Texture& texture);

		/// <summary>
		/// Used to draw elements on the screen
		/// </summary>
		/// <param name="window">a valid window reference</param>
		virtual void draw(sf::RenderWindow& window);

		/// <summary>
		/// Gets the bounds of the sprite, used for collision detection
		/// </summary>
		/// <returns></returns>
		sf::FloatRect getOutlineBounds() { return m_sprite.getGlobalBounds(); }
		 
		/// <summary>
		/// Scales the object on the screen
		/// </summary>
		/// <param name="factor"></param>
		void scale(float factor) { m_sprite.scale(sf::Vector2f(factor, factor)); }

		/// <summary>
		/// Pure abstract method, updates the object's fields
		/// </summary>
		/// <param name="deltaTime">game loop's delta time</param>
		virtual void update(float deltaTime) = 0;
	};
}