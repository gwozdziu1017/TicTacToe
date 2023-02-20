/*
    Class responsible for handling human player.
*/
#pragma once
#include "IPlayer.hpp";

class HumanPlayer : public IPlayer
{
public:
    HumanPlayer(std::string _name, std::string _sign) : name(_name), sign(_sign), winner(false) {}
    ~HumanPlayer() {}
    std::string getName() override;
    std::string getSign() override;
    bool isWinner() override;
private:
    std::string name;
    std::string sign;
    bool winner;
};