#include <gtest/gtest.h>
#include "lib.h"

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions)
{
    EXPECT_TRUE(version() > 0);
}

