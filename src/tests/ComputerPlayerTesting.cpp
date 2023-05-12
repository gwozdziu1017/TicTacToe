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
        std::shared_ptr<ComputerPlayer> CPlayer = std::make_shared<ComputerPlayer>(
            "Damian",
            Menu::VALUE_o
        );

        ASSERT_TRUE(CPlayer->getName() == "Damian");
        ASSERT_TRUE(CPlayer->getSign() == Menu::VALUE_o);
        EXPECT_FALSE(CPlayer->getIsWinner());
    }

    TEST(ComputerPlayerTests, createComputerPlayerThenSetIsWinnerTrueExpectGetIsWinnerTrue)
    {
        std::shared_ptr<ComputerPlayer> CPlayer = std::make_shared<ComputerPlayer>(
            "Damian",
            Menu::VALUE_o
        );
        CPlayer -> setIsWinner(true);

        EXPECT_TRUE(CPlayer->getIsWinner());
    }
}