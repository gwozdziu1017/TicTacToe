/*
    Class for board used to help players understand its fields.
    NumericBoard looks like this:

     1 | 2 | 3 
    ---|---|---
     4 | 5 | 6 
    ---|---|---
     7 | 8 | 9  
*/

#pragma once
#include "IBoard.hpp"

class NumericBoard : public IBoard
{
public:
    NumericBoard() { setBoardAsDefault(); };
    ~NumericBoard() {};

    void setBoardAsDefault();

private:
    friend std::ostream& operator<< (std::ostream& stream, const NumericBoard& board);
    std::string board;
};