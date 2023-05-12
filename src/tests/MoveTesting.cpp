#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <memory>

#include "../../include/ExampleClass.hpp"
#include "../../include/Move.hpp"
#include "../../include/IBoard.hpp"
#include "../../include/PlayableBoard.hpp"

namespace MoveTesting
{
    TEST(MoveTests, createMoveGetFieldReturnsField)
    {
        std::shared_ptr<Move> mv = std::make_shared<Move>(1, Menu::VALUE_X);
        EXPECT_EQ(mv->getField(), 1);
    }

    TEST(MoveTests, createMoveGetValueReturnsValue)
    {
        std::shared_ptr<Move> mv = std::make_shared<Move>(1, Menu::VALUE_X);
        EXPECT_EQ(mv->getValue(), Menu::VALUE_X);
    }

    TEST(MoveTests, onEqualMoveFieldsOperatorEqualsReturnsFalse)
    {
        Move m1{1, Menu::VALUE_X};
        Move m2{1, Menu::VALUE_o};

        EXPECT_FALSE(m1 == m2);
    }

   TEST(MoveTests, onEqualMoveValuesOperatorEqualsReturnsFalse)
    {
        Move m1{1, Menu::VALUE_X};
        Move m2{2, Menu::VALUE_X};

        EXPECT_FALSE(m1 == m2);
    }

   TEST(MoveTests, onEqualMoveFieldAndValueOperatorEqualsReturnsTrue)
    {
        Move m1{1, Menu::VALUE_X};
        Move m2{1, Menu::VALUE_X};

        EXPECT_TRUE(m1 == m2);
    }
}