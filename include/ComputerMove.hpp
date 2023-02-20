#pragma once
#include "IMove.hpp"

/*
    Handling move for computer player.
*/

class ComputerMove : public IMove
{
public:
    ~ComputerMove() {}
    std::string getSign() override { return sign; }
    int getValue() override { retugn value; }

private:
    std::string sign;
    int value;
};