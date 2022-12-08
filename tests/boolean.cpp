#include "openxr/openxr_bool.hpp"
#include <type_traits>

#include <gtest/gtest.h>

class OpenXrBoolTest : public ::testing::Test {
protected:
  void SetUp() override {}

  void TearDown() override {}
};
static inline bool f1(XrBool32 param) { return param; }
TEST_F(OpenXrBoolTest, boolTest) {
  {
    EXPECT_TRUE(f1(true));
    EXPECT_TRUE(!f1(false));

    EXPECT_TRUE(xr::Bool32(true) == true);
    EXPECT_TRUE(xr::Bool32(true) == XR_TRUE);
    EXPECT_TRUE(xr::Bool32(true) != false);
    EXPECT_TRUE(xr::Bool32(true) != XR_FALSE);
    EXPECT_TRUE(xr::Bool32(false) == false);
    EXPECT_TRUE(xr::Bool32(false) == XR_FALSE);
    EXPECT_TRUE(xr::Bool32(false) != true);
    EXPECT_TRUE(xr::Bool32(false) != XR_TRUE);

    // Same as above but with argument order flipped
    EXPECT_TRUE(true == xr::Bool32(true));
    EXPECT_TRUE(XR_TRUE == xr::Bool32(true));
    EXPECT_TRUE(false != xr::Bool32(true));
    EXPECT_TRUE(XR_FALSE != xr::Bool32(true));
    EXPECT_TRUE(false == xr::Bool32(false));
    EXPECT_TRUE(XR_FALSE == xr::Bool32(false));
    EXPECT_TRUE(true != xr::Bool32(false));
    EXPECT_TRUE(XR_TRUE != xr::Bool32(false));

    EXPECT_FALSE(!xr::Bool32(true) == true);
    EXPECT_FALSE(!xr::Bool32(true) == XR_TRUE);
    EXPECT_FALSE(!xr::Bool32(true) != false);
    EXPECT_FALSE(!xr::Bool32(true) != XR_FALSE);
    EXPECT_FALSE(!xr::Bool32(false) == false);
    EXPECT_FALSE(!xr::Bool32(false) == XR_FALSE);
    EXPECT_FALSE(!xr::Bool32(false) != true);
    EXPECT_FALSE(!xr::Bool32(false) != XR_TRUE);

    EXPECT_TRUE(xr::Bool32::fromRaw(XR_TRUE) == true);
    EXPECT_TRUE(xr::Bool32::fromRaw(XR_TRUE) == XR_TRUE);
    EXPECT_TRUE(xr::Bool32::fromRaw(XR_FALSE) == false);
    EXPECT_TRUE(xr::Bool32::fromRaw(XR_FALSE) == XR_FALSE);
  }
}
