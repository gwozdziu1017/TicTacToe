#pragma once
#include <string>

class IMove
{
public:
    virtual ~IMove() {};
protected:
    virtual std::string getSign() = 0;
    virtual int getValue() = 0;

};