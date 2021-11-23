#include <iostream>
#include <ui/ui.h>
#include <logging/log.h>
#include <entity/player.h>
#include <gameui/healthbar.h>
#include <resources_pool/texture_manager.h>
#include <gameui/gameui.h>
#include <gamemap/wall.h>
#include <state/states.h>

using namespace std;
using namespace engine::resources;
using namespace core;
using namespace engine;

namespace texp = core::texture_properties;

int main()
{
    //sf::RenderWindow window(sf::VideoMode(400, 400), "app");

    //candle::RadialLight light;
    //light.setRange(100);

    //candle::EdgeVector edges;
    //edges.emplace_back(sf::Vector2f(200, 100), sf::Vector2f(300, 100));

    //while (window.isOpen())
    //{
    //    sf::Event e;
    //    while (window.pollEvent(e))
    //    {
    //        if (e.type == sf::Event::Closed)
    //        {
    //            window.close();
    //        }

    //        if (e.type == sf::Event::MouseMoved)
    //        {
    //            sf::Vector2f mp(sf::Mouse::getPosition(window));

    //            light.setPosition(mp);
    //            //light.castLight(edges.begin(), edges.end());
    //        }
    //    }

    //    window.clear();
    //    window.draw(light);
    //    window.display();
    //}

    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "SFML Window");
    window.setFramerateLimit(60);

    std::map<std::string, std::string> textures = { 
        { texp::HEALTH_TEXTURE,  texp::HEALTH_TEXTURE_PATH }, 
        { texp::ICON_TEXTURE,    texp::ICON_TEXTURE_PATH }, 
        { texp::SPRITE_TEXTURE,  texp::SPRITE_TEXTURE_PATH } 
    };

    std::shared_ptr<TextureManager> textureManager = TextureManager::getInstance(textures);
    std::shared_ptr<State> state = std::make_shared<PlayState>(window, window.getSize().x, window.getSize().y);

    while (window.isOpen())
    { 
        if (window.hasFocus())
        {
            window.clear();

            state->update();
            state->draw();
            window.display();
        }
    }

    return 0;
}
