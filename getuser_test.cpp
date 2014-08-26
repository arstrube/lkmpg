/**
 *  getuser_test.cpp - Test the get_user() stubs
 */

#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"
#include "stubs/user_stubs.h"

extern "C" {
    #include <linux/kern_levels.h> /* Needed for KERN_INFO */
    #include "getuser/getuser_wrapper.h"
    #include "stubs/kernel_stubs.h"
}

#define EBUSY -16

TEST_GROUP(getuser)
{
};

unsigned char actual_unsigned_char;
unsigned char expected_unsigned_char;
TEST(getuser, get_unsigned_char)
{
    expected_unsigned_char = 0xFE;
    actual_unsigned_char = 0x00;
    get_user_wrapper_1u();
    LONGS_EQUAL(expected_unsigned_char, actual_unsigned_char);
}

char actual_char;
char expected_char;
TEST(getuser, get_char)
{
    expected_char = -15;
    actual_char = 0;
    get_user_wrapper_1s();
    LONGS_EQUAL(expected_char, actual_char);
}

unsigned short actual_unsigned_short;
unsigned short expected_unsigned_short;
TEST(getuser, get_unsigned_short)
{
    expected_unsigned_short = 64000;
    actual_unsigned_short = 0;
    get_user_wrapper_2u();
    LONGS_EQUAL(expected_unsigned_short, actual_unsigned_short);
}

short actual_short;
short expected_short;
TEST(getuser, get_short)
{
    expected_short = -4578;
    actual_short = 0;
    get_user_wrapper_2s();
    LONGS_EQUAL(expected_short, actual_short);
}

unsigned long actual_unsigned_long;
unsigned long expected_unsigned_long;
TEST(getuser, get_unsigned_long)
{
    expected_unsigned_long = 200000;
    actual_unsigned_long = 0;
    get_user_wrapper_4u();
    LONGS_EQUAL(expected_unsigned_long, actual_unsigned_long);
}

long actual_long;
long expected_long;
TEST(getuser, get_long)
{
    expected_long = -70000;
    actual_long = 0;
    get_user_wrapper_4s();
    LONGS_EQUAL(expected_long, actual_long);
}

long long actual_long_long;
long long expected_long_long;
#if 0
TEST(getuser, get_long_long)
{
    expected_long_long = -7000000000000000000;
    actual_long_long = 0;
    get_user_wrapper_8s();
    LONGS_EQUAL(expected_long_long, actual_long_long);
}
#endif
unsigned long long actual_unsigned_long_long;
unsigned long long expected_unsigned_long_long;
#if 0
TEST(getuser, get_unsigned_long_long)
{
    expected_unsigned_long_long = 2000000000000000000;
    actual_unsigned_long_long = 0;
    get_user_wrapper_8u();
    LONGS_EQUAL(expected_unsigned_long_long, actual_unsigned_long_long);
}
#endif
int main(int ac, char** av)
{
	return CommandLineTestRunner::RunAllTests(ac, av);
}
