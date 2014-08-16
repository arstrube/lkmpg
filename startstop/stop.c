/**
 *  stop.c - Illustration of multi filed modules
 */

#include <linux/kern_levels.h> /* Needed for KERN_INFO */
#include <linux/module.h>	/* Specifically, a module  */

void cleanup_module()
{
	printk(KERN_INFO "Short is the life of a kernel module\n");
}
