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
static char   read_buffer[200];

void read_buffer_reset(void)
{
    read_buffer[0] = 0;
}

char * read_buffer_get(void)
{
    return read_buffer;
}

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
    return device_read(&file, read_buffer, 200, 0);
}

int device_write_wrapper(void)
{
    return device_write(&file, NULL, 200, 0);
}
