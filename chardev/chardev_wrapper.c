/**
 *  chardev.c: Creates a read-only char device that says how many times
 *  you've read from the dev file
 */
#include <linux/module.h>      /* Needed by all modules */
#include <linux/kern_levels.h> /* Needed for KERN_INFO */
#include <linux/init.h>	       /* Needed for the macros */
#include <linux/fs.h>
#include "chardev.h"           /* Make sure this is okay */
#include "chardev_wrapper.h"   /* for testing */

static struct inode node;
static struct file file;
static char   buffer[200];

char * write_buffer = buffer;

int device_open_wrapper(void)
{
    return device_open(&node, &file);
}

int device_release_wrapper(void)
{
    return device_release(&node, &file);
}

int device_read_wrapper(void)
{
    return device_read(&file, buffer, 200, 0);
}

#if 0
}

/**
 *  Called when a process writes to dev file: echo "hi" > /dev/hello
 */
PRIVATE ssize_t
device_write(struct file *filp, const char *buff, size_t len, loff_t * off)
{
	printk(KERN_ALERT "Sorry, this operation isn't supported.\n");
	return -EINVAL;
}

#endif
