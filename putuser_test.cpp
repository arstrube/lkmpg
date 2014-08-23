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
    CHECK(0 == put_user_wrapper_1u(expected, &actual));
    LONGS_EQUAL(expected, actual);
}

TEST(putuser, put_char)
{
    char expected = -15, actual = 0;
    CHECK(0 == put_user_wrapper_1s(expected, &actual));
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
    CHECK(0 == put_user_wrapper_2s(expected, &actual));
    LONGS_EQUAL(expected, actual);
}

TEST(putuser, put_unsigned_long)
{
    unsigned int expected = 200000, actual = 0;
    CHECK(0 == put_user_wrapper_4u(expected, &actual));
    LONGS_EQUAL(expected, actual);
}

TEST(putuser, put_long)
{
    int expected = -70000, actual = 0;
    CHECK(0 == put_user_wrapper_4s(expected, &actual));
    LONGS_EQUAL(expected, actual);
}

int main(int ac, char** av)
{
	return CommandLineTestRunner::RunAllTests(ac, av);
}
