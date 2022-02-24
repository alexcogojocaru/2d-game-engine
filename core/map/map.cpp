#include <iostream>
#include "include/gamemap/perlin.hpp"
#include "include/gamemap/map.h"

#define DIMENSION	64
#define LINES		60
#define COLUMNS		60
#define PROCESS		0.01

namespace core
{
	namespace map
	{
		const sf::Color BLUE_COLOR(35, 85, 204);
		const sf::Color WALL_COLOR(173, 82, 209);
		const sf::Color DEEP_WALL_COLOR(224, 44, 38);

		bool isIsolated(sf::RectangleShape* shapes[LINES][COLUMNS], int i, int j)
		{
			int directions = 0;
			bool isAdiacentToWall = false;

			if (i - 1 > 0 && i + 1 < LINES && j - 1 > 0 && j + 1 < COLUMNS)
			{
				if (shapes[i - 1][j]->getFillColor() == BLUE_COLOR)
				{
					directions += 1;
				}

				if (shapes[i + 1][j]->getFillColor() == BLUE_COLOR)
				{
					directions += 1;
				}

				if (shapes[i][j - 1]->getFillColor() == BLUE_COLOR)
				{
					directions += 1;
				}

				if (shapes[i][j - 1]->getFillColor() == BLUE_COLOR)
				{
					directions += 1;
				}

				// check deep walls
				if (shapes[i - 1][j]->getFillColor() == DEEP_WALL_COLOR || shapes[i - 1][j]->getFillColor() == sf::Color(221, 227, 61))
				{
					isAdiacentToWall = isAdiacentToWall || true;
				}

				if (shapes[i + 1][j]->getFillColor() == DEEP_WALL_COLOR || shapes[i + 1][j]->getFillColor() == sf::Color(221, 227, 61))
				{
					isAdiacentToWall = isAdiacentToWall || true;
				}

				if (shapes[i][j + 1]->getFillColor() == DEEP_WALL_COLOR || shapes[i][j + 1]->getFillColor() == sf::Color(221, 227, 61))
				{
					isAdiacentToWall = isAdiacentToWall || true;
				}

				if (shapes[i][j - 1]->getFillColor() == DEEP_WALL_COLOR || shapes[i][j - 1]->getFillColor() == sf::Color(221, 227, 61))
				{
					isAdiacentToWall = isAdiacentToWall || true;
				}
			}

			//return (directions >= 3) ? true : false;
			return (isAdiacentToWall) ? false : ((directions >= 3) ? true : false);
		}
		
		Map::Map(b2World& world, std::string seed, sf::Vector2f pos) : world(world)
		{
			texture = TextureManager::getInstance()->getPtrTexture("texture");
			const siv::PerlinNoise perlin { (unsigned)rand() % 100000 };
			sf::RectangleShape* shapes[LINES][COLUMNS];

			MAP_WIDTH = COLUMNS;
			MAP_HEIGHT = LINES;

			for (int x = 0; x < LINES; ++x)
			{
				for (int y = 0; y < COLUMNS; ++y)
				{
					const double noise = perlin.octave2D_01((x * DIMENSION * PROCESS), (y * DIMENSION * PROCESS), 4);
					shapes[x][y] = new sf::RectangleShape(sf::Vector2f(DIMENSION, DIMENSION));
					shapes[x][y]->setPosition(x * DIMENSION, y * DIMENSION);

					if (noise < 0.3)
					{
						shapes[x][y]->setFillColor(DEEP_WALL_COLOR); // Deep Wall
					}
					else if (noise >= 0.3 && noise < 0.5)
					{
						shapes[x][y]->setFillColor(sf::Color(221, 227, 61)); // Close Wall
					}
					else
					{
						shapes[x][y]->setFillColor(sf::Color(35, 85, 204)); // Terrain
						terrainPositions.push_back(sf::Vector2f(x, y));
					}
				}
			}

			for (int i = 0; i < LINES; i++)
			{
				for (int j = 0; j < COLUMNS; j++)
				{
					bool check = false;
					bool verticalCheck = false;
					bool horizontalCheck = false;

					if (shapes[i][j]->getFillColor() != BLUE_COLOR)
					{
						if (i - 1 > 0 && shapes[i - 1][j]->getFillColor() == BLUE_COLOR)
						{
							check = true;
							horizontalCheck = true;
						}

						if (i + 1 < LINES && shapes[i + 1][j]->getFillColor() == BLUE_COLOR)
						{
							check = true;
							horizontalCheck &= true;
						}

						if (j - 1 > 0 && shapes[i][j - 1]->getFillColor() == BLUE_COLOR)
						{
							check = true;
							verticalCheck = true;
						}

						if (j + 1 < COLUMNS && shapes[i][j + 1]->getFillColor() == BLUE_COLOR)
						{
							check = true;
							verticalCheck &= true;
						}

						if (check)
						{
							shapes[i][j]->setFillColor(WALL_COLOR);
						}
					}
				}
			}

			for (int i = 0; i < LINES; i++)
			{
				for (int j = 0; j < COLUMNS; j++)
				{
					if (shapes[i][j]->getFillColor() == WALL_COLOR)
					{
						if (isIsolated(shapes, i, j))
						{
							shapes[i][j]->setFillColor(sf::Color(50, 168, 82));
						}
					}
				}
			}

			vertices.setPrimitiveType(sf::Quads);
			vertices.resize(LINES * COLUMNS * 4);

			for (int i = 0; i < COLUMNS; i++)
			{
				for (int j = 0; j < LINES; j++)
				{
					sf::Vertex* quad = &vertices[(i + j * COLUMNS) * 4];
					sf::Vector2f pos = shapes[j][i]->getPosition();

					quad[0].position = pos;
					quad[1].position = sf::Vector2f(pos.x + DIMENSION, pos.y);
					quad[2].position = sf::Vector2f(pos.x + DIMENSION, pos.y + DIMENSION);
					quad[3].position = sf::Vector2f(pos.x, pos.y + DIMENSION);

					if (shapes[j][i]->getFillColor() == BLUE_COLOR)
					{
						double probability = (double)(rand() % 100) / 100.0;

						if (probability >= 0.5 && probability < 0.7)
						{
							quad[0].texCoords = sf::Vector2f(16.f + 16.f * 1, 16.f + 16.f * 3);
							quad[1].texCoords = sf::Vector2f(32.f + 16.f * 1, 16.f + 16.f * 3);
							quad[2].texCoords = sf::Vector2f(32.f + 16.f * 1, 32.f + 16.f * 3);
							quad[3].texCoords = sf::Vector2f(16.f + 16.f * 1, 32.f + 16.f * 3);
						}
						else
						{
							quad[0].texCoords = sf::Vector2f(16.f + 16.f * 0, 16.f + 16.f * 3);
							quad[1].texCoords = sf::Vector2f(32.f + 16.f * 0, 16.f + 16.f * 3);
							quad[2].texCoords = sf::Vector2f(32.f + 16.f * 0, 32.f + 16.f * 3);
							quad[3].texCoords = sf::Vector2f(16.f + 16.f * 0, 32.f + 16.f * 3);
						}


					}
					else if (shapes[j][i]->getFillColor() == WALL_COLOR)
					{
						quad[0].texCoords = sf::Vector2f(16.f + 16.f * 1, 16.f + 16.f * 0);
						quad[1].texCoords = sf::Vector2f(32.f + 16.f * 1, 16.f + 16.f * 0);
						quad[2].texCoords = sf::Vector2f(32.f + 16.f * 1, 32.f + 16.f * 0);
						quad[3].texCoords = sf::Vector2f(16.f + 16.f * 1, 32.f + 16.f * 0);

						b2BodyDef groundBodyDefinition;
						groundBodyDefinition.type = b2_staticBody;
						groundBodyDefinition.position.Set(pos.x, pos.y);

						b2Body* body = world.CreateBody(&groundBodyDefinition);

						b2PolygonShape groundBox;
						groundBox.SetAsBox(32, 32);
						body->CreateFixture(&groundBox, 0.0f);
					}
					else if (shapes[j][i]->getFillColor() == sf::Color(221, 227, 61))
					{
						quad[0].texCoords = sf::Vector2f(16.f + 16.f * 2, 16.f + 16.f * 1);
						quad[1].texCoords = sf::Vector2f(32.f + 16.f * 2, 16.f + 16.f * 1);
						quad[2].texCoords = sf::Vector2f(32.f + 16.f * 2, 32.f + 16.f * 1);
						quad[3].texCoords = sf::Vector2f(16.f + 16.f * 2, 32.f + 16.f * 1);
					}
					else if (shapes[j][i]->getFillColor() == sf::Color(50, 168, 82))
					{
						double probability = (double)(rand() % 100) / 100.0;

						if (probability < 0.1)
						{
							// chest
							int powerupProb = rand() % 4;
							std::string power;

							switch (powerupProb)
							{
							case 0:
								power = "DAMAGE_DOWN";
								break;
							case 1:
								power = "DAMAGE_UP";
								break;
							case 2:
								power = "SPEED_DOWN";
								break;
							case 3:
								power = "SPEED_UP";
							}

							chestPositions.push_back({ sf::Vector2f(j * 64, i * 64), power });

							quad[0].texCoords = sf::Vector2f(16.f + 16.f * 20, 16.f + 16.f * 18);
							quad[1].texCoords = sf::Vector2f(32.f + 16.f * 20, 16.f + 16.f * 18);
							quad[2].texCoords = sf::Vector2f(32.f + 16.f * 20, 32.f + 16.f * 18);
							quad[3].texCoords = sf::Vector2f(16.f + 16.f * 20, 32.f + 16.f * 18);
						}
						else
						{
							quad[0].texCoords = sf::Vector2f(16.f + 16.f * 0, 16.f + 16.f * 3);
							quad[1].texCoords = sf::Vector2f(32.f + 16.f * 0, 16.f + 16.f * 3);
							quad[2].texCoords = sf::Vector2f(32.f + 16.f * 0, 32.f + 16.f * 3);
							quad[3].texCoords = sf::Vector2f(16.f + 16.f * 0, 32.f + 16.f * 3);
						}
					}
				}
			}
		}

		void Map::update()
		{

		}

		void Map::draw(sf::RenderWindow& window)
		{
			window.draw(vertices, texture);
		}

		sf::Vector2f& Map::getSpawnPosition(float widthMax, float heightMax)
		{
			int pos; // = rand() % terrainPositions.size();
			bool foundPosition = false;

			while (!foundPosition)
			{
				pos = rand() % terrainPositions.size();
				if ((terrainPositions[pos].x > 14 && terrainPositions[pos].y > 14) && (terrainPositions[pos].x < widthMax - 14 && terrainPositions[pos].y < heightMax - 14))
				{
					foundPosition = true;
				}
			}
			
			return std::ref(terrainPositions[pos]);
		}
	}
}