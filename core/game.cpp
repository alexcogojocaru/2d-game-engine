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
    window.setFramerateLimit(144);

    sf::View playerView(sf::Vector2f(1920 / 2, 1080 / 2), sf::Vector2f(1920, 1080));
    window.setView(playerView);

    srand((unsigned int)time(NULL));

    std::map<std::string, std::string> textures = {
        {
            texp::HEALTH_TEXTURE,
            texp::HEALTH_TEXTURE_PATH
        },
        {
            texp::ICON_TEXTURE,
            texp::ICON_TEXTURE_PATH
        },
        {
            texp::SPRITE_TEXTURE,
            texp::SPRITE_TEXTURE_PATH
        },
        {
            texp::MENU_BACKGROUND_TEXTURE,
            texp::MENU_STATE_BACKGROUND_PATH
        }
    };

    std::shared_ptr<TextureManager> textureManager = TextureManager::getInstance(textures);

    std::vector<std::shared_ptr<State>> states;
    std::shared_ptr<State> state = std::make_shared<MenuState>(window, window.getSize().x, window.getSize().y);
    int count = 1;

    sf::Clock clock;
    float deltaTime;
    frame_compact info;

    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();

        window.clear(sf::Color(39, 45, 56));

        state->update(deltaTime);
        state->draw();
        window.display();

        if (state->changeState)
        {
            state->changeState = false;
            if (count == 1)
            {
                state = std::make_shared<SelectionState>(window, window.getSize().x, window.getSize().y);
            }

            if (count == 2)
            {
                info = dynamic_cast<SelectionState&>(*state).getAnimInfo();
                state = std::make_shared<PlayState>(window, window.getSize().x, window.getSize().y, info);
            }

            if (count == 3)
            {
                printf("changed to endstate\n");
                state = std::make_shared<EndState>(window, window.getSize().x, window.getSize().y);
            }

            count++;
        }
    }

    return 0;
}
