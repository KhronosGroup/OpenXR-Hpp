#include "openxr/openxr.hpp"

#include <gtest/gtest.h>

class OpenXrMathTest : public ::testing::Test {
protected:
  void SetUp() override {}

  void TearDown() override {}
};

TEST_F(OpenXrMathTest, quatTest) {
    EXPECT_EQ(xr::Quaternionf().x, 0.f);
    EXPECT_EQ(xr::Quaternionf().y, 0.f);
    EXPECT_EQ(xr::Quaternionf().z, 0.f);
    EXPECT_EQ(xr::Quaternionf().w, 1.f);
}

TEST_F(OpenXrMathTest, vecTest) {
    EXPECT_EQ(xr::Vector3f().x, 0.f);
    EXPECT_EQ(xr::Vector3f().y, 0.f);
    EXPECT_EQ(xr::Vector3f().z, 0.f);
}
