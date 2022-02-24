#pragma once

#include <resources_pool/texture_manager.h>
#include "seed_generator.h"
#include "wall.h"

/// <summary>
/// Namespace that contains the implementation for the core game
/// </summary>
namespace core
{
	namespace map
	{
		struct chest_powerup
		{
			sf::Vector2f position;
			std::string power;
		};

		class Map
		{
		private:
			std::vector<Wall> m_walls;
			seed_info m_seedInfo;
			b2World world;
			sf::VertexArray vertices;
			sf::Texture* texture;
			std::vector<sf::Vector2f> terrainPositions;

		public:
			std::vector<chest_powerup> chestPositions;
			unsigned int MAP_WIDTH;
			unsigned int MAP_HEIGHT;

		public:
			Map();
			Map(b2World& world, std::string seed, sf::Vector2f pos);

			seed_info getSeedInfo() const { return m_seedInfo; }

			void update();
			void draw(sf::RenderWindow& window);

			sf::Vector2f& getSpawnPosition(float widthMax, float heightMax);
		};
	}
}