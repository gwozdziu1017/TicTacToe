#include "../include/PlayableBoard.hpp"
#include "PlayableBoard.hpp"

bool PlayableBoard::tryUpdateBoardWithMove(Move _move)
{
    if(isFieldFree(_move.getField()))
    {
        updateBoardWithMove(_move);
        return true;
    }
    else
    {
        return false;
    }
}
void PlayableBoard::updateBoardWithMove(Move _move)
{
    Move tempMove{_move.getField(), Menu::EMPTY_FIELD};
    std::replace(moveVector.begin(), moveVector.end(), Move{_move.getField(), Menu::EMPTY_FIELD}, _move);
}

bool PlayableBoard::isFieldFree(int field)
{
    Move temp{field, Menu::EMPTY_FIELD};
    auto result = std::find(begin(moveVector),
                            end(moveVector), 
                            temp);
    return result != std::end(moveVector);
}

void PlayableBoard::print()
{
    IO::print(*this);
}

void PlayableBoard::setMoveVectorAsEmpty()
{
    for(auto iter = 1; iter<10; iter++)
    {
        Move mv{iter, Menu::EMPTY_FIELD};
        this->moveVector.push_back(mv);
    }
}