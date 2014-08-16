/** startstop_test.cpp */

#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"
#include "stubs/user_stubs.h"

extern "C" {
    #include "startstop/startstop.h"
}

TEST_GROUP(hello)
{
    void setup()
    {
        printk_reset();
    }
};

TEST(hello, hello_1_init_module)
{
    LONGS_EQUAL(0, init_module());
    STRCMP_EQUAL(KERN_INFO, printk_get_loglevel());
    STRCMP_EQUAL("Hello, world - this is the kernel speaking\n", printk_get_message());
}

TEST(hello, hello_1_cleanup_module)
{
    cleanup_module();
    STRCMP_EQUAL(KERN_INFO, printk_get_loglevel());
    STRCMP_EQUAL("Short is the life of a kernel module\n", printk_get_message());
}

int main(int ac, char** av)
{
	return CommandLineTestRunner::RunAllTests(ac, av);
}

