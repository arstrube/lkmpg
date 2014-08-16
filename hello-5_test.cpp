/** hello-5_test.cpp */

/// TODO: Make printk() append to buffer

#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"
#include "CppUTest/PlatformSpecificFunctions.h"
#include "stubs/user_stubs.h"

extern "C" {
    #include <linux/kern_levels.h> /* Needed for KERN_INFO */
    #include "hello-5/hello-5.h"
}

TEST_GROUP(hello)
{
    void setup()
    {
        printk_reset();
    }
};

TEST(hello, hello_2_init_module)
{
    LONGS_EQUAL(0, init_module());
    STRCMP_EQUAL(KERN_INFO, printk_get_loglevel());
    STRCMP_CONTAINS("Hello, world 5\n=============\n", printk_get_message());
	STRCMP_CONTAINS("myshort is a short integer: 1\n", printk_get_message());
	STRCMP_CONTAINS("myint is an integer: 420\n", printk_get_message());
	STRCMP_CONTAINS("mylong is a long integer: 9999\n", printk_get_message());
	STRCMP_CONTAINS("mystring is a string: blah\n", printk_get_message());
	for (int i = 0; i < 2; i++)
	{
	    char expected[30];
	    test_snprintf(expected, 30UL, "myintArray[%d] = -1\n", i);
		STRCMP_CONTAINS(expected, printk_get_message());
	}
	STRCMP_CONTAINS("got 0 arguments for myintArray.\n", printk_get_message());
}

TEST(hello, hello_2_exit_module)
{
    cleanup_module();
    STRCMP_EQUAL(KERN_INFO, printk_get_loglevel());
    STRCMP_EQUAL("Goodbye, world 5\n", printk_get_message());
}

int main(int ac, char** av)
{
	return CommandLineTestRunner::RunAllTests(ac, av);
}
