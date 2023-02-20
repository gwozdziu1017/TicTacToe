/*
    Handling real multiplayer game.
*/

#pragma once
#include "IGame.hpp"


class MultiplayerGame : public IGame
{
public:
    MultiplayerGame(PlayerPtr player1, PlayerPtr player2);
    ~MultiplayerGame() {}

private:
    void run() override;
    void onTurnEnd(PlayerPtr player) override;
    void updateBoard(Move move);

    MoveMap moveMap;
    BoardPtr boardPtr;
    PlayerPtrVector playerPtrVector; // TODO: reserve only space for two players in vector
};