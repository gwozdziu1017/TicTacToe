#pragma once
#include <map>
#include <set>
#include <vector>
#include <string>
#include <memory>
#include "IPlayer.hpp"
#include "IBoard.hpp"
#include "Move.hpp"

typedef std::map<std::string, std::set<int>> MoveMap;
typedef std::shared_ptr<IBoard> BoardPtr;
typedef std::shared_ptr<IPlayer> PlayerPtr;
typedef std::vector<PlayerPtr> PlayerPtrVector;

class IGame
{
public:
    virtual ~IGame() {}
protected:
    virtual void run() = 0;
    virtual void onTurnEnd(PlayerPtr player) = 0;
    virtual void updateBoard(const Move move) = 0;
    virtual void updateMoveMap(const Move move) = 0;
};