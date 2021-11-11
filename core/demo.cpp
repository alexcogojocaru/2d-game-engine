#include <iostream>
#include <ui/ui.h>
#include <logging/log.h>
#include <entity/player.h>
#include <gameui/healthbar.h>
#include <resources_pool/texture_manager.h>

using namespace std;
using namespace engine::resources;

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

    std::map<std::string, std::string> textures = { {"healthIcons", healthIconsPath}, {"icons", iconsPath}, {"texture", texturePath} };
    std::shared_ptr<TextureManager> textureManager = TextureManager::getInstance(textures);

    sf::Vector2f texturePos = sf::Vector2f(8, 5);
    const sf::Texture& texture = textureManager->getTexture("texture");
    core::Player player(world, texturePos, texture);

    float timeStep = 1.0f / 60.0f;
    int32 velocityIterations = 6;
    int32 positionIterations = 2;

    sf::Vector2f iconPos = sf::Vector2f(1, 0);
    sf::Vector2f scaleIcon = sf::Vector2f(2, 2);
    sf::Vector2f positionIcon = sf::Vector2f(100, 100);

    const sf::Texture& iconTexture = textureManager->getTexture("icons");
    engine::ui::Icon icon(iconTexture, iconPos);
    icon.setScaleFactor(2.0f);
    icon.setPosition(positionIcon);

    const sf::Texture& healthTexture = textureManager->getTexture("healthIcons");

    std::shared_ptr<core::HealthBar> healthBar = core::HealthBar::getInstance(healthTexture, 100.0f, 4);

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

        healthBar->draw(window);
        window.display();
    }

    return 0;
}
