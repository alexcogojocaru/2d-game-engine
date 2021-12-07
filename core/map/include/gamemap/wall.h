#pragma once

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include <memory>
#include <resources_pool/texture_manager.h>

using namespace engine::resources;

/// <summary>
/// Namespace that contains the implementation for the core game
/// </summary>
namespace core
{
	namespace map
	{
		class Wall
		{
		private:
			static std::shared_ptr< TextureManager> m_textureManager;
			static const uint32_t					TILE_DIMENSION;

			sf::VertexArray						m_vertices;
			sf::RectangleShape					m_outline;
			b2Body*								m_body;

		private:
			void setupWallEdges(b2Vec2& pos, uint32_t width, uint32_t height);

		public:
			Wall();
			Wall(b2World& world, uint32_t width, uint32_t height, b2Vec2& pos);
			Wall(b2World& world, uint32_t width, uint32_t height, b2Vec2&& pos);

			void draw(sf::RenderWindow& window);
		};
	}
}