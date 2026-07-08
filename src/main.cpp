#include <iostream>
#include <SFML/Graphics.hpp>
#include <print>
#include <optional>

#include "src/core/Config.hpp"

#include "src/player/Player.hpp"
#include "src/camera/Camera.hpp"
#include "src/worldManager/blockData/BlockData.hpp"
#include "src/worldManager/WorldManager.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode({Config::windowW, Config::windowH}), "Blocks2d");
    window.setFramerateLimit(Config::windowFps);

    initBlockData();

    sf::Clock clock;

    WorldManager worldManager;
    worldManager.loadAtlasTexture("res/textures/blockAtlas.png");
    worldManager.createWorld(25);

    Player player;
    Camera camera;
    camera.setZoom(1.0f);
        
    float fpsTimer = 0.0f;
    int frameCount = 0;
    int currentFps = 0;

    while (window.isOpen()) {
        float deltaTime = clock.restart().asSeconds();

        fpsTimer += deltaTime;
        frameCount++;

        if (fpsTimer >= 1.0f) {
            currentFps = frameCount;
            frameCount = 0;
            fpsTimer = 0.0f;
            std::println("FPS: {}", currentFps);
        }

        while (const std::optional<sf::Event> event = window.pollEvent()) {
            
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }

            if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                if (keyPressed->code == sf::Keyboard::Key::F8) {
                    window.close();
                }
                if (keyPressed->code == sf::Keyboard::Key::I) {
                    camera.setZoom(camera.getZoom() + 0.1f);
                }
                if (keyPressed->code == sf::Keyboard::Key::O) {
                    camera.setZoom(camera.getZoom() - 0.1f);
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