#pragma once
#include <cstdint>

enum class BlockType : uint8_t {
    Air = 0, 
    Grass, 
    Loam, 
    Water_bearing_gravel,
    Limestone,
    Basaltite,
    Basalt
};