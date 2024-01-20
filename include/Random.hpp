/*
    Simple wrapper for drawing random number needed for computer player to make a move.
*/
#pragma once

#include <random>

class Random
{
public:
    Random() {}
    int getFromRange(const int begin, const int end)
    {
        std::random_device randomDevice;
        std::mt19937 generator(randomDevice());
        std::uniform_int_distribution<int> distr(begin, end);
        return distr(generator);
    }
};