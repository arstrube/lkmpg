/**
  * hello-1.h
  */

#ifndef HELLO_1_H
#define HELLO_1_H

#include <linux/kern_levels.h> /* Needed for KERN_INFO */

int init_module(void);
void cleanup_module(void);

#endif
