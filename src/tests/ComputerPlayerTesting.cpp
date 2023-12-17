#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <memory>

#include "../../include/IPlayer.hpp"
#include "../../include/ComputerPlayer.hpp"
#include "../../include/Menu.hpp"

namespace ComputerPlayerTests
{
    TEST(ComputerPlayerTests, createComputerPlayerThenVerifyAllFields)
    {
        std::shared_ptr<ComputerPlayer> CPlayer = std::make_shared<ComputerPlayer>();

        ASSERT_TRUE(CPlayer->getName() == "Computer");
        ASSERT_TRUE(CPlayer->getSign() == Menu::VALUE_o);
        EXPECT_FALSE(CPlayer->getIsWinner());
        ASSERT_TRUE(CPlayer->getId() == 0);
    }

    TEST(ComputerPlayerTests, createComputerPlayerThenSetIsWinnerTrueExpectGetIsWinnerTrue)
    {
        std::shared_ptr<ComputerPlayer> CPlayer = std::make_shared<ComputerPlayer>();
        CPlayer -> setIsWinner(true);

        EXPECT_TRUE(CPlayer->getIsWinner());
    }

    TEST(ComputerPlayerTests, createComputerPlayerThenSetIdTo1ExpectIdEquals1)
    {
        std::shared_ptr<ComputerPlayer> CPlayer = std::make_shared<ComputerPlayer>();
        CPlayer -> setId(1);

        EXPECT_TRUE(CPlayer->getId() == 1);
    }
}