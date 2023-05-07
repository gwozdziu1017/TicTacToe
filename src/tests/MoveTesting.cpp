#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <memory>

#include "../../include/ExampleClass.hpp"
#include "../../include/Move.hpp"
#include "../../include/IBoard.hpp"
#include "../../include/PlayableBoard.hpp"

namespace MoveTesting
{
    TEST(MoveTesting, createMoveGetFieldReturnsField)
    {
        std::shared_ptr<Move> mv = std::make_shared<Move>(1, "X");
        EXPECT_EQ(mv->getField(), 1);
    }

    TEST(MoveTesting, createMoveGetValueReturnsValue)
    {
        std::shared_ptr<Move> mv = std::make_shared<Move>(1, "X");
        EXPECT_EQ(mv->getValue(), "X");
    }

    TEST(MoveMock, onEqualMoveFieldsOperatorEqualsReturnsFalse)
    {
        Move m1{1, Menu::VALUE_X};
        Move m2{1, Menu::VALUE_o};

        EXPECT_FALSE(m1 == m2);
    }

   TEST(MoveMock, onEqualMoveValuesOperatorEqualsReturnsFalse)
    {
        Move m1{1, Menu::VALUE_X};
        Move m2{2, Menu::VALUE_X};

        EXPECT_FALSE(m1 == m2);
    }

   TEST(MoveMock, onEqualMoveFieldAndValueOperatorEqualsReturnsTrue)
    {
        Move m1{1, Menu::VALUE_X};
        Move m2{1, Menu::VALUE_X};

        EXPECT_TRUE(m1 == m2);
    }
}