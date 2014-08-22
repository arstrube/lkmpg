/**
 * chardev_test.cpp - Test the LKMPG chardev program
 */

#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"
#include "stubs/user_stubs.h"

extern "C" {
    #include <linux/kern_levels.h> /* Needed for KERN_INFO */
    #include "chardev/chardev.h"
    #include "chardev/chardev_wrapper.h"
    #include "stubs/kernel_stubs.h"
}

#define EBUSY -16

TEST_GROUP(chardev)
{
    int result;
    void setup()
    {
        read_buffer_reset();
        printk_reset();
    }
};

TEST(chardev, chardev_init_module_success)
{
    register_chrdev_result_set(50);
    LONGS_EQUAL(0, init_module());
    STRCMP_EQUAL(KERN_INFO, printk_get_loglevel());
	STRCMP_CONTAINS("I was assigned major number 50. To talk to\n", printk_get_message());
	STRCMP_CONTAINS("the driver, create a dev file with\n", printk_get_message());
	STRCMP_CONTAINS("'mknod /dev/chardev c 50 0'.\n", printk_get_message());
	STRCMP_CONTAINS("Try various minor numbers. Try to cat and echo to\n", printk_get_message());
	STRCMP_CONTAINS("the device file.\n", printk_get_message());
	STRCMP_CONTAINS("Remove the device file and module when done.\n", printk_get_message());

}

short *__check_myshort(void);

TEST(chardev, chardev_init_module_failure)
{
    register_chrdev_result_set(-1);
    LONGS_EQUAL(-1, init_module());
}

TEST(chardev, chardev_device_open_success)
{
    device_release_wrapper();
    LONGS_EQUAL(0, device_open_wrapper());
    device_read_wrapper(); /// put mesg into buffer
    STRCMP_EQUAL("I already told you 1 times Hello world!\n", read_buffer_get());
}

TEST(chardev, chardev_device_open_failure)
{
    device_release_wrapper();
    LONGS_EQUAL(0, device_open_wrapper());
    LONGS_EQUAL(EBUSY, device_open_wrapper());
}

TEST(chardev, chardev_exit_module)
{
    cleanup_module();
    STRCMP_EQUAL(KERN_INFO, printk_get_loglevel());
    STRCMP_EQUAL("__unregister_chrdev(0, 0, 256, chardev) called\n", printk_get_message());
}

int main(int ac, char** av)
{
	return CommandLineTestRunner::RunAllTests(ac, av);
}
