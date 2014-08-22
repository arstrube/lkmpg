/**
 *  Wrapper for chardev internal methods
 */

#ifndef CHARDEV_WRAPPER_H
#define CHARDEV_WRAPPER_H

void read_buffer_reset(void);
char *read_buffer_get(void);
int device_open_wrapper(void);
int device_read_wrapper(void);
int device_release_wrapper(void);

#endif
