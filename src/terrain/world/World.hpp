#pragma once 
#include <SFML/Graphics.hpp>
#include <cstdint>
#include <vector>

namespace Terrain {
    constexpr unsigned int BLOCK_SIZE = 32;



    inline sf::Texture blockAtlas;

    struct World {
        std::vector<Chunk> chunks;
    };

    float getSurfaceY(const std::vector<Chunk>& chunks, float pX);


}