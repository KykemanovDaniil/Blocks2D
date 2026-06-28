#include "Chunk.hpp"
#include <SFML/Graphics.hpp>
#include <cmath>

void Chunk::init() {
    FastNoiseLite landscapeNoise;
    landscapeNoise.SetNoiseType(FastNoiseLite::NoiseType_ValueCubic);
    landscapeNoise.SetFrequency(0.1f);

    landscapeNoise.SetSeed(0);

    for (unsigned int y = 0; y < CHUNK_H; ++y) {
        for (unsigned int x = 0; x < CHUNK_W; ++x) {
            unsigned int index = x + (y * CHUNK_W);

            int globalBlockX = static_cast<int>(x) + chunk.x * static_cast<int>(CHUNK_W);

            float noiseValue = landscapeNoise.GetNoise(static_cast<float>(globalBlockX), 0.0f);
            unsigned int surfaceY = 60 + static_cast<int>(noiseValue * 15.0f);

            if (y > surfaceY) {
                chunk.blocks[index] = BlockType::Limestone;
            } else {
                chunk.blocks[index] = BlockType::Air;
            }
        }
    }
}

void Chunk::draw(sf::RenderWindow& window) {
    window.draw(chunk.mesh, &blockAtlas);
}

void Chunk::updateMesh(Chunk& chunk) {
    chunk.mesh.setPrimitiveType(sf::PrimitiveType::Triangles);

    int solidBlock = 0;

    unsigned int currentVertex = 0;

    for (unsigned int y = 0; y < CHUNK_H; ++y) {
        for (unsigned int x = 0; x < CHUNK_W; ++x) {
            if (chunk.blocks[x + (y * CHUNK_W)] != BlockType::Air) {
                solidBlock += 1;
            }
        }
    }

    chunk.mesh.resize(solidBlock * 6);

    float textureSize = 18.0f;

    for (unsigned int y = 0; y < CHUNK_H; ++y) {
        for (unsigned int x = 0; x < CHUNK_W; ++x) {
            unsigned int blockIndex = x + (y * CHUNK_W);

            if (chunk.blocks[blockIndex] != BlockType::Air) { 
                float screenX = static_cast<float>(static_cast<int>(x) + chunk.x * static_cast<int>(CHUNK_W)) * BLOCK_SIZE;
                float screenY = static_cast<float>(y) * BLOCK_SIZE;

                if (chunk.blocks[blockIndex] == BlockType::Limestone) {
                    chunk.mesh[currentVertex + 0].position = sf::Vector2f(screenX, screenY);
                    chunk.mesh[currentVertex + 0].texCoords = sf::Vector2f(0.0f, 0.0f);

                    chunk.mesh[currentVertex + 1].position = sf::Vector2f(screenX + BLOCK_SIZE, screenY);
                    chunk.mesh[currentVertex + 1].texCoords = sf::Vector2f(textureSize, 0.0f);

                    chunk.mesh[currentVertex + 2].position = sf::Vector2f(screenX , screenY + BLOCK_SIZE);
                    chunk.mesh[currentVertex + 2].texCoords = sf::Vector2f(0.0f, textureSize);

                    

                    chunk.mesh[currentVertex + 3].position = sf::Vector2f(screenX + BLOCK_SIZE, screenY);
                    chunk.mesh[currentVertex + 3].texCoords = sf::Vector2f(textureSize, 0.0f);

                    chunk.mesh[currentVertex + 4].position = sf::Vector2f(screenX + BLOCK_SIZE, screenY + BLOCK_SIZE);
                    chunk.mesh[currentVertex + 4].texCoords = sf::Vector2f(textureSize, textureSize);

                    chunk.mesh[currentVertex + 5].position = sf::Vector2f(screenX, screenY + BLOCK_SIZE);
                    chunk.mesh[currentVertex + 5].texCoords = sf::Vector2f(0.0f, textureSize);
                    
                    currentVertex += 6;
                }
            }
        }
    }
}