#include "../include/PlayableBoard.hpp"
#include "PlayableBoard.hpp"

void PlayableBoard::updateBoardWithMove(Move _move)
{
    Move tempMove{_move.getField(), emptyField};
    std::replace(moveVector.begin(), moveVector.end(), Move{_move.getField(), emptyField}, _move);
    //moveVector.at(_move.getField()) = _move;
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
    std::cerr << *this;
}

void PlayableBoard::setMoveVectorAsEmpty()
{
    for(auto iter = 1; iter<10; iter++)
    {
        Move mv{iter, emptyField};
        this->moveVector.push_back(mv);
    }
}