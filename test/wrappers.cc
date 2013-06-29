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
	const size_t deadbeef = 0xDEADBEEF;
	const int* ptr = (int*)deadbeef;
	ASSERT_NO_THROW(result = formatting::format("hey {} howdy", formatting::raw(ptr)));
	ASSERT_STREQ(result.c_str(),"hey 0xDEADBEEF howdy");
}

TEST(Wrappers,Width)
{
	std::string result;
	ASSERT_NO_THROW(result = formatting::format("hey {} howdy", formatting::width[4](3)));
	ASSERT_STREQ(result.c_str(),"hey    3 howdy");
}

TEST(Wrappers,Precision)
{
	std::string result;
	ASSERT_NO_THROW(result = formatting::format("hey {} howdy", formatting::precision[6](2.718281828)));
	ASSERT_STREQ(result.c_str(),"hey 2.71828 howdy");
}
