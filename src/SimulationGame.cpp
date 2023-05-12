#include "../include/SimulationGame.hpp"

SimulationGame::SimulationGame(PlayerPtr player1, PlayerPtr player2)
{
    playerPtrVector.push_back(player1);
    playerPtrVector.push_back(player2);
}

/*
    1. Draw random from [1, 9] as a field
    2. Update Board
    3. Check if win
    4. Print Board
*/
void SimulationGame::run()
{
    auto turn = 1;
    while(turn < 3)
    {
        for(auto player : playerPtrVector)
        {
            onTurnEnd(player);
        }
    }
}

void SimulationGame::updateBoard(const Move move)
{


}