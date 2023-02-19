/*
    Player class that is responsible for player related actions.
*/

#include <string>

class IPlayer
{
protected:
    virtual std::string getName() = 0;
    virtual std::string getSign() = 0;
    virtual bool isWinner() = 0;
};