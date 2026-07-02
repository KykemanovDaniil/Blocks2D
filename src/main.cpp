#include <iostream>
#include <SFML/Graphics.hpp>
#include <print>

#include "core/Config.hpp"

#include "player/Player.hpp"
#include "camera/Camera.hpp"
#include "worldManager/blockData/BlockData.hpp"
#include "worldManager/WorldManager.hpp"

constexpr int CHUNKS = 5;

int main() {
    sf::RenderWindow window(sf::VideoMode({Config::windowW, Config::windowH}), "Blocks2d");
    window.setFramerateLimit(60);

    initBlockData();

    sf::Clock clock;

    WorldManager worldManager;
    worldManager.loadAtlasTexture("res/textures/blockAtlas.png");
    worldManager.createWorld(15);

    Player player;
    Camera camera;
    camera.setZoom(1.0f);
    
    while (window.isOpen()) {
        float deltaTime = clock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::F8) {
                    window.close();
                }
            }
        }

        player.update(deltaTime);
        camera.updateLerp(player.getPosition(), deltaTime);

        // RENDER

        window.clear(sf::Color{82, 176, 255, 255});

        camera.setView(window);

        worldManager.draw(window);

        player.draw(window);

        window.display();
    }

    return 0;
}