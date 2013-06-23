#include <gtest/gtest.h>
#include <formatting/formatting.hpp>
#include <string>

TEST(Minimal,Eq)
{
	int x = 2;
	int y = 2;
	int xpy = 2+2;
	bool result = (x+y) == xpy;
	std::string formatted;
	ASSERT_NO_THROW(formatted = formatting::format("{} + {} is {} and that's {}", 2, 2, 2+2, true));
	ASSERT_STREQ(formatted.c_str(), "2 + 2 is 4 and that's true");
}
