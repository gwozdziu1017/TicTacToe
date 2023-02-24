#pragma once
#include "IBoard.hpp"

class PlayableBoard : public IBoard
{
public:
    PlayableBoard() : moveVector(MoveVector()) {}
    ~PlayableBoard() {}

    void updateBoardWithMove(const Move move);
    bool isFieldFree(const int field);
    void sortMoveVector();
    MoveVector getMoveVector() { return moveVector; }

    friend std::ostream& operator<< (std::ostream& stream, const PlayableBoard& board);
private:
    MoveVector moveVector;
};