/*
    Simple wrapper for drawing random number needed for computer player to make a move.
*/
#pragma once

class Random
{
public:
    Random() : begin(1), end(9) {}
    Random(const int _begin, const int _end) : begin(_begin), end(_end) {}
    int getFromRange(const int begin, const int end);

private:
    int begin;
    int end;
};