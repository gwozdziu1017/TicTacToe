#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <memory>

#include "../../include/ExampleClass.hpp"
#include "../../include/Move.hpp"
#include "../../include/IBoard.hpp"
#include "../../include/PlayableBoard.hpp"

/*namespaxzce exampleTest
{
    TEST(exampleTest, passing)
    {
        EXPECT_EQ(true, true);
    }
}

namespace mocked
{
    struct ExampleClassMock : public testing::Test
    {
        testing::StrictMock<ExampleClass> mock;
        ExampleClass sut = ExampleClass(mock);
    };

    TEST_F(ExampleClassMock, shouldReturn77)
    {
        ExampleClass& ex = sut;
        EXPECT_EQ(ex.foo(), 77);
    }
}*/

namespace mockedMoveClass
{
    TEST(MoveMock, onCreationReturnsX)
    {
        std::shared_ptr<Move> mv = std::make_shared<Move>(1, "X");
        EXPECT_EQ(mv->getField(), 1);
    }

}

namespace mockedPlayableBoard
{
    TEST(playableBoardMock, onIsFieldFreeReturnsFalse)
    {
        std::shared_ptr<PlayableBoard> board = std::make_shared<PlayableBoard>();
        Move mv{1, "X"};
        board->updateBoardWithMove(mv);
        ASSERT_FALSE(board->isFieldFree(1));
    }

    TEST(playableBoardMock, onIsFieldFreeReturnsTrue)
    {
        std::shared_ptr<PlayableBoard> board = std::make_shared<PlayableBoard>();
        Move mv{1, "X"};
        board->updateBoardWithMove(mv);
        ASSERT_TRUE(board->isFieldFree(2));
    }

    TEST(playableBoardMock, onSortMoveVectorReturnsTrue)
    {
        std::shared_ptr<PlayableBoard> board = std::make_shared<PlayableBoard>();
        Move m1{5, "X"};
        Move m2{1, "O"};
        Move m3{3, "X"};

        board->updateBoardWithMove(m1);
        board->updateBoardWithMove(m2);
        board->updateBoardWithMove(m3);

        board->sortMoveVector();

        MoveVector stubbedVector{m2, m3, m1};
        MoveVector realMoveVector{board->getMoveVector()};

        for(auto iter = 0; iter < 3; iter++)
        {
            ASSERT_EQ(stubbedVector[iter].getField(), realMoveVector[iter].getField());
        }
    }
}
