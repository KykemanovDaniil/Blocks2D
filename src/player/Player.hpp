#pragma once
#include <SFML/Graphics.hpp>
#include "world/World.hpp"

struct Player {
    sf::Vector2f position = {0.0f, 0.0f};
    float speed = 5.0f;
    
    float playerH = 55.0f;
    float playerW = 25.0f;

    void spawnOnSurface(int distance, std::vector<Terrain::Chunk>& worldChunks);

    void setPosition(const sf::Vector2f& position);

    void movementPlayer();
    void drawPlayer(sf::RenderWindow& window);
};
