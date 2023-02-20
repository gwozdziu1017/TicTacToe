#include "../include/PlayableBoard.hpp"

void PlayableBoard::updateBoardWithMove(const Move move)
{
    moveVectorPtr->push_back(move);
}

bool PlayableBoard::isFieldFree(const int field)
{
    for(auto iter = moveVectorPtr->begin();
             iter != moveVectorPtr->end();
             iter++)
    {
        if(iter->getField() == field) // there is move with this field as a key
            return false;
    }
    return true;
}

std::ostream &operator<<(std::ostream &stream, const PlayableBoard &board)
{
    
}
