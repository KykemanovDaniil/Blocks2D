#include "BlockData.hpp"

std::array<BlockData, BLOCK_TYPES_COUNT> BlockRegistry;

void initBlockData() {
    BlockRegistry[static_cast<size_t>(BlockType::Air)] = {BlockType::Air, false, 0};

    BlockRegistry[static_cast<size_t>(BlockType::Grass)] = {BlockType::Grass, true, 0};

    BlockRegistry[static_cast<size_t>(BlockType::Loam)] = {BlockType::Loam, true, 1};

    BlockRegistry[static_cast<size_t>(BlockType::Grus)] = {BlockType::Grus, true, 2};

    BlockRegistry[static_cast<size_t>(BlockType::Water_bearing_gravel)] = {BlockType::Water_bearing_gravel, true, 3};

    BlockRegistry[static_cast<size_t>(BlockType::Limestone)] = {BlockType::Limestone, true, 4};

    BlockRegistry[static_cast<size_t>(BlockType::Basaltite)] = {BlockType::Basaltite, true, 6};

    BlockRegistry[static_cast<size_t>(BlockType::Basalt)] = {BlockType::Basalt, true, 7};
}
