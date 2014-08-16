/**
 *  start.c - Illustration of multi filed modules
 */

#include <linux/kern_levels.h> /* Needed for KERN_INFO */
#include <linux/module.h>	/* Specifically, a module */
#include "startstop.h"           /* Make sure this is okay */

int init_module(void)
{
	printk(KERN_INFO "Hello, world - this is the kernel speaking\n");
	return 0;
}
