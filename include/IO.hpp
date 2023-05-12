/*
    Static class that wraps handling IO.
    Methods print and get use std::cin and std::cout.
    Moreover method print is overloaded and is able to print different container as well
*/
#pragma once
#include <iostream>

class IO
{
public:
    template <typename T>
    static void print(const T& input);    // printing default types

    template <typename T>
    static T get();    // wrapping for std::cin
};

/* Prints given argument to standard output */
template <typename T>
inline void IO::print(const T& input)
{
    std::cout << input;
}

/* Returns from standard input */
template <typename T>
inline T IO::get()
{
    T temp;
    std::cin >> temp;
    return temp;
}
