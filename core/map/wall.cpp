#include <stdio.h>
#include <ctime>
#include <random>
#include "include/gamemap/wall.h"

#define SCALE_FACTOR	4
#define DIMENSION		32
#define BLOCK_DIMENSION 64.f

namespace core
{
	namespace map
	{
		std::shared_ptr<TextureManager> Wall::m_textureManager = TextureManager::getInstance();
		const uint32_t Wall::TILE_DIMENSION = 16;
	
		Wall::Wall()
		{

		}

		Wall::Wall(b2World& world, uint32_t width, uint32_t height, b2Vec2& pos)
		{
			m_textureManager = TextureManager::getInstance();
			width  *= DIMENSION;
			height *= DIMENSION;

			pos.x *= 64;
			pos.y *= 64;

			uint32_t width_minimum_factor = (width / DIMENSION - 1) * DIMENSION;
			uint32_t height_minimum_factor = (height / DIMENSION - 1) * DIMENSION;

			b2BodyDef groundBodyDefinition;
			groundBodyDefinition.type = b2_staticBody;
			groundBodyDefinition.position.Set(pos.x + width_minimum_factor, pos.y + height_minimum_factor);

			m_body = world.CreateBody(&groundBodyDefinition);
		
			b2PolygonShape groundBox;
			groundBox.SetAsBox(width, height);
			m_body->CreateFixture(&groundBox, 0.0f);

			m_outline = sf::RectangleShape(sf::Vector2f(width * 2, height * 2));
			m_outline.setPosition(pos.x, pos.y);
			m_outline.setFillColor(sf::Color::Red);

			m_vertices.setPrimitiveType(sf::Quads);
			m_vertices.resize(width * height * 4);

			float xStart = pos.x;
			float yStart = pos.y;

			for (int i = 0; i < width / DIMENSION; i++)
			{
				for (int j = 0; j < height / DIMENSION; j++)
				{
					sf::Vertex* quad = &m_vertices[(i + j * width / DIMENSION) * 4];

					quad[0].position = sf::Vector2f(xStart + i * BLOCK_DIMENSION, yStart + j * BLOCK_DIMENSION);
					quad[1].position = sf::Vector2f(xStart + (i + 1) * BLOCK_DIMENSION, yStart + j * BLOCK_DIMENSION);
					quad[2].position = sf::Vector2f(xStart + (i + 1) * BLOCK_DIMENSION, yStart + (j + 1) * BLOCK_DIMENSION);
					quad[3].position = sf::Vector2f(xStart + i * BLOCK_DIMENSION, yStart + (j + 1) * BLOCK_DIMENSION);

					double probability = (double)(rand() % 100) / 100.0;

					if (probability >= 0.5)
					{
						quad[0].texCoords = sf::Vector2f(16.f + 16.f * 1, 16.f + 16.f * 0);
						quad[1].texCoords = sf::Vector2f(32.f + 16.f * 1, 16.f + 16.f * 0);
						quad[2].texCoords = sf::Vector2f(32.f + 16.f * 1, 32.f + 16.f * 0);
						quad[3].texCoords = sf::Vector2f(16.f + 16.f * 1, 32.f + 16.f * 0);
					}
					else if (probability >= 0.3 && probability < 0.5)
					{
						quad[0].texCoords = sf::Vector2f(16.f + 16.f * 2, 16.f + 16.f * 1);
						quad[1].texCoords = sf::Vector2f(32.f + 16.f * 2, 16.f + 16.f * 1);
						quad[2].texCoords = sf::Vector2f(32.f + 16.f * 2, 32.f + 16.f * 1);
						quad[3].texCoords = sf::Vector2f(16.f + 16.f * 2, 32.f + 16.f * 1);
					}
					else
					{
						quad[0].texCoords = sf::Vector2f(16.f + 16.f * 2, 16.f + 16.f * 2);
						quad[1].texCoords = sf::Vector2f(32.f + 16.f * 2, 16.f + 16.f * 2);
						quad[2].texCoords = sf::Vector2f(32.f + 16.f * 2, 32.f + 16.f * 2);
						quad[3].texCoords = sf::Vector2f(16.f + 16.f * 2, 32.f + 16.f * 2);
					}
				}
			}

			setupWallEdges(pos, width, height);
		}

		Wall::Wall(b2World& world, uint32_t width, uint32_t height, b2Vec2&& pos)
			: Wall(world, width, height, pos)
		{

		}

		void Wall::setupWallEdges(b2Vec2& pos, uint32_t width, uint32_t height)
		{
			float start_x = pos.x;
			float start_y = pos.y;

			/*sf::Vector2f edges[] = {
				sf::Vector2f(start_x, start_y),
				sf::Vector2f(start_x + width * DIMENSION, start_y),
				sf::Vector2f(start_x + width * DIMENSION, start_y + height * DIMENSION),
				sf::Vector2f(start_x, start_y * DIMENSION) 
			};

			for (int i = 0; i < 3; i++)
			{
				candle::EdgeVector _edges;
				_edges.emplace_back(edges[i], edges[i + 1]);
				m_edges.push_back(_edges);
			}

			candle::EdgeVector _edges;
			_edges.emplace_back(edges[0], edges[3]);
			m_edges.push_back(_edges);*/

			/*candle::EdgeVector edges;
			edges.emplace_back(sf::Vector2f(start_x, start_y), sf::Vector2f(start_x, start_y * DIMENSION));
			m_edges.push_back(edges);*/
		}

		void Wall::draw(sf::RenderWindow& window)
		{
			window.draw(m_vertices, m_textureManager->getPtrTexture("texture"));
		}
	}
}