#include <gtest/gtest.h>
#include <formatting/formatting.hpp>
#include <string>

TEST(Types,Char)
{
	std::string result;
	ASSERT_NO_THROW(result = formatting::format("hey {} howdy", static_cast<char>('c')));
	ASSERT_STREQ(result.c_str(),"hey c howdy");
}
TEST(Types,SignedChar)
{
	std::string result;
	ASSERT_NO_THROW(result = formatting::format("hey {} howdy", static_cast<signed char>('-')));
	ASSERT_STREQ(result.c_str(),"hey - howdy");
}
TEST(Types,UnsignedChar)
{
	std::string result;
	ASSERT_NO_THROW(result = formatting::format("hey {} howdy", static_cast<unsigned char>('+')));
	ASSERT_STREQ(result.c_str(),"hey + howdy");
}
TEST(Types,Short)
{
	std::string result;
	ASSERT_NO_THROW(result = formatting::format("hey {} howdy", static_cast<short>(-8)));
	ASSERT_STREQ(result.c_str(),"hey -8 howdy");
}
TEST(Types,UnsignedShort)
{
	std::string result;
	ASSERT_NO_THROW(result = formatting::format("hey {} howdy", static_cast<unsigned short>(8)));
	ASSERT_STREQ(result.c_str(),"hey 8 howdy");
}
TEST(Types,Int)
{
	std::string result;
	ASSERT_NO_THROW(result = formatting::format("hey {} howdy", static_cast<int>(-10)));
	ASSERT_STREQ(result.c_str(),"hey -10 howdy");
}
TEST(Types,UnsignedInt)
{
	std::string result;
	ASSERT_NO_THROW(result = formatting::format("hey {} howdy", static_cast<unsigned int>(10)));
	ASSERT_STREQ(result.c_str(),"hey 10 howdy");
}
TEST(Types,Long)
{
	std::string result;
	ASSERT_NO_THROW(result = formatting::format("hey {} howdy", static_cast<long>(600000)));
	ASSERT_STREQ(result.c_str(),"hey 600000 howdy");
}
TEST(Types,UnsignedLong)
{
	std::string result;
	ASSERT_NO_THROW(result = formatting::format("hey {} howdy", static_cast<unsigned long>(4294967290)));
	ASSERT_STREQ(result.c_str(),"hey 4294967290 howdy");
}
TEST(Types,Float)
{
	std::string result;
	ASSERT_NO_THROW(result = formatting::format("hey {} howdy", static_cast<float>(2.123456)));
	ASSERT_STREQ(result.c_str(),"hey 2.123456 howdy");
}
TEST(Types,Double)
{
	std::string result;
	ASSERT_NO_THROW(result = formatting::format("hey {} howdy", static_cast<double>(3.14159265)));
	ASSERT_STREQ(result.c_str(),"hey 3.14159265 howdy");
}
TEST(Types,String)
{
	std::string result;
	ASSERT_NO_THROW(result = formatting::format("hey {} howdy", static_cast<std::string>("mister")));
	ASSERT_STREQ(result.c_str(),"hey mister howdy");
}
TEST(Types,Bool)
{
	std::string result;
	ASSERT_NO_THROW(result = formatting::format("hey {} howdy", static_cast<bool>(true)));
	ASSERT_STREQ(result.c_str(),"hey true howdy");
}
TEST(Types,Pointer)
{
	std::string result;
	int int_var = 3;
	ASSERT_NO_THROW(result = formatting::format("hey {} howdy", static_cast<int*>(&int_var)));
	ASSERT_STREQ(result.c_str(),"hey 3 howdy");
}
