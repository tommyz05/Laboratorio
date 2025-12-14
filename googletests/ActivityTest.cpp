//
// Created by tommy on 12/11/25.
//
#include "gtest/gtest.h"
#include "../Activity.h"

TEST(ActivityTest, TimeErrorException)
{
    EXPECT_THROW({
        Activity a("",11,0,10,0);
    }, std::invalid_argument);
}
TEST(ActivityTest, CorrectTime)
{
    EXPECT_NO_THROW({
        Activity a("",10,0,11,0);
    });
}
TEST(ActivityTest, NegativeTimeException)
{
    EXPECT_THROW({
    Activity a("",-10,0,11,0);
    }, std::invalid_argument);
}
TEST(ActivityTest, HourOutOfBound)
{
    EXPECT_THROW({
    Activity a("",24,0,24,1);
    }, std::invalid_argument);
}
TEST(ActivityTest, MinutesOutOfBound)
{
    EXPECT_THROW({
    Activity a("",10,64,11,65);
    }, std::invalid_argument);
}
