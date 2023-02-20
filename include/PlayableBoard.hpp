#pragma once
#include "IBoard.hpp"

class PlayableBoard : public IBoard
{
public:
    PlayableBoard() : boardPtr(std::make_shared<BoardContent>()) {}
    ~PlayableBoard() {}
private:
    void updateBoardWithMove(const Move move);
    bool isFieldFree(const int _field);

    friend std::ostream& operator<< (std::ostream& stream, const PlayableBoard& board);

    BoardPtr boardPtr;
};