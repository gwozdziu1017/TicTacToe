#include "../include/PlayableBoard.hpp"

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

void PlayableBoard::setWinningCombinationList()
{
    this->winningCobinationList =
    {
        {1, 2, 3},
        {1, 5, 9},
        {1, 4, 7},
        {2, 5, 8},
        {3, 5, 7},
        {3, 6, 9},
        {4, 5, 6},
        {7, 8, 9}
    };
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

set<int> PlayableBoard::getSetOfTakenFieldsInMoveVectorForGivenSign(const string sign)
{
    std::set<int> setOfTakenFieldsInMoveVector {};
    for(auto& move : moveVector)
    {
        if(move.getValue() == sign)
            setOfTakenFieldsInMoveVector.insert(move.getField());
    }

    return setOfTakenFieldsInMoveVector;
}

bool PlayableBoard::isSetInsideWinningCombinationList(const set<int> setOfFields)
{
    for(auto winningSet : winningCobinationList)
    {
        if(std::includes(setOfFields.begin(),
                         setOfFields.end(),
                         winningSet.begin(),
                         winningSet.end()))
            return true;
    }
    return false;
}

/*
    1. Board has knowledge about all moves in moveVector: all moves for every player in one container
    2. It's given what sign was added to moveVector lately.
    3. Extract move values (fields) from moveVector for given sign (it's not the best solution tho)
    4. Pack it into set to have it sorted.
    5. Check for each winning combo is it in the set above - it will mean that winning combo is in
        moveVector for given sign
    6. Return true if found, else return false. 
*/
bool PlayableBoard::isWinningCombinationInMoveVector(const string sign)
{
    set<int> setOfTakenFieldsInMoveVector = getSetOfTakenFieldsInMoveVectorForGivenSign(sign);
    if(setOfTakenFieldsInMoveVector.size() > 2)
        return isSetInsideWinningCombinationList(setOfTakenFieldsInMoveVector);
    else
        return false;
}