#pragma once
#include "IBoard.hpp"

class PlayableBoard : public IBoard
{
public:
    PlayableBoard() { setMoveVectorAsEmpty(); }
    ~PlayableBoard() {}

    // setters
    bool tryUpdateBoardWithMove(Move move);
    void updateBoardWithMove(Move move);
    void setMoveVectorAsEmpty();

    // getters
    bool isFieldFree(int field);
    void print();
    MoveVector getMoveVector() { return moveVector; }
    bool isWinningCombinationInMoveVector();

    // operators
    friend std::ostream& operator<< (std::ostream& stream, const PlayableBoard& board){
        MoveVector vectorOfMoves = board.moveVector;
        if(vectorOfMoves.size() == 0)
        {
            stream << "EMPTY_BOARD";
            return stream;
        }
        
        for(auto elem : vectorOfMoves)
        {
            stream << elem;
        }
        return stream;
    };
private:
    MoveVector moveVector;
};