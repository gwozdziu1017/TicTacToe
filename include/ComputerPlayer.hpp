/*
    Class responsible for handling computer player used in game simulation.
*/
#pragma once
#include "IPlayer.hpp";

class ComputerPlayer : public IPlayer
{
public:
    ComputerPlayer(std::string _name, std::string _sign) : name(_name), sign(_sign), winner(false) {}
    ~ComputerPlayer() {}
    std::string getName() override { return name; }
    std::string getSign() override { return sign; };
    bool isWinner() override { return winner; };
private:
    std::string name;
    std::string sign;
    bool winner;
};