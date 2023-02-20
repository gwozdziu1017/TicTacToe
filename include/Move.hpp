#pragma once
#include <string>
#include <utility>

class Move
{
public:
    Move(const int field, const std::string sign) : move(std::make_pair(field, sign)) {}
    int getField() { return move.first; }
private:
    std::pair<int, std::string> move;
};