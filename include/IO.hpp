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
    static void print(T input);    // printing default types

    template <typename T> 
    static void printContainer(T input); // printing container

    template <typename T>
    static T get();    // wrapping for std::cin
};