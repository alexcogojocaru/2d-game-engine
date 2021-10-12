// sfml-2d.cpp : Defines the entry point for the application.
//

#include <iostream>
#include "entity.h"

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window");
    window.setFramerateLimit(60);

    b2Vec2 gravity(0.0f, 55.0f);
    b2World world(gravity);

    b2BodyDef groundBodyDefinition;
    groundBodyDefinition.type == b2_staticBody;
    groundBodyDefinition.position.Set(0.0f, 400.0f);

    b2Body* groundBody = world.CreateBody(&groundBodyDefinition);
    b2PolygonShape groundBox;
    groundBox.SetAsBox(8.0f * SCALE_FACTOR, 8.0f * SCALE_FACTOR);

    groundBody->CreateFixture(&groundBox, 0.0f);

    sf::Texture texture;
    std::string texturePath;

#ifdef __linux__
    texturePath = "/home/alex/Desktop/2d-game-engine/tileset.png";
#else
    texturePath = "D:/2d-game-engine/tileset.png";
#endif

    if (!texture.loadFromFile(texturePath))
    {
        std::cout << "erroor" << std::endl;
    }

    engine::Entity entity(sf::Vector2f(0, 0), sf::Vector2f(8, 5), world, texture);

    float timeStep = 1.0f / 60.0f;
    int32 velocityIterations = 6;
    int32 positionIterations = 2;

    while (window.isOpen())
    {
        sf::Event _event;
        while (window.pollEvent(_event))
        {
            switch (_event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::KeyPressed:
                break;
            }
        }

        world.Step(timeStep, velocityIterations, positionIterations);

        window.clear();

        for (b2Body* bodyIterator = world.GetBodyList(); bodyIterator != 0; bodyIterator = bodyIterator->GetNext())
        {
            if (bodyIterator->GetType() == b2_dynamicBody)
            {
                entity.draw(window, bodyIterator);
            }
            else
            {
                sf::Vector2f texturePosition(1, 1);
                sf::IntRect spriteTextureRect(texturePosition.x * TILESET_DIMENSION, texturePosition.y * TILESET_DIMENSION, 16, 16);
                sf::Sprite sprite(texture, spriteTextureRect);

                sprite.setScale(SCALE_FACTOR, SCALE_FACTOR);
                sprite.setPosition(bodyIterator->GetPosition().x, bodyIterator->GetPosition().y);
                sprite.setRotation(bodyIterator->GetAngle() * 180 / b2_pi);

                window.draw(sprite);
            }
        }

        window.display();
    }

    return 0;
}
