#include <gtest/gtest.h>

int Increment(int val) { return val + 1; }
int Decrement(int val) { return val - 1; }

TEST(HelloGoogleTest, Increment)
{
  EXPECT_EQ(2, Increment(1));
}

TEST(HelloGoogleTest, Decrement)
{
  EXPECT_EQ(0, Decrement(1));
}
