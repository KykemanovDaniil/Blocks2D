#include "WorldManager.hpp"

void WorldManager::createWorld(int size) {
    for (int i = -size; i < size; ++i) {
        Chunk chunk;
        chunk.setX(i);
        chunk.init();
        chunk.updateGeometry();
        
        activeChunks[i] = chunk;
    }
}
