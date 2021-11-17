#include <iostream>
#include <ui/ui.h>
#include <logging/log.h>
#include <entity/player.h>
#include <gameui/healthbar.h>
#include <resources_pool/texture_manager.h>
#include <gameui/gameui.h>
#include <gamemap/tile.h>
#include <state/states.h>

using namespace std;
using namespace engine::resources;
using namespace core;
using namespace engine;

namespace texp = core::texture_properties;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window");
    window.setFramerateLimit(60);

    std::map<std::string, std::string> textures = { 
        { texp::HEALTH_TEXTURE,  texp::HEALTH_TEXTURE_PATH }, 
        { texp::ICON_TEXTURE,    texp::ICON_TEXTURE_PATH }, 
        { texp::SPRITE_TEXTURE,  texp::SPRITE_TEXTURE_PATH } 
    };

    std::shared_ptr<TextureManager> textureManager = TextureManager::getInstance(textures);
    std::shared_ptr<State> state = std::make_shared<PlayState>(window, 800, 600);

    while (window.isOpen())
    { 
        window.clear();

        state->update();
        state->draw();
        window.display();
    }

    return 0;
}
