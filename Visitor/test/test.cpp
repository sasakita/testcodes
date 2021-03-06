#include <gtest/gtest.h>
#include "Visitor.hh"
#include "Observer.hh"

int Increment(int val) { return val + 1; }
int Decrement(int val) { return val - 1; }

TEST(HelloGoogleTest, Increment)
{
  EXPECT_EQ(2, Increment(1));
    NumberGenerator n;
    TestObserver t;
    n.addObserver(&t);
    ExecObserver e;
    n.addObserver(&e);
    n.execute();
}

TEST(HelloGoogleTest, Decrement)
{
  EXPECT_EQ(0, Decrement(1));
}
