#include <gtest/gtest.h>
#include "ipaddr.h"

TEST(IpAddr, IpAddr)
{
    IpAddr addr1;
    EXPECT_STREQ(addr1.ipAddr().c_str(), "0.0.0.0");
    addr1 = IpAddr("192.168.0.1");
    EXPECT_STREQ(addr1.ipAddr().c_str(), "192.168.0.1");
}

TEST(IpAddr, filter)
{
    IpAddr addr1 = IpAddr("192.168.0.1");
    EXPECT_TRUE(addr1.filter(192));
    EXPECT_FALSE(addr1.filter(191));
    EXPECT_TRUE(addr1.filter(192, 168));
    EXPECT_FALSE(addr1.filter(191, 168));
}

TEST(IpAddr, filter_any)
{
    IpAddr addr1 = IpAddr("192.168.0.1");
    EXPECT_TRUE(addr1.filter_any(0));
    EXPECT_TRUE(addr1.filter_any(1));
    EXPECT_FALSE(addr1.filter_any(2));
}
