/**
  *  chardev.h
  */

#ifndef CHARDEV_H
#define CHARDEV_H

#include <linux/kern_levels.h> /* Needed for KERN_INFO */

#define PRIVATE static

int init_module(void);
void cleanup_module(void);

#if UNIT_TEST
 #undef PRIVATE
 #define PRIVATE
 int device_open(struct inode *, struct file *);
 int device_release(struct inode *, struct file *);
 ssize_t device_read(struct file *, char *, size_t, loff_t *);
 ssize_t device_write(struct file *, const char *, size_t, loff_t *);
#endif

#endif
