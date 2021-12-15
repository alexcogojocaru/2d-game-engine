#include <iostream>
#include <resources_pool/texture_manager.h>
#include <state/states.h>
#include <stack>

using namespace std;
using namespace engine::resources;
using namespace core;
using namespace engine;

namespace texp = core::texture_properties;

int main()
{
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "SFML Window");
    window.setFramerateLimit(60);

    sf::Cursor cursor;
    if (cursor.loadFromSystem(sf::Cursor::Cross))
        window.setMouseCursor(cursor);

    srand((unsigned int)time(NULL));

    std::map<std::string, std::string> textures = { 
        { texp::HEALTH_TEXTURE,  texp::HEALTH_TEXTURE_PATH }, 
        { texp::ICON_TEXTURE,    texp::ICON_TEXTURE_PATH }, 
        { texp::SPRITE_TEXTURE,  texp::SPRITE_TEXTURE_PATH },
        { texp::MENU_BACKGROUND_TEXTURE, texp::MENU_STATE_BACKGROUND_PATH }
    };

    std::shared_ptr<TextureManager> textureManager = TextureManager::getInstance(textures);
    std::shared_ptr<State> menuState = std::make_shared<MenuState>(window, window.getSize().x, window.getSize().y);
    std::shared_ptr<State> playState = std::make_shared<PlayState>(window, window.getSize().x, window.getSize().y);

    std::stack<std::shared_ptr<State>> states;

    states.push(playState);
    states.push(menuState);

    sf::Clock clock;
    float deltaTime;
    bool stateChange;

    std::shared_ptr<State> state = states.top();

    while (window.isOpen())
    { 
        deltaTime = clock.restart().asSeconds();

        window.clear();

        state->update(deltaTime);
        state->draw();
        window.display();
    
        stateChange = state->isTheStateChanged();
        if (stateChange)
        {
            /*states.pop();
            state = states.top();*/
            state = playState;
        }
    }

    return 0;
}
