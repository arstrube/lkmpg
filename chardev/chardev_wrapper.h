/**
 *  Wrapper for chardev internal methods
 */

#ifndef CHARDEV_WRAPPER_H
#define CHARDEV_WRAPPER_H

extern char *write_buffer;

int device_open_wrapper(void);
int device_read_wrapper(void);
int device_release_wrapper(void);

#endif
