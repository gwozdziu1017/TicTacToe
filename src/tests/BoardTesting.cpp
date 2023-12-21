#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <memory>

#include "../../include/ExampleClass.hpp"
#include "../../include/Move.hpp"
#include "../../include/IBoard.hpp"
#include "../../include/PlayableBoard.hpp"

namespace BoardTesting
{
    TEST(PlayableBoardTests, createPlayableBoardGetMoveVectorReturnsEmptyMoveVector)
    {
        std::shared_ptr<PlayableBoard> board = std::make_shared<PlayableBoard>();
        MoveVector moveVector = board->getMoveVector();
        int iter = 1;
        for(auto elem : moveVector)
        {
            Move mv{iter, Menu::EMPTY_FIELD};
            ASSERT_TRUE(elem == Move(iter, Menu::EMPTY_FIELD));
            iter++;
        }
    }

    TEST(PlayableBoardTests, createBoardUpdateBoardWithMove)
    {
        std::shared_ptr<PlayableBoard> board = std::make_shared<PlayableBoard>();
        Move mv{1, Menu::VALUE_X};

        board->updateBoardWithMove(mv);
        auto moveVector = board->getMoveVector();

        ASSERT_TRUE(moveVector[0] == mv);
    }

    TEST(PlayableBoardTests, putMoveIntoBoardOnIsFieldFreeExpectFalse)
    {
        std::shared_ptr<PlayableBoard> board = std::make_shared<PlayableBoard>();
        Move mv{1, "X"};
        board->updateBoardWithMove(mv);

        EXPECT_FALSE(board->isFieldFree(1));
    }

    TEST(PlayableBoardTests, createBoardOnIsFieldFreeExpectTrue)
    {
        std::shared_ptr<PlayableBoard> board = std::make_shared<PlayableBoard>();
        EXPECT_TRUE(board->isFieldFree(1));
    }

    TEST(PlayableBoardTests, onUpdateFreeFieldExpectTryUpdateFieldReturnsTrue)
    {
        std::shared_ptr<PlayableBoard> board = std::make_shared<PlayableBoard>();
        Move m1{5, Menu::VALUE_o};

        EXPECT_TRUE(board->tryUpdateBoardWithMove(m1));
    }

    TEST(PlayableBoardTests, onUpdateNotFreeFieldExpectTryUpdateFieldReturnsFalse)
    {
        std::shared_ptr<PlayableBoard> board = std::make_shared<PlayableBoard>();
        Move m1{5, Menu::VALUE_o};
        Move m2{5, Menu::VALUE_X};

        board->updateBoardWithMove(m1);
        EXPECT_FALSE(board->tryUpdateBoardWithMove(m2));
    }

    TEST(PlayableBoardTests, createBoardPutThreeMovesPrintBoard)
    {
        std::shared_ptr<PlayableBoard> board = std::make_shared<PlayableBoard>();
        Move m1{1, "X"};
        Move m2{5, "X"};
        Move m3{8, "X"};

        board->updateBoardWithMove(m1);
        board->updateBoardWithMove(m2);
        board->updateBoardWithMove(m3);

        board->print();
    }

    TEST(PlaybleBoardTests, createBoardPutWinningMovesExpectIsWinningComboReturnsTrue)
    {
        std::shared_ptr<PlayableBoard> board = std::make_shared<PlayableBoard>();
        Move m1{1, "X"};
        Move m2{2, "X"};
        Move m3{3, "X"};

        board->updateBoardWithMove(m1);
        board->updateBoardWithMove(m2);
        board->updateBoardWithMove(m3);

        EXPECT_TRUE(board->isWinningCombinationInMoveVector(m1.getValue()));
    }

    TEST(PlaybleBoardTests, createAllWinningCombinationExpectIsWinningComboReturnsTrue)
    {
        std::vector<std::vector<int>> winningCombinations = 
        {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9},
            {1, 4, 7},
            {2, 5, 8},
            {3, 6, 9},
            {7, 5, 3},
            {5, 1, 9}
        };
        std::shared_ptr<PlayableBoard> board = std::make_shared<PlayableBoard>();

        for(auto vector : winningCombinations)
        {
            Move m1{vector[0], Menu::VALUE_o};
            Move m2{vector[1], Menu::VALUE_o};
            Move m3{vector[2], Menu::VALUE_o};

            board->updateBoardWithMove(m1);
            board->updateBoardWithMove(m2);
            board->updateBoardWithMove(m3);

            EXPECT_TRUE(board->isWinningCombinationInMoveVector(m1.getValue()));
        }
    }

    TEST(PlaybleBoardTests, createNotWinningCombinationExpectIsWiningCombinationReturnsFalse)
    {
        std::shared_ptr<PlayableBoard> board = std::make_shared<PlayableBoard>();
        Move m1{1, "X"};
        Move m2{2, "X"};
        Move m3{5, "X"};

        board->updateBoardWithMove(m1);
        board->updateBoardWithMove(m2);
        board->updateBoardWithMove(m3);

        EXPECT_FALSE(board->isWinningCombinationInMoveVector(m1.getValue()));
    }

    TEST(PlaybleBoardTests, createCombinationOfTwoElementsExpectIsWiningCombinationReturnsFalse)
    {
        std::shared_ptr<PlayableBoard> board = std::make_shared<PlayableBoard>();
        Move m1{1, "X"};
        Move m2{2, "X"};

        board->updateBoardWithMove(m1);
        board->updateBoardWithMove(m2);

        EXPECT_FALSE(board->isWinningCombinationInMoveVector(m1.getValue()));
    }

    TEST(PlaybleBoardTests, createWinningCombinationWithAdditionalMovesExpectIsWiningCombinationReturnsTrue)
    {
        std::shared_ptr<PlayableBoard> board = std::make_shared<PlayableBoard>();
        Move m1{1, "X"};
        Move m2{2, "X"};
        Move m3{5, "X"};
        Move m4{3, "X"};

        board->updateBoardWithMove(m1);
        board->updateBoardWithMove(m2);
        board->updateBoardWithMove(m3);
        board->updateBoardWithMove(m4);

        EXPECT_TRUE(board->isWinningCombinationInMoveVector(m1.getValue()));
    }
}
