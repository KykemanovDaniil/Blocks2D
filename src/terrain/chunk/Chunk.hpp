#pragma once 
#include <SFML/Graphics.hpp>
#include <vector>
#include "../blockType/BlockType.hpp"

constexpr unsigned int CHUNK_W = 16;
constexpr unsigned int CHUNK_H = 128;
constexpr unsigned int CHUNK_SIZE = CHUNK_W * CHUNK_H;

struct Chunk {
    int x = 0;
    BlockType blocks[CHUNK_SIZE] = {BlockType::Air};
    sf::VertexArray mesh;

    void init();
    void updateMesh();
    void draw(sf::RenderWindow& window);
};