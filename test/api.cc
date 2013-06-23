#include <gtest/gtest.h>
#include <formatting/formatting.hpp>
#include <string>

TEST(API,OneParameter)
{
	std::string result;
	ASSERT_NO_THROW(result = formatting::format("{}", 1));
	ASSERT_STREQ(result.c_str(),"1");
}
TEST(API,TwoParameters)
{
	std::string result;
	ASSERT_NO_THROW(result = formatting::format("{} {}", 1, '2'));
	ASSERT_STREQ(result.c_str(),"1 2");
}
TEST(API,ThreeParameters)
{
	std::string result;
	ASSERT_NO_THROW(result = formatting::format("{} {} {}", 1, '2', "3"));
	ASSERT_STREQ(result.c_str(),"1 2 3");
}
TEST(API,FourParameters)
{
	std::string result;
	ASSERT_NO_THROW(result = formatting::format("{} {} {} {}", 1, '2', "3", 4));
	ASSERT_STREQ(result.c_str(),"1 2 3 4");
}
TEST(API,FiveParameters)
{
	std::string result;
	ASSERT_NO_THROW(result = formatting::format("{} {} {} {} {}", 1, '2', "3", 4, '5'));
	ASSERT_STREQ(result.c_str(),"1 2 3 4 5");
}
TEST(API,SixParameters)
{
	std::string result;
	ASSERT_NO_THROW(result = formatting::format("{} {} {} {} {} {}", 1, '2', "3", 4, '5', "6"));
	ASSERT_STREQ(result.c_str(),"1 2 3 4 5 6");
}
TEST(API,SevenParameters)
{
	std::string result;
	ASSERT_NO_THROW(result = formatting::format("{} {} {} {} {} {} {}", 1, '2', "3", 4, '5', "6", 7));
	ASSERT_STREQ(result.c_str(),"1 2 3 4 5 6 7");
}
TEST(API,EightParameters)
{
	std::string result;
	ASSERT_NO_THROW(result = formatting::format("{} {} {} {} {} {} {} {}", 1, '2', "3", 4, '5', "6", 7, '8'));
	ASSERT_STREQ(result.c_str(),"1 2 3 4 5 6 7 8");
}
TEST(API,NineParameters)
{
	std::string result;
	ASSERT_NO_THROW(result = formatting::format("{} {} {} {} {} {} {} {} {}", 1, '2', "3", 4, '5', "6", 7, '8', 9));
	ASSERT_STREQ(result.c_str(),"1 2 3 4 5 6 7 8 9");
}
TEST(API,TenParameters)
{
	std::string result;
	ASSERT_NO_THROW(result = formatting::format("{} {} {} {} {} {} {} {} {} {}", 1, '2', "3", 4, '5', "6", 7, '8', 9, "10"));
	ASSERT_STREQ(result.c_str(),"1 2 3 4 5 6 7 8 9 10");
}
TEST(API,WrongNumberOfPlaceholders)
{
	ASSERT_THROW(formatting::format("{}", 1, 2), formatting::formatting_error);
}
