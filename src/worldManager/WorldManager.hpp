#pragma once
#include <map>
#include "chunk/Chunk.hpp"
#include <print>

class WorldManager {
public:
    void createWorld(int size);

    void loadAtlasTexture(const char* path) {
        if (!blockAtlas.loadFromFile(path)) {
            std::println("Failed load tex: blockAtlas");
    }
    }

    void draw(sf::RenderTarget& target) const {
        for (auto& [index, chunk] : activeChunks) {
            chunk.draw(target, blockAtlas); 
        }
    }
private:
    sf::Texture blockAtlas;
    std::map<int, Chunk> activeChunks;
};