#include "Chunk.hpp"
#include "../blockData/BlockData.hpp"

void Chunk::init() {
    for (unsigned int y = 0; y < CHUNK_H; ++y) {
        for (unsigned int x = 0; x < CHUNK_W; ++x) {
            unsigned int index = x + (y * CHUNK_W);
            if (y < 20) {
                blocks[index] = BlockType::Air;                
            } 
            else if (y == 20) {
                blocks[index] = BlockType::Grass;  
            } 
            else if (y > 20 && y <= 23) {
                blocks[index] = BlockType::Loam;
            } 
            else if (y > 23 && y <= 28) {
                blocks[index] = BlockType::Grus;
            } 
            else if (y > 28 && y <= 32) {
                blocks[index] = BlockType::Water_bearing_gravel; 
            } 
            else if (y > 32 && y <= 119) {
                blocks[index] = BlockType::Limestone;     
            } 
            else if (y > 119 && y <= 125) {
                blocks[index] = BlockType::Basaltite;   
            } 
            else {
                blocks[index] = BlockType::Basalt;         
            }
        }
    }
}

void Chunk::updateGeometry() {

    m_mesh.setPrimitiveType(sf::PrimitiveType::Triangles);

    unsigned int solidBlocks = 0;

    for (unsigned int y = 0; y < CHUNK_H; ++y) {
        for (unsigned int x = 0; x < CHUNK_W; ++x) {
        
            unsigned int index = x + (y * CHUNK_W);

            if (blocks[index] != BlockType::Air) {
                solidBlocks += 1;
            }
        }
    }

    m_mesh.resize(solidBlocks * 6);
    
    unsigned int vertexCount = 0;

    for (unsigned int y = 0; y < CHUNK_H; ++y) {
        for (unsigned int x = 0; x < CHUNK_W; ++x) {
            unsigned int index = x + (y * CHUNK_W);
            if (blocks[index] == BlockType::Air) {
                continue;
            }

            const BlockData& data = BlockRegistry[static_cast<size_t>(blocks[index])];

            float posX0 = static_cast<float>(static_cast<int>(x) + m_x * static_cast<int>(CHUNK_W)) * BLOCK_SIZE;
            float posX1 = posX0 + BLOCK_SIZE;
            float posY0 = static_cast<float>(y) * BLOCK_SIZE;
            float posY1 = posY0 + BLOCK_SIZE;

            unsigned int atlasIndex = data.m_texIndex; 

            int TEX_SIZE = 18;

            float texX0 = static_cast<float>(atlasIndex * TEX_SIZE);
            float texX1 = texX0 + TEX_SIZE;
            float texY0 = 0.0f;
            float texY1 = TEX_SIZE;

            m_mesh[vertexCount + 0].position = sf::Vector2f(posX0, posY0);
            m_mesh[vertexCount + 0].texCoords = sf::Vector2f(texX0, texY0);
            m_mesh[vertexCount + 0].color = sf::Color::White;

            m_mesh[vertexCount + 1].position = sf::Vector2f(posX0, posY1);
            m_mesh[vertexCount + 1].texCoords = sf::Vector2f(texX0, texY1);
            m_mesh[vertexCount + 1].color = sf::Color::White;

            m_mesh[vertexCount + 2].position = sf::Vector2f(posX1, posY0);
            m_mesh[vertexCount + 2].texCoords = sf::Vector2f(texX1, texY0);
            m_mesh[vertexCount + 2].color = sf::Color::White;



            m_mesh[vertexCount + 3].position = sf::Vector2f(posX0, posY1);
            m_mesh[vertexCount + 3].texCoords = sf::Vector2f(texX0, texY1);
            m_mesh[vertexCount + 3].color = sf::Color::White;

            m_mesh[vertexCount + 4].position = sf::Vector2f(posX1, posY1);
            m_mesh[vertexCount + 4].texCoords = sf::Vector2f(texX1, texY1);
            m_mesh[vertexCount + 4].color = sf::Color::White;

            m_mesh[vertexCount + 5].position = sf::Vector2f(posX1, posY0);
            m_mesh[vertexCount + 5].texCoords = sf::Vector2f(texX1, texY0);
            m_mesh[vertexCount + 5].color = sf::Color::White;

            vertexCount += 6;
        }
    }
}