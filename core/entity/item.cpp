#include "include/entity/drawable.h"
#include "include/items/item.h"

namespace core
{
	Item::Item(b2World& world, const sf::Texture& texture, const sf::Vector2f texturePos) : 
		Drawable(texture)
	{
		float scale = 2;

		m_sprite.setTextureRect(sf::IntRect(texturePos.x * 16, texturePos.y * 16, 16, 32));
		m_sprite.setPosition(200, 300);
		m_sprite.setScale(scale, scale);
		m_sprite.setRotation(-45);

		m_outline = sf::RectangleShape(sf::Vector2f(16, 32));
		m_outline.setFillColor(sf::Color(0, 0, 0, 0));
		m_outline.setOutlineColor(sf::Color::Red);
		m_outline.setOutlineThickness(0.5);
		m_outline.setScale(scale, scale);
		m_outline.setPosition(200, 300);
		m_outline.setRotation(-45);
	}

	void Item::setOrigin(float x, float y)
	{
		m_sprite.setOrigin(sf::Vector2f(x, y));
		m_outline.setOrigin(sf::Vector2f(x, y));
	}

	void Item::setPosition(float x, float y)
	{
		m_sprite.setPosition(x, y);
		m_outline.setPosition(x, y);
	}

	void Item::rotate(float angle)
	{
		m_sprite.rotate(angle);
		m_outline.rotate(angle);
	}

	void Item::update(float deltaTime)
	{

	}

	void Item::draw(sf::RenderWindow& window)
	{
		Drawable::draw(window);
	}
}