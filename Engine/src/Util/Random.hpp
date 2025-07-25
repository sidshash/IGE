#pragma once
#include <random>

namespace Random {
    inline int GenerateRandomID() {
        static std::mt19937 rng(std::random_device{}());
        static std::uniform_int_distribution<int> dist(100000, 999999);
        return dist(rng);
    }
};
