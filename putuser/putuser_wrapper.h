/**
  *  putuser_wrapper.h
  */

#ifndef PUTUSER_WRAPPER_H
#define PUTUSER_WRAPPER_H

#include <linux/kern_levels.h> /* Needed for KERN_INFO */

#define PRIVATE static

int put_user_wrapper_1s(char source, char *target);
int put_user_wrapper_1u(unsigned char source, unsigned char *target);
int put_user_wrapper_2s(short source, short *target);
int put_user_wrapper_2u(unsigned short source, unsigned short *target);
int put_user_wrapper_4s(int source, int *target);
int put_user_wrapper_4u(unsigned int source, unsigned int *target);

#endif
