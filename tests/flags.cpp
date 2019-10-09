#include "openxr/openxr.hpp"
#include <type_traits>

#include <gtest/gtest.h>

class OpenXrFlagsTest : public ::testing::Test {
   protected:
    void SetUp() override {}

    void TearDown() override {}
};

TEST_F(OpenXrFlagsTest, flagsTest) {
    {
        xr::SpaceVelocityFlags flags = xr::SpaceVelocityFlagBits::LinearValid | xr::SpaceVelocityFlagBits::AngularValid;
        EXPECT_EQ(flags & xr::SpaceVelocityFlagBits::LinearValid, xr::SpaceVelocityFlagBits::LinearValid);
        EXPECT_EQ((flags & xr::SpaceVelocityFlagBits::LinearValid).operator bool(), true);
        EXPECT_EQ(flags & xr::SpaceVelocityFlagBits::AngularValid, xr::SpaceVelocityFlagBits::AngularValid);
        EXPECT_EQ((flags & xr::SpaceVelocityFlagBits::AngularValid).operator bool(), true);
		XrSpaceVelocityFlags cflags = flags.operator size_t();
		EXPECT_EQ(cflags, XR_SPACE_VELOCITY_LINEAR_VALID_BIT | XR_SPACE_VELOCITY_ANGULAR_VALID_BIT);
    }

    {
        xr::SpaceVelocityFlags flags = xr::SpaceVelocityFlagBits::LinearValid;
        EXPECT_EQ(flags & xr::SpaceVelocityFlagBits::LinearValid, xr::SpaceVelocityFlagBits::LinearValid);
        EXPECT_EQ((flags & xr::SpaceVelocityFlagBits::LinearValid).operator bool(), true);
        EXPECT_EQ(flags & xr::SpaceVelocityFlagBits::AngularValid, xr::SpaceVelocityFlagBits::None);
        EXPECT_EQ((flags & xr::SpaceVelocityFlagBits::AngularValid).operator bool(), false);
		XrSpaceVelocityFlags cflags = flags.operator size_t();
		EXPECT_EQ(cflags, XR_SPACE_VELOCITY_LINEAR_VALID_BIT);
    }

	{
        xr::SpaceVelocityFlags flags;
        EXPECT_EQ(flags, xr::SpaceVelocityFlagBits::None);
		XrSpaceVelocityFlags cflags = flags.operator size_t();
		EXPECT_EQ(cflags, 0);
    }

	{
		auto flags = xr::SpaceVelocityFlagBits::LinearValid | xr::SpaceVelocityFlagBits::AngularValid;
		EXPECT_TRUE((std::is_same<decltype(flags), xr::SpaceVelocityFlags>::value));
	}

	{
		auto flags = xr::SpaceVelocityFlagBits::LinearValid | xr::SpaceVelocityFlagBits::AngularValid;
		EXPECT_TRUE((std::is_same<decltype(flags), xr::SpaceVelocityFlags>::value));
	}
}
