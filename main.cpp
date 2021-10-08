#include <SFML/Graphics.hpp>
#include "include/box2d/box2d.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    window.setFramerateLimit(60);

    // b2Vec2 gravity(0.0f, 9.8f);
    // b2World world(gravity);

    while (window.isOpen())
    {
        // world.Step(1.0f / 60.0f, 6, 2);

        window.clear();
        window.display();
    }

    return 0;
}