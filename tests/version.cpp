#include "openxr/openxr.hpp"

#include <gtest/gtest.h>

class OpenXrVersionTest : public ::testing::Test {
protected:
  void SetUp() override {}

  void TearDown() override {}
};

static const uint64_t VERSION_1_2_3{0x0001000200000003};
static const uint64_t VERSION_3_2_1{0x0003000200000001};

TEST_F(OpenXrVersionTest, versionTest) {
  {
    xr::Version v;
    EXPECT_EQ(v.major(), 0x0000);
    EXPECT_EQ(v.minor(), 0x0000);
    EXPECT_EQ(v.patch(), 0x00000000);
  }
  {
    xr::Version v(VERSION_1_2_3);
    EXPECT_EQ(v.major(), 0x0001);
    EXPECT_EQ(v.minor(), 0x0002);
    EXPECT_EQ(v.patch(), 0x00000003);
  }
  {
    xr::Version v(VERSION_3_2_1);
    EXPECT_EQ(v.major(), 0x0003);
    EXPECT_EQ(v.minor(), 0x0002);
    EXPECT_EQ(v.patch(), 0x0001);
  }
  {
    xr::Version v;
    v.major(0xFFFF);
    EXPECT_EQ(v.major(), 0xFFFF);
    EXPECT_EQ(v.minor(), 0x0000);
    EXPECT_EQ(v.patch(), 0x00000000);
    v.major(0x0000);
    EXPECT_EQ(v.major(), 0x0000);
    EXPECT_EQ(v.minor(), 0x0000);
    EXPECT_EQ(v.patch(), 0x00000000);
  }
  {
    xr::Version v;
    v.minor(0xFFFF);
    EXPECT_EQ(v.major(), 0x0000);
    EXPECT_EQ(v.minor(), 0xFFFF);
    EXPECT_EQ(v.patch(), 0x0000);
    v.minor(0x0000);
    EXPECT_EQ(v.major(), 0x0000);
    EXPECT_EQ(v.minor(), 0x0000);
    EXPECT_EQ(v.patch(), 0x00000000);
  }
  {
    xr::Version v;
    v.patch(0xFFFFFFFF);
    EXPECT_EQ(v.major(), 0x0000);
    EXPECT_EQ(v.minor(), 0x0000);
    EXPECT_EQ(v.patch(), 0xFFFFFFFF);
    v.patch(0x00000000);
    EXPECT_EQ(v.major(), 0x0000);
    EXPECT_EQ(v.minor(), 0x0000);
    EXPECT_EQ(v.patch(), 0x00000000);
  }
}
