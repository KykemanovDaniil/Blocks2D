#include <iostream>
#include <SFML/Graphics.hpp>

#include "core/Config.hpp"

#include "world/World.hpp"
#include "player/Player.hpp"
#include "camera/Camera.hpp"

constexpr int CHUNKS = 3;

int main() {
    sf::RenderWindow window(sf::VideoMode({Config::windowW, Config::windowH}), "Blocks2d");
    window.setFramerateLimit(60);

    if (!Terrain::blockAtlas.loadFromFile("res/textures/blockAtlas.png")) {
        std::cerr << "LOAD FAILED : Terrain::blockAtlas";
    }

    std::vector<Terrain::Chunk> worldChunks;

    for (int i = -CHUNKS; i < CHUNKS; ++i) {
        Terrain::Chunk newChunk;
        Terrain::initChunk(newChunk, i);
        Terrain::updateChunkMesh(newChunk);

        worldChunks.push_back(newChunk);
    }

    Player player;
    player.spawnOnSurface(10, worldChunks);

    Camera camera;
    camera.setSize({Config::windowW, Config::windowH});
    camera.setCenter(player.position);
    camera.setZoom(1.0f);
    camera.setLerp(0.08f);
    
    while (window.isOpen()) {
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

        player.movementPlayer();

        camera.updateLerp(player.position);

        window.clear(sf::Color{82, 176, 255, 0});

        camera.setView(window);

        for (const auto& chunk : worldChunks) {
            Terrain::drawChunk(window, chunk);
        }

        player.drawPlayer(window);

        window.display();
    }

    return 0;
}