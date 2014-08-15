/**
  *  hello-4.h
  */

#ifndef HELLO_4_H
#define HELLO_4_H

#include <linux/kern_levels.h> /* Needed for KERN_INFO */

/** This is what these init and exit functions will look like
  * after application of the macros
  */
int init_module(void);
void cleanup_module(void);

#endif
