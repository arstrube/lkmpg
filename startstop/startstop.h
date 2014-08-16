/**
  *  startstop.h
  */

#ifndef STARTSTOP_H
#define STARTSTOP_H

#include <linux/kern_levels.h> /* Needed for KERN_INFO */

int init_module(void);
void cleanup_module(void);

#endif
