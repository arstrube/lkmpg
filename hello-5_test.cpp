/** hello-5_test.cpp */

/// TODO: Make printk() append to buffer

#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"
#include "stubs/user_stubs.h"

extern "C" {
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
    STRCMP_EQUAL(KERN_INFO, log_level);
    STRCMP_CONTAINS("Hello, world 5\n=============\n", printk_get());
	STRCMP_CONTAINS("myshort is a short integer: 1\n", printk_get());
	STRCMP_CONTAINS("myint is an integer: 420\n", printk_get());
	STRCMP_CONTAINS("mylong is a long integer: 9999\n", printk_get());
	STRCMP_CONTAINS("mystring is a string: \"bla\"\n", printk_get());
	for (int i = 0; i < 2; i++)
	{
	    char expected[30];
	    snprintf(expected, 30, "myintArray[%d] = -1\n", i);
		STRCMP_CONTAINS(expected, printk_get());
	}
	STRCMP_CONTAINS("got 0 arguments for myintArray.\n", printk_get());
}

TEST(hello, hello_2_exit_module)
{
    cleanup_module();
    STRCMP_EQUAL(KERN_INFO, log_level);
    STRCMP_EQUAL("Goodbye, world 5\n", printk_get());
}

int main(int ac, char** av)
{
	return CommandLineTestRunner::RunAllTests(ac, av);
}
