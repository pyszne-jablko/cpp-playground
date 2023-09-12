#include <gtest/gtest.h>

TEST(HelloTest, Basic)
{
    EXPECT_STRNE("google", "tests");
    EXPECT_EQ(12 * 12, 144);
}