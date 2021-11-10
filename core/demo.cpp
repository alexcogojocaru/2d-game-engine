#include <iostream>
#include <ui/ui.h>
#include <logging/log.h>
#include <entity/player.h>

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window");
    window.setFramerateLimit(60);

    b2Vec2 gravity(0.0f, 0.0f);
    b2World world(gravity);
    
    log_info("created world with gravity=(%f, %f)", world.GetGravity().x, world.GetGravity().y);

    b2BodyDef groundBodyDefinition;
    groundBodyDefinition.type == b2_staticBody;
    groundBodyDefinition.position.Set(0.0f, 400.0f);

    b2Body* groundBody = world.CreateBody(&groundBodyDefinition);
    b2PolygonShape groundBox;
    groundBox.SetAsBox(8.0f * SCALE_FACTOR, 8.0f * SCALE_FACTOR);

    groundBody->CreateFixture(&groundBox, 0.0f);

    sf::Texture texture;
    std::string texturePath;
    std::string iconsPath;
    std::string healthIconsPath;

#ifdef __linux__
    texturePath = "/home/alex/Desktop/2d-game-engine/tileset.png";
    iconsPath = "/home/alex/Desktop/2d-game-engine/UI_Font_A.png";
    healthIconsPath = "/home/alex/Desktop/2d-game-engine/HeartSprites.png";
#else
    texturePath = "tileset.png";
    iconsPath = "UI_Font_A.png";
    healthIconsPath = "HeartSprites.png";
#endif

    if (!texture.loadFromFile(texturePath))
    {
        std::cout << "erroor" << std::endl;
    }
    std::cout << sf::Joystick::getButtonCount(0) << std::endl;

    // engine::Entity entity(sf::Vector2f(0, 0), sf::Vector2f(8, 5), world, texture);
    sf::Vector2f texturePos = sf::Vector2f(8, 5);
    core::Player player(world, texturePos, texture);

    float timeStep = 1.0f / 60.0f;
    int32 velocityIterations = 6;
    int32 positionIterations = 2;

    sf::Font font;

    if (!font.loadFromFile(PACIFICO_FONT_PATH))
    {
        std::cout << "could not load the font from the file" << std::endl;
    }

    sf::Texture iconTexture;

    if (!iconTexture.loadFromFile(iconsPath))
    {
        std::cout << "erroor" << std::endl;
    }

    sf::Vector2f iconPos = sf::Vector2f(1, 0);
    sf::Vector2f scaleIcon = sf::Vector2f(2, 2);
    sf::Vector2f positionIcon = sf::Vector2f(100, 100);

    engine::ui::Icon icon(iconTexture, iconPos);
    icon.setScale(sf::Vector2f(2, 2));
    icon.setPosition(positionIcon);

    // texture loading for hearts and mana
    sf::Texture healthTexture;
    if (!healthTexture.loadFromFile(healthIconsPath))
    {
        std::cout << "health texture error" << std::endl;
    }
    
    sf::Vector2f heartPos = sf::Vector2f(0, 0);
    sf::Vector2f heartPosition = sf::Vector2f(0, 0);

    engine::ui::Icon heartIcon1(healthTexture, heartPos, 16, 16, 16);
    heartIcon1.setScale(sf::Vector2f(4, 4));
    heartIcon1.setPosition(sf::Vector2f(0, 0));

    engine::ui::Icon heartIcon2(healthTexture, heartPos, 16, 16, 16);
    heartIcon2.setScale(sf::Vector2f(4, 4));
    heartIcon2.setPosition(sf::Vector2f(16, 0));

    engine::ui::Icon heartIcon3(healthTexture, heartPos, 16, 16, 16);
    heartIcon3.setScale(sf::Vector2f(4, 4));
    heartIcon3.setPosition(sf::Vector2f(32, 0));

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
                player.draw(window);
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

        icon.draw(window);
        heartIcon1.draw(window);
        heartIcon2.draw(window);
        heartIcon3.draw(window);
        window.display();
    }

    return 0;
}