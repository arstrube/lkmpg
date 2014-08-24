/**
  *  putuser_wrapper.h
  */

#ifndef PUTUSER_WRAPPER_H
#define PUTUSER_WRAPPER_H

#include <linux/kern_levels.h> /* Needed for KERN_INFO */

int get_user_wrapper_1s(void);
int get_user_wrapper_1u(void);
int get_user_wrapper_2s(short source, short *target);
int get_user_wrapper_2u(unsigned short source, unsigned short *target);
int get_user_wrapper_4s(long *target);
int get_user_wrapper_4u(unsigned long *target);
int get_user_wrapper_8s(long long *target);
int get_user_wrapper_8u(unsigned long long *target);

#endif
