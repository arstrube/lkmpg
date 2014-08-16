/**
  *  chardev.h
  */

#ifndef CHARDEV_H
#define CHARDEV_H

#include <linux/kern_levels.h> /* Needed for KERN_INFO */

int init_module(void);
void cleanup_module(void);
static int device_open(struct inode *, struct file *);
static int device_release(struct inode *, struct file *);
static ssize_t device_read(struct file *, char *, size_t, loff_t *);
static ssize_t device_write(struct file *, const char *, size_t, loff_t *);

#endif
