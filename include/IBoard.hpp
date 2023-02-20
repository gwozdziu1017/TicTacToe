#pragma once
#include <set>
#include <map>
#include <string>
#include <memory>
#include "Move.hpp"
#include "IO.hpp"

typedef std::map<int, std::string> BoardContent;
typedef std::shared_ptr<BoardContent> BoardPtr;

const std::string emptyField; // "   "
const std::string horizontalSeparator; // "---|---|---"
const std::string verticalSeparator; // "|"

class IBoard
{
public:
    virtual ~IBoard() = 0;
};