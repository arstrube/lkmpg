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

char actual_char; /* can't pass as arguments */
char expected_char;

TEST(getuser, get_char)
{
    expected_char = -15;
    actual_char = 0;
    get_user_wrapper_1s();
    LONGS_EQUAL(expected_char, actual_char);
}
#if 0
TEST(getuser, put_unsigned_short)
{
    unsigned short expected = 64000, actual = 0;
    CHECK(0 == put_user_wrapper_2u(expected, &actual));
    LONGS_EQUAL(expected, actual);
}

TEST(getuser, put_short)
{
    short expected = -4578, actual = 0;
    put_user_wrapper_2s(expected, &actual);
    LONGS_EQUAL(expected, actual);
}
#endif
unsigned long expected_unsigned_long; /* workaround */
#if 0
TEST(getuser, put_unsigned_long)
{
    /* workaround because passing unsigned long
     * as argument is not possible
     */
    expected_unsigned_long = 200000;
    unsigned long actual = 0;
    put_user_wrapper_4u(&actual);
    LONGS_EQUAL(expected_unsigned_long, actual);
}
#endif
long expected_long; /* workaround */
#if 0
TEST(getuser, put_long)
{
    /* workaround because passing long as
     * argument is not possible
     */
    expected_long = -70000;
    long actual = 0;
    put_user_wrapper_4s(&actual);
    LONGS_EQUAL(expected_long, actual);
}
#endif
long long expected_long_long; /* workaround */
#if 0
TEST(getuser, put_long_long)
{
    /* workaround because passing long as
     * argument is not possible
     */
    expected_long_long = -7000000000000000000;
    long long actual = 0;
    put_user_wrapper_8s(&actual);
    LONGS_EQUAL(expected_long_long, actual);
}
#endif
long long expected_unsigned_long_long; /* workaround */
#if 0
TEST(getuser, put_unsigned_long_long)
{
    /* workaround because passing long as
     * argument is not possible
     */
    expected_unsigned_long_long = 2000000000000000000;
    unsigned long long actual = 0;
    put_user_wrapper_8u(&actual);
    LONGS_EQUAL(expected_unsigned_long_long, actual);
}
#endif
int main(int ac, char** av)
{
	return CommandLineTestRunner::RunAllTests(ac, av);
}
