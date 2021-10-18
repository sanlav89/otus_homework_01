#include <gtest/gtest.h>
#include "ipaddr.h"

TEST(IpAddr, IpAddr)
{
    IpAddr addr1;
    EXPECT_STREQ(addr1.to_string().c_str(), "0.0.0.0");
    addr1 = IpAddr("192.168.0.1");
    EXPECT_STREQ(addr1.to_string().c_str(), "192.168.0.1");
}

TEST(IpAddr, filter)
{
    IpAddr addr1 = IpAddr("192.168.0.1");
    EXPECT_TRUE(addr1.byte(0) == 1);
    EXPECT_TRUE(addr1.byte(1) == 0);
    EXPECT_TRUE(addr1.byte(2) == 168);
    EXPECT_TRUE(addr1.byte(3) == 192);
}

TEST(IpAddr, filter_any)
{
    IpAddr addr1 = IpAddr("192.168.0.1");
    IpAddr addr2 = addr1;
    EXPECT_STREQ(addr2.to_string().c_str(), "192.168.0.1");
}
