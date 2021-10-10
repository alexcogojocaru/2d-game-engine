#include <SFML/Graphics.hpp>
#include "include/box2d/box2d.h"

#define TILESET_DIMENSION 16
#define SCALE 2.0f

int main()
{
    sf::RenderWindow window(sf::VideoMode(700, 700), "SFML works!");
    window.setFramerateLimit(60);

    b2Vec2 gravity(0.f, 9.8f);
    b2World world(gravity);

    b2BodyDef groundBodyDefinition;
    groundBodyDefinition.type == b2_staticBody;
    groundBodyDefinition.position.Set(0.0f, 400.0f);

    b2Body* groundBody = world.CreateBody(&groundBodyDefinition);
    b2PolygonShape groundBox;
    groundBox.SetAsBox(8.0f * SCALE , 8.0f * SCALE);

    groundBody->CreateFixture(&groundBox, 0.0f);

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(0.0f, 0.0f);

    b2Body* body = world.CreateBody(&bodyDef);

    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(8.0f * SCALE , 8.0f * SCALE);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;

    body->CreateFixture(&fixtureDef);
    float timeStep = 1.0f / 60.0f;
    int32 velocityIterations = 6;
    int32 positionIterations = 2;

    sf::Texture texture;
    if (!texture.loadFromFile("tileset.png"))
    {
        
    }

    while (window.isOpen())
    {
        sf::Event _event;
        while (window.pollEvent(_event))
        {
            if (_event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        world.Step(timeStep, velocityIterations, positionIterations);

        window.clear();

        // for (b2Body* bodyIterator = world.GetBodyList(); bodyIterator != 0; bodyIterator = bodyIterator->GetNext())
        // {
        //     if (bodyIterator->GetType() == b2_dynamicBody)
        //     {
        //         sf::Vector2f texturePosition(8, 5);
        //         sf::IntRect spriteTextureRect(texturePosition.x * TILESET_DIMENSION, texturePosition.y * TILESET_DIMENSION, 16, 16);
        //         sf::Sprite sprite(texture, spriteTextureRect);
                
        //         sprite.setScale(SCALE, SCALE);
        //         sprite.setPosition(bodyIterator->GetPosition().x, bodyIterator->GetPosition().y);
        //         sprite.setRotation(bodyIterator->GetAngle() * 180 / b2_pi);
                
        //         window.draw(sprite);
        //     }
        //     else
        //     {
        //         sf::Vector2f texturePosition(1, 1);
        //         sf::IntRect spriteTextureRect(texturePosition.x * TILESET_DIMENSION, texturePosition.y * TILESET_DIMENSION, 16, 16);
        //         sf::Sprite sprite(texture, spriteTextureRect);
            
        //         sprite.setScale(SCALE, SCALE);
        //         sprite.setPosition(bodyIterator->GetPosition().x, bodyIterator->GetPosition().y);
        //         sprite.setRotation(bodyIterator->GetAngle() * 180 / b2_pi);
                
        //         window.draw(sprite);
        //     }
        // }

        std::cout << world.GetBodyList() << std::endl;

        window.display();
    }

    return 0;
}