/*
    Handling simulation game where we mock two computer players.
*/

#pragma once
#include "IGame.hpp"
#include "Random.hpp"

class SimulationGame : public IGame
{
public:
    SimulationGame(PlayerPtr player1, PlayerPtr player2);
    ~SimulationGame() {}

private:
    void run() override;
    void onTurnEnd(PlayerPtr player) override;
    void updateBoard(Move move);

    MoveMap moveMap;
    BoardPtr boardPtr;
    PlayerPtrVector playerPtrVector; // TODO: reserve only space for two players in vector
};