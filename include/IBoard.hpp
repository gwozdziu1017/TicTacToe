#pragma once
#include <vector>
#include <string>
#include <memory>
#include "Move.hpp"
#include "IO.hpp"

typedef std::vector<Move> MoveVector;
typedef std::shared_ptr<MoveVector> MoveVectorPtr;

const std::string emptyField; // "   "
const std::string horizontalSeparator; // "---|---|---"
const std::string verticalSeparator; // "|"

class IBoard
{
public:
    virtual ~IBoard() {};
};