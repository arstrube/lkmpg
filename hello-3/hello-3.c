/**
  *  hello-3.c - Illustrating the __init, __initdata and __exit macros.
  */

#include <linux/module.h>      /* Needed by all modules */
#include <linux/kern_levels.h> /* Needed for KERN_INFO */
#include <linux/init.h>	       /* Needed for the macros */
#include "hello-3.h"           /* Make sure this is okay */

static int hello3_data __initdata = 3;

static int __init hello_3_init(void)
{
	printk(KERN_INFO "Hello, world %d\n", hello3_data);
	return 0;
}

static void __exit hello_3_exit(void)
{
	printk(KERN_INFO "Goodbye, world %d\n", hello3_data);
}

module_init(hello_3_init);
module_exit(hello_3_exit);
