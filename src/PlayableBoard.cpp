#include "../include/PlayableBoard.hpp"
#include "PlayableBoard.hpp"

void PlayableBoard::updateBoardWithMove(const Move move)
{
    moveVector.push_back(move);
}

bool PlayableBoard::isFieldFree(const int field)
{
    for(auto move : moveVector)
    {
        if(move.getField() == field)
            return false;   // there is field in moveVector so it's not free
    }
    return true;
}

void PlayableBoard::sortMoveVector()
{
    std::sort(moveVector.begin(),
              moveVector.end(),
              [](auto& lhs, auto& rhs){ return lhs.getField() < rhs.getField(); });
}

std::ostream &operator<<(std::ostream &stream, const PlayableBoard &board)
{
    
}
