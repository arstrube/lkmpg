/**
 *  putuser_test.cpp - Test the put_user() stubs
 */

#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"
#include "stubs/user_stubs.h"

extern "C" {
    #include <linux/kern_levels.h> /* Needed for KERN_INFO */
    #include "putuser/putuser_wrapper.h"
    #include "stubs/kernel_stubs.h"
}

#define EBUSY -16

TEST_GROUP(putuser)
{
};

TEST(putuser, put_unsigned_char)
{
    unsigned char expected = 0xFE, actual = 0x00;
    put_user_wrapper_1u(expected, &actual);
    LONGS_EQUAL(expected, actual);
}

TEST(putuser, put_char)
{
    char expected = -15, actual = 0;
    put_user_wrapper_1s(expected, &actual);
    LONGS_EQUAL(expected, actual);
}

TEST(putuser, put_unsigned_short)
{
    unsigned short expected = 64000, actual = 0;
    CHECK(0 == put_user_wrapper_2u(expected, &actual));
    LONGS_EQUAL(expected, actual);
}

TEST(putuser, put_short)
{
    short expected = -4578, actual = 0;
    put_user_wrapper_2s(expected, &actual);
    LONGS_EQUAL(expected, actual);
}

unsigned long expected_unsigned_long; /* workaround */

TEST(putuser, put_unsigned_long)
{
    /* workaround because passing unsigned long
     * as argument is not possible
     */
    expected_unsigned_long = 200000;
    unsigned long actual = 0;
    put_user_wrapper_4u(&actual);
    LONGS_EQUAL(expected_unsigned_long, actual);
}

long expected_long; /* workaround */

TEST(putuser, put_long)
{
    /* workaround because passing long as
     * argument is not possible
     */
    expected_long = -70000;
    long actual = 0;
    put_user_wrapper_4s(&actual);
    LONGS_EQUAL(expected_long, actual);
}

long long expected_long_long; /* workaround */

TEST(putuser, put_long_long)
{
    /* workaround because passing long as
     * argument is not possible
     */
    expected_long_long = -7000000000000000000;
    long long actual = 0;
    put_user_wrapper_8s(&actual);
    LONGS_EQUAL(expected_long_long, actual);
}

long long expected_unsigned_long_long; /* workaround */

TEST(putuser, put_unsigned_long_long)
{
    /* workaround because passing long as
     * argument is not possible
     */
    expected_unsigned_long_long = 2000000000000000000;
    unsigned long long actual = 0;
    put_user_wrapper_8u(&actual);
    LONGS_EQUAL(expected_unsigned_long_long, actual);
}

int main(int ac, char** av)
{
	return CommandLineTestRunner::RunAllTests(ac, av);
}
