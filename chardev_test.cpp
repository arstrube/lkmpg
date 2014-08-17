/** hello-5_test.cpp */

/// TODO: Make printk() append to buffer

#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"
#include "CppUTest/PlatformSpecificFunctions.h"
#include "stubs/user_stubs.h"

extern "C" {
    #include <linux/kern_levels.h> /* Needed for KERN_INFO */
    #include "chardev/chardev.h"
}

TEST_GROUP(chardev)
{
    void setup()
    {
        printk_reset();
    }
};

TEST(chardev, chardev_init_module_success)
{
    LONGS_EQUAL(0, init_module());
    STRCMP_EQUAL(KERN_INFO, printk_get_loglevel());
	STRCMP_CONTAINS("I was assigned major number 0. To talk to\n", printk_get_message());
	STRCMP_CONTAINS("the driver, create a dev file with\n", printk_get_message());
	STRCMP_CONTAINS("'mknod /dev/chardev c 0 0'.\n", printk_get_message());
	STRCMP_CONTAINS("Try various minor numbers. Try to cat and echo to\n", printk_get_message());
	STRCMP_CONTAINS("the device file.\n", printk_get_message());
	STRCMP_CONTAINS("Remove the device file and module when done.\n", printk_get_message());

}

short *__check_myshort(void);

TEST(chardev, chardev_init_module_failure)
{
    LONGS_EQUAL(0, init_module());
    STRCMP_EQUAL(KERN_INFO, printk_get_loglevel());
	STRCMP_CONTAINS("myshort is a short integer: 555\n", printk_get_message());
}

TEST(chardev, hchardev_exit_module)
{
    cleanup_module();
    STRCMP_EQUAL(KERN_INFO, printk_get_loglevel());
    STRCMP_EQUAL("Goodbye, world 5\n", printk_get_message());
}

int main(int ac, char** av)
{
	return CommandLineTestRunner::RunAllTests(ac, av);
}
