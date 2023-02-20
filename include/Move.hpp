#pragma once
#include "IMove.hpp"

class Move : public IMove
{
public:
    Move(const std::string _sign, const int _value) : sign(_sign), value(_value) {}
    ~Move() {}
    std::string getSign() override { return sign; }
    int getValue() override { return value; }

private:
    std::string sign;
    int value;
};