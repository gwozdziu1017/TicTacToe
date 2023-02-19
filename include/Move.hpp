#pragma once
#include <string>

class Move
{
public:
    Move(const std::string _sign, const int _value) : sign(_sign), value(_value) {}
    std::string getSign() { return sign; }
    int getValue() { return value; }

private:
    std::string sign;
    int value;

}