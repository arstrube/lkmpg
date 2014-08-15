/** KernelModuleTests.cpp */

#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"
#include "CppUTest/SimpleString.h"
#include <cstdarg>
#include "CppUTest/PlatformSpecificFunctions.h"

#define NBUF 2048L
static char log_buffer[NBUF];
static char log_level[3];

extern "C" {

    #include "hello-1/hello-1.h"
    #define __init
    #define __exit
    #include "hello-2/hello-2.h"

    /** Kernel function stubs */

    int printk (const char * fmt, ...)
    {
        va_list args;
        SimpleString::StrNCpy(log_level, fmt, 2);
        fmt += 2;
        va_start(args, fmt);
        return PlatformSpecificVSNprintf(log_buffer, NBUF, fmt, args);
    }

}

TEST_GROUP(hello)
{
    void setup()
    {
        log_buffer[0] = 0;
        log_level[0] = 0;
    }
};

TEST(hello, hello_1_init_module)
{
    LONGS_EQUAL(0, init_module());
    STRCMP_EQUAL(KERN_INFO, log_level);
    STRCMP_EQUAL("Hello world 1.\n", log_buffer);
}

TEST(hello, hello_1_cleanup_module)
{
    cleanup_module();
    STRCMP_EQUAL(KERN_INFO, log_level);
    STRCMP_EQUAL("Goodbye world 1.\n", log_buffer);
}

TEST(hello, hello_2_init)
{
    LONGS_EQUAL(0, hello_2_init());
    STRCMP_EQUAL(KERN_INFO, log_level);
    STRCMP_EQUAL("Hello world 1.\n", log_buffer);
}

TEST(hello, hello_2_exit)
{
    hello_2_exit();
    STRCMP_EQUAL(KERN_INFO, log_level);
    STRCMP_EQUAL("Goodbye world 1.\n", log_buffer);
}

int main(int ac, char** av)
{
	return CommandLineTestRunner::RunAllTests(ac, av);
}
