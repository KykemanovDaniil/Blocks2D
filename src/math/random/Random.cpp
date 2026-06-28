#include "math/random/Random.hpp"
#include <random>

int Random::inRange(const int min, const int max) {
    static thread_local std::random_device seed;
    static thread_local std::mt19937 gen(seed());
    std::uniform_int_distribution<int> dist(min, max);

    return dist(gen);
}