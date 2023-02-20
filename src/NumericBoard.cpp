#include "../include/NumericBoard.hpp"

NumericBoard::NumericBoard()
{
    board = "";

    board.append(" 1 ");
    board.append(verticalSeparator);
    board.append(" 2 ");
    board.append(verticalSeparator);
    board.append(" 3 ");
    board.append("\n");
    board.append(horizontalSeparator);
    board.append("\n");
    // ---
    board.append(" 4 ");
    board.append(verticalSeparator);
    board.append(" 5 ");
    board.append(verticalSeparator);
    board.append(" 6 ");
    board.append("\n");
    board.append(horizontalSeparator);
    board.append("\n");
    // ---
    board.append(" 7 ");
    board.append(verticalSeparator);
    board.append(" 8 ");
    board.append(verticalSeparator);
    board.append(" 9 ");
    board.append("\n");
}

std::ostream &operator<<(std::ostream &stream, const NumericBoard &board)
{
    IO::print(board);
}