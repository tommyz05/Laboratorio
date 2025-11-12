//
// Created by tommy on 12/11/25.
//
#include "gtest/gtest.h"
#include "../Register.h"

class RegisterTestFixture : public testing::Test
{
protected:
    std::shared_ptr<Activity> a;
    Register reg;
    void SetUp() override
    {
        a = std::make_shared<Activity>("TestActivity", 10, 0, 11, 0);
    }
};

TEST_F(RegisterTestFixture, DayException)
{
    EXPECT_THROW({
        reg.add("x", a);
    }, std::invalid_argument);
}
TEST_F(RegisterTestFixture, MondayActivity)
{
    EXPECT_NO_THROW({
        reg.add("Monday", a);
    });
}
TEST_F(RegisterTestFixture, TuesdayActivity)
{
    EXPECT_NO_THROW({
        reg.add("Tuesday", a);
    });
}
TEST_F(RegisterTestFixture, WednesdayActivity)
{
    EXPECT_NO_THROW({
        reg.add("Wednesday", a);
    });
}
TEST_F(RegisterTestFixture, ThursdayActivity)
{
    EXPECT_NO_THROW({
        reg.add("Thursday", a);
    });
}
TEST_F(RegisterTestFixture, FridayActivity)
{
    EXPECT_NO_THROW({
        reg.add("Friday", a);
    });
}
TEST_F(RegisterTestFixture, SaturdayActivity)
{
    EXPECT_NO_THROW({
        reg.add("Saturday", a);
    });
}
TEST_F(RegisterTestFixture, SundayActivity)
{
    EXPECT_NO_THROW({
        reg.add("Sunday", a);
    });
}
