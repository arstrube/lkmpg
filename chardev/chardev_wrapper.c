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

int device_open_wrapper(void)
{
    struct inode node;
    struct file file;
    return device_open(&node, &file);
}
/*
 * Called when a process closes the device file.
 */

#if 0
PRIVATE int device_release(struct inode *inode, struct file *file)
{
	Device_Open--;		/* We're now ready for our next caller */

	/*
	 * Decrement the usage count, or else once you opened the file, you'll
	 * never get get rid of the module.
	 */
	module_put(THIS_MODULE);

	return 0;
}

/**
 *  Called when a process, which already opened the dev file, attempts to
 *  read from it.
 */
PRIVATE ssize_t device_read(struct file *filp,	/* see include/linux/fs.h   */
			   char *buffer,	/* buffer to fill with data */
			   size_t length,	/* length of the buffer     */
			   loff_t * offset)
{
	/*
	 * Number of bytes actually written to the buffer
	 */
	int bytes_read = 0;

	/*
	 * If we're at the end of the message,
	 * return 0 signifying end of file
	 */
	if (*msg_Ptr == 0)
		return 0;

	/*
	 * Actually put the data into the buffer
	 */
	while (length && *msg_Ptr) {

		/*
		 * The buffer is in the user data segment, not the kernel
		 * segment so "*" assignment won't work.  We have to use
		 * put_user which copies data from the kernel data segment to
		 * the user data segment.
		 */
		put_user(*(msg_Ptr++), buffer++);

		length--;
		bytes_read++;
	}

	/*
	 * Most read functions return the number of bytes put into the buffer
	 */
	return bytes_read;
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
