/*
    Class responsible for handling computer player used in game simulation.
*/
#pragma once
#include "IPlayer.hpp"


class ComputerPlayer : public IPlayer
{
public:
    ComputerPlayer() : name("Computer"),
                       sign(Menu::VALUE_o), // computer always plays with o
                       isWinner(false),
                       id(0)
                       { };
    ~ComputerPlayer() {}

    // geters
    std::string getName() override { return name; }
    std::string getSign() override { return sign; };
    bool getIsWinner() override { return isWinner; };
    short getId() override { return id; }

    // setters
    void setIsWinner(const bool isWinner) { this->isWinner = isWinner; }
    void setId(const short _id) { this -> id = _id; }
private:
    std::string name;
    std::string sign;
    bool isWinner;
    short id;
};