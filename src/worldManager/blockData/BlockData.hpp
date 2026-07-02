#pragma once
#include "../blockType/BlockType.hpp"
#include <array>
#include <cstddef>

constexpr size_t BLOCK_TYPES_COUNT = 8; 

struct BlockData {
    BlockType m_type;
    bool m_solid;
    unsigned int m_texIndex;
};

extern std::array<BlockData, BLOCK_TYPES_COUNT> BlockRegistry;

void initBlockData();