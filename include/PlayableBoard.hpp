#pragma once
#include "IBoard.hpp"

class PlayableBoard : public IBoard
{
public:
    PlayableBoard() : moveVectorPtr(std::make_shared<MoveVector>()) {}
    ~PlayableBoard() {}

    void updateBoardWithMove(const Move move);
    bool isFieldFree(const int field);

    friend std::ostream& operator<< (std::ostream& stream, const PlayableBoard& board);
private:
    MoveVectorPtr moveVectorPtr;
};