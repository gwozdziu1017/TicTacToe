/*
    Player class that is responsible for player related actions.
*/
#pragma once
#include <string>
#include "Menu.hpp"

class IPlayer
{
public:
    virtual ~IPlayer() {}
protected:
    virtual std::string getName() = 0;
    virtual std::string getSign() = 0;
    virtual bool getIsWinner() = 0;
};