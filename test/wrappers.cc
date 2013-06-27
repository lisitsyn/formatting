#include <gtest/gtest.h>
#include <formatting/formatting.hpp>
#include <string>

TEST(Wrappers,Hex)
{
	std::string result;
	ASSERT_NO_THROW(result = formatting::format("hey {} howdy", formatting::hex(0xDEADBEEF)));
	ASSERT_STREQ(result.c_str(),"hey 0xDEADBEEF howdy");
}

TEST(Wrappers,Oct)
{
	std::string result;
	ASSERT_NO_THROW(result = formatting::format("hey {} howdy", formatting::oct(0117)));
	ASSERT_STREQ(result.c_str(),"hey 0117 howdy");
}

TEST(Wrappers,Raw)
{
	std::string result;
	ASSERT_NO_THROW(result = formatting::format("hey {} howdy", formatting::raw(reinterpret_cast<size_t*>(0xDEADBEEF))));
	ASSERT_STREQ(result.c_str(),"hey 0xDEADBEEF howdy");
}
