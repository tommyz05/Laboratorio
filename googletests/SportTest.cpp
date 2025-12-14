//
// Created by tommy on 12/11/25.
//
#include "gtest/gtest.h"
#include "../Sport.h"

TEST(SportTest, NegativeCaloriesException)
{
    EXPECT_THROW({
        Sport s("",10,0,11,0,-400);
    }, std::invalid_argument);
}
TEST(SportTest, PositiveCalories)
{
    EXPECT_NO_THROW({
        Sport s("",10,0,11,0,400);
    });
}
