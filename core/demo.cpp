#include <iostream>
#include <ui/ui.h>
#include <logging/log.h>
#include <entity/player.h>
#include <gameui/healthbar.h>
#include <resources_pool/texture_manager.h>
#include <gameui/gameui.h>
#include <gamemap/wall.h>
#include <state/states.h>
#include <input/keyboard_input.h>

using namespace std;
using namespace engine::resources;
using namespace core;
using namespace engine;

namespace texp = core::texture_properties;

int main()
{
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "SFML Window");
    window.setFramerateLimit(60);

    std::map<std::string, std::string> textures = { 
        { texp::HEALTH_TEXTURE,  texp::HEALTH_TEXTURE_PATH }, 
        { texp::ICON_TEXTURE,    texp::ICON_TEXTURE_PATH }, 
        { texp::SPRITE_TEXTURE,  texp::SPRITE_TEXTURE_PATH } 
    };

    std::shared_ptr<TextureManager> textureManager = TextureManager::getInstance(textures);
    std::shared_ptr<State> state = std::make_shared<PlayState>(window, window.getSize().x, window.getSize().y);

    sf::Clock clock;
    float deltaTime;

    while (window.isOpen())
    { 
        deltaTime = clock.restart().asSeconds();

        window.clear();

        state->update(deltaTime);
        state->draw();
        window.display();
    }

    return 0;
}
