/** hello-5_test.cpp */

/// TODO: Make printk() append to buffer

#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"
#include "CppUTest/SimpleString.h"
#include <cstdarg>
#include <cstdio>
#include "CppUTest/PlatformSpecificFunctions.h"

#define NBUF 8000L
static char log_buffer[NBUF];
static char log_level[3];

extern "C" {
    #include "hello-5/hello-5.h"
}

TEST_GROUP(hello)
{
    void setup()
    {
        log_buffer[0] = 0;
        log_level[0] = 0;
    }
};

TEST(hello, hello_2_init_module)
{
    LONGS_EQUAL(0, init_module());
    STRCMP_EQUAL(KERN_INFO, log_level);
    STRCMP_CONTAINS("Hello, world 5\n=============\n", log_buffer);
	STRCMP_CONTAINS("myshort is a short integer: 1\n", log_buffer);
	STRCMP_CONTAINS("myint is an integer: 420\n", log_buffer);
	STRCMP_CONTAINS("mylong is a long integer: 9999\n", log_buffer);
	STRCMP_CONTAINS("mystring is a string: \"bla\"\n", log_buffer);
	for (int i = 0; i < 2; i++)
	{
	    char expected[30];
	    snprintf(expected, 30, "myintArray[%d] = -1\n", i);
		STRCMP_CONTAINS(expected, log_buffer);
	}
	STRCMP_CONTAINS("got 0 arguments for myintArray.\n", log_buffer);
}

TEST(hello, hello_2_exit_module)
{
    cleanup_module();
    STRCMP_EQUAL(KERN_INFO, log_level);
    STRCMP_EQUAL("Goodbye, world 5\n", log_buffer);
}

int main(int ac, char** av)
{
	return CommandLineTestRunner::RunAllTests(ac, av);
}
