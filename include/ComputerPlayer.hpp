/*
    Class responsible for handling computer player used in game simulation.
*/
#pragma once
#include "IPlayer.hpp"

class ComputerPlayer : public IPlayer
{
public:
    ComputerPlayer() = delete;
    ComputerPlayer(std::string _name, std::string _sign) : name(_name), sign(_sign), isWinner(false) {}
    ~ComputerPlayer() {}

    // geters
    std::string getName() override { return name; }
    std::string getSign() override { return sign; };
    bool getIsWinner() override { return isWinner; };

    // setters
    void setIsWinner(const bool isWinner) { this->isWinner = isWinner; }
private:
    std::string name;
    std::string sign;
    bool isWinner;
};