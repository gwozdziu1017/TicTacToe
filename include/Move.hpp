#pragma once
#include <string>
#include <utility>
#include "IO.hpp"

class Move
{
public:
    Move(const int field, const std::string sign) : move(std::make_pair(field, sign)) {}
    int getField() { return move.first; }
    std::string getValue() { return move.second; }

    friend bool operator==(const Move& lhs, const Move& rhs) {
                                                                if (lhs.move.first == rhs.move.first &&
                                                                    lhs.move.second == rhs.move.second)
                                                                    return true;
                                                                else
                                                                    return false;
                                                            }

    friend std::ostream& operator<< (std::ostream& stream, const Move& _move){
                                                                                stream << "Move field: " << _move.move.first
                                                                                        << " Move value: " << _move.move.second
                                                                                        << "\n";
                                                                                return stream;
                                                                             }
private:
    std::pair<int, std::string> move;
};