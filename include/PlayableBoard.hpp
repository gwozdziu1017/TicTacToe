#pragma once
#include "IBoard.hpp"
#include <list>
#include <set>
#include <algorithm>

using std::list;
using std::set;



class PlayableBoard : public IBoard
{
public:
    PlayableBoard()
    {
        setMoveVectorAsEmpty();
        setWinningCombinationList();
    }
    ~PlayableBoard() {}

    // setters
    bool tryUpdateBoardWithMove(Move move);
    void updateBoardWithMove(Move move);
    void setMoveVectorAsEmpty();
    void setWinningCombinationList();

    // getters
    bool isFieldFree(int field);
    void print();
    MoveVector getMoveVector() { return moveVector; }
    bool isWinningCombinationInMoveVector(const string sign);
    set<int> getSetOfTakenFieldsInMoveVectorForGivenSign(const string sign);
    bool isSetInsideWinningCombinationList(const set<int> setOfFields);

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
    std::list<std::set<int>> winningCobinationList;
};